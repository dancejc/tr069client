/*-------------------------------------------------------------------------*/
/**
   @file    cpe.c
   @author  Tommy Jiang
   @date    August 2011
   @version 1.0
   @brief   tr069 cpe main function.
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>

#include "cwmp_USCOREagent.nsmap"

#include "cpe.h"
#include "cpefunc.h"
#include "datamodel.h"
#include "adapter.h"

#ifdef HTTP_DA
#include "httpda.h" 	/* optionally enable HTTP Digest Authentication */
#endif

#define	MAXARGC		4	/* max number of cli arguments in buf */
#define	WHITE	" \t\n"	/* white space for tokenizing cli arguments */

//const char server[] = "http://10.2.7.27:8080/openacs/acs";
struct cpe_app cpeapp;
struct soap soap;
ping_stat pingstat;
struct http_da_info httpda_info;
tr_client clients[MAXCLIENTS];

struct option tr69copts[] = {
	{"console", 0, NULL, 'c'},
	{"info", 0, NULL, 'i'},
	{"port", 1, NULL, 'p'},
	{"server", 1, NULL, 's'},
	{0, 0, 0, 0}
};

int test()
{
	char *name = "Device.X_CTC_IPTV.ServiceInfo.UserID";
	
	set_parameter(name ,"AAA");
	
	char localip[128];
	bzero(localip, 128);
	get_local_ip(AF_INET, localip, 128);
	fprintf(stderr, "IP addr: %s\n", localip);
	//DDI("test", pingstat.pingstate)
	/*char *s = NULL;
	NODE *p = NULL;
	NODE *root = get_rootnode();
	p = get_node(testname, root);
	if(p)
	{
		if(!(p->get_para))
		{
			printf("Method not suppot.\n");
			return 0;
		}
		p->get_para(&s);
		printf("%s\n", s);
		free(s);
	}
	else printf("Not found.\n");*/
	return 0;
}

int app_init(cpe_app *app)
{
	app->clients = clients;
	int i = 0;
	for(;i < MAXCLIENTS; i++)
	{
		app->clients[i].fd = -1;
		app->clients[i].type = NONE_TYPE;
	}
	
	app->cli_fd = 0;
	app->localport = 0;
	app->debugflag = 0;
	app->cliflag = 0;
	app->client_fd = -1;
	app->running_stat = CPE_IDEL;
	pingstat.datasize = 56;
	app->pingstat = &pingstat;
	app->httpda_info = &httpda_info;
	
#ifdef CPE_DEBUG
	strcpy(app->acsurl, "http://10.2.7.29:9090/");
#else
	strcpy(app->acsurl, "http://182.138.3.190:9090/ACS-server/ACS");
#endif
	
	cpe_get_config(app);
	return 0;
}

cpe_app* get_app()
{
	return &cpeapp;
}

struct soap* get_soap()
{
	return &soap;
}

int cpe_init(int argc, char *argv[])
{
	TR69CLOG(TR69C_INFO, "TR69C application init.");
	
	cpe_app* app = get_app();
	/* TR69C init */
	app_init(app);
	
	/* Process argument */
	int opt = 0;
	while((opt = getopt_long(argc, argv, "icp:s:", tr69copts, NULL)) != -1)
	{
		switch(opt){
			case 'i':
				print_info();
				break;
			case 'p':
				app->localport = atoi(optarg);
				break;
			case 'c':
				app->cliflag = 1;
				TR69CLOG(TR69C_INFO, "Run in console mode.");
				break;
			case 's':
				//app->localport = atoi(optarg);
				strcpy(app->acsurl, optarg);
				//DDS(app->acsurl)
				break;
			case '?':
				//fprintf(stderr, "Unknown argument: %c.\n", optopt);
				print_help();
				return 0;
				break;
		}
	}
	
	/* SOAP init */
	soap.max_keep_alive = 10; // at most 100 calls per keep-alive session

	//soap.mustUnderstand = 1;
	//soap.accept timeout = 600;
	soap_init2(&soap, SOAP_IO_KEEPALIVE, SOAP_IO_KEEPALIVE|SOAP_XML_INDENT);
	//soap_init1(&soap, SOAP_XML_INDENT);//???
	//soap.userid = "itms";
	//soap.passwd = "itms";
	//soap.authrealm = "IgdAuthentication";
	
	soap.send_timeout = 5; // gsoap send timeout
	soap.recv_timeout = 5; // gsoap recv timeout
#ifdef HTTP_DA
	if (soap_register_plugin(&soap, http_da))
    soap_print_fault(&soap, stderr);
#endif
	//TR69CLOG(TR69C_INFO, "KEEP: %d, MODE: %d, IMODE: %d, OMODE: %d", soap.keep_alive, soap.mode, soap.imode, soap.omode);
	return 1;
}

void cpe_exit()
{
	soap_destroy(&soap);
  soap_end(&soap);
  soap_done(&soap);
  
  close_clients();
  close(get_app()->server_sockfd);
  close(get_app()->cliserver_sockfd);
  
	TR69CLOG(TR69C_INFO, "TR69C application exit.");
	exit(0);
}

int even_loop()
{
	  int server_len, client_len;
    int result, i = 0, clisopt = 1;
    //double addresult;
    struct timeval tv;
    fd_set loopfds;
    
    //SOAP_SOCKET server_sockfd, client_sockfd; // master and slave sockets
    SOAP_SOCKET max_sockfd = 10, keepfd;//set max socket fd 10, temp
		cpe_app* app = get_app();
	
    FD_ZERO(&(app->readfds));
    
    /* init cli socket */
#ifdef DOMAIN_SOCKET
    struct sockaddr_un cliserver_address;
    struct sockaddr_un cliclient_address;
		unlink ("server_socket"); 
    app->cliserver_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    cliserver_address.sun_family = AF_UNIX;
    strcpy (cliserver_address.sun_path, "server_socket");
#else
    int s_fd, n_fd;
    struct sockaddr_in cliserver_address;
    struct sockaddr_in cliclient_address;
    app->cliserver_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    cliserver_address.sin_family = AF_INET;
    cliserver_address.sin_addr.s_addr = htonl(INADDR_ANY);
    cliserver_address.sin_port = htons(CLISERVER_PORT);
#endif
    server_len = sizeof(cliserver_address);
    
    /* set cli socket can be reuse, help debug */
    setsockopt(app->cliserver_sockfd, SOL_SOCKET, SO_REUSEADDR, &clisopt, sizeof(clisopt)); 
    
    result = bind(app->cliserver_sockfd, (struct sockaddr *)&cliserver_address, server_len);
    if(result < 0) {
    	perror("bind cli socket error");
    	exit(1);
    }
        
    listen(app->cliserver_sockfd, 5);
    
    FD_SET(app->cliserver_sockfd, &app->readfds);
    
    /* init soap socket */
    if(app->localport)
    	app->server_sockfd = soap_bind(&soap, NULL, app->localport, 100);
    else
    	app->server_sockfd = soap_bind(&soap, NULL, TR69SERVER_PORT, 100);
    	
    if (!soap_valid_socket(app->server_sockfd))
    {
    	soap_print_fault(&soap, stderr);
      exit(-1);
    }
    FD_SET(app->server_sockfd, &app->readfds);
    
    if(app->cliflag)
			FD_SET(app->cli_fd, &app->readfds);

    while(1) {
        //char ch;
        int fd;
        int nread;
        //char buffer[128];
        /*printf("-----------------FD monitor------------------\n");
        DDI("cpe event", app->cli_fd)
        DDI("client fd", app->client_sockfd)
        DDI("server fd", app->server_sockfd)*/
        
        //time vaule must set here
        tv.tv_sec = 0;
				tv.tv_usec = 0;

        loopfds = app->readfds;

        //TODO1: the max fd set 10, it waste the CPU, Change it to max(fd). 
        //TODO2: Change the fd to the list, follow BCM. or array that follow APUE p.444
        result = select(max_sockfd, &loopfds, (fd_set *)0, 
            (fd_set *)0, (struct timeval *) 0/*&tv*/);

        if(result < 0) {
            perror("select error");
            exit(1);
        }

        for(fd = 0; fd < max_sockfd; fd++) {
            if(FD_ISSET(fd,&loopfds)) {

                if(fd == app->server_sockfd) {
                		TR69CLOG(TR69C_INFO, "Server socketfd active.");
                    add_client(soap_accept(&soap), ITMS_CONN, &app->readfds);
                }
                if(fd == app->cliserver_sockfd) {
                		TR69CLOG(TR69C_INFO, "CLI server socketfd active.");
                		client_len = sizeof(cliclient_address);
                		int clfd = accept(app->cliserver_sockfd, (struct sockaddr *)&cliclient_address, &client_len);
                		//TR69CLOG(TR69C_INFO, "Remote CLI %s client connected TR69C.", inet_ntoa(cliclient_address.sin_addr));
                    add_client(clfd, RM1_CONN, &app->readfds);
                }
                else if(fd == app->cli_fd) {
                		//TR69CLOG(TR69C_INFO, "CPE eventfd active.");
                		keepfd = process_clievent(&soap, fd);
										if(keepfd > 0)
										{
											add_client(keepfd, ITMS_CONN, &app->readfds);
											app->running_stat = TRSESSION_RUNNING;
										}
                }
                else {
                	//DDI("else fd", fd)
                	app->client_fd = fd;
                	for(i = 0; i < MAXCLIENTS; i++)
                	{
                		if(app->clients[i].fd < 0)
                			continue;
                			
                		if(app->clients[i].fd == fd && app->clients[i].type == ITMS_CONN )
                		{
                			  TR69CLOG(TR69C_INFO, "SOAP engine begin...");
                			  soap.socket = fd;
                    	  soap_serve(&soap);
                    	  	
                    	  if (soap.error)
												{ 
													//DDI("soap.keep_alive", soap.keep_alive)
													//DDI("soap.error", soap.error)
													if(soap.error < 0)
														TR69CLOG(TR69C_INFO, "ITMS close the connection.");
													else if(soap.error == TR069_EMPTY)
														TR69CLOG(TR69C_INFO, "ITMS send an empty post.");
													else
														soap_print_fault(&soap, stderr);
														
													rm_client(app->clients[i].fd, &app->readfds);
													app->running_stat = CPE_IDEL;
													//app->client_sockfd = 0;
												}
      									soap_end(&soap);
                    	  TR69CLOG(TR69C_INFO, "SOAP engine end...");
                		}
                		else if(app->clients[i].fd == fd && app->clients[i].type == RM_CONN && app->clients[i].type == RM1_CONN )
                		{
                			if(app->running_stat == TRSESSION_RUNNING)continue;
#ifndef DOMAIN_SOCKET
                			s_fd = dup(STDERR_FILENO);
											n_fd = dup2(app->client_fd, STDERR_FILENO);
#endif
                			TR69CLOG(TR69C_INFO, "Processing remote CLI command begin...");
                			ioctl(fd, FIONREAD, &nread);
                			//DDI("IO cli", nread);
                			if(nread == 0)
                			{
                				close(fd);
                				rm_client(app->clients[i].fd, &app->readfds);
                				TR69CLOG(TR69C_INFO, "Remote CLI close the socket...");
                			}
                			else{
												if(app->clients[i].type == RM_CONN)
	                				keepfd = process_clievent(&soap, fd);
	                			else if(app->clients[i].type == RM1_CONN)
													keepfd = process_message(fd, process_cli);/* TODO test */
												if(keepfd > 0)
												{
													add_client(keepfd, ITMS_CONN, &app->readfds);
													app->running_stat = TRSESSION_RUNNING;
												}
											}
												
											TR69CLOG(TR69C_INFO, "Processing remote CLI command end...");
#ifndef DOMAIN_SOCKET
											dup2(s_fd, n_fd);
											fprintf(stderr, "\n");
#endif
                		}
                	}
                	app->client_fd = -1;
                }
                if(app->cliflag)
                	fprintf(stderr, "TR69C>");
            }
        }
    }
}

int process_clievent(struct soap *soap, SOAP_SOCKET fd)
{
	//fprintf(stderr, "do cpe function : %d\n", opt);
	int nread = 0;
  char buffer[128];
  bzero(buffer, 128);
  char tmp;
  //int keepfd = -1;
  //char c, tmp;
	//ioctl(fd, FIONREAD, &nread);
	//setsockopt(fd, SOL_SOCKET, SO_RCVBUF, (const char* )&i, sizeof(int));
	//if(nread > 8){fprintf(stderr, "input too long.\n");return 0;}
  nread = read(fd, buffer, 128);
  if(nread >= 128)
  {
  	fprintf(stderr, "The inputs are too long!\n");
  	for(;tmp != '\n';read(fd, &tmp, 1));
  	return 0;
  }
  if(buffer[nread-1] == '\n')buffer[nread-1] = 0;
  /* some windows telnet terminal will send \r\n, Then case error */
 	if(buffer[nread-2] == '\r')buffer[nread-2] = 0;
  //buffer[nread-1] = 0;
  //if(fd > 2)
  	//buffer[nread-2] = 0;
  
  return buf_args(buffer, process_cli);
}

int main(int argc, char *argv[])
{
	print_info();
	
	if(!cpe_init(argc, argv))
		exit(1);
		
#ifdef CPE_DEBUG
	//test();
#endif
	//send_inform();//initial inform message.
	if(get_app()->cliflag)
		fprintf(stderr, "TR69C>");
	even_loop();
	exit(0);
}

int add_listener(int fd, fd_set *set)
{
	//cpe_app* app = get_app();
	TR69CLOG(TR69C_INFO, "TR69C add a listener, fd = %d", fd);
	//app->client_sockfd = fd;
	FD_SET(fd, set);
	return 0;
}

void print_clients()
{
	fprintf(stderr, "TR69C Clients :\n");
	cpe_app* app = get_app();
	int i = 0;
	for(; i < MAXCLIENTS; i++)
	{
		fprintf(stderr, "Client %d:\n", i);
		fprintf(stderr, "   fd = %d\n", app->clients[i].fd);
		fprintf(stderr, "   type = %d\n", app->clients[i].type);
		//DDI("type", app->clients[i].type)
	}
}

int add_client(int fd, CLIENTTYPE type, fd_set *set)
{
	cpe_app* app = get_app();
	int i = 0;
	for(; i < MAXCLIENTS; i++)
	{
		if(app->clients[i].fd == -1/* && type == ITMS_CONN*/)
		{
			app->clients[i].fd = fd;
			app->clients[i].type = type;
			add_listener(app->clients[i].fd, set);
			return 0;
		}
	}
	return 0;
}

int rm_client(int fd, fd_set *set)
{
	cpe_app* app = get_app();
	int i = 0;
	for(; i < MAXCLIENTS; i++)
	{
		if(app->clients[i].fd == fd)
		{
			rm_listener(fd, set);
			app->clients[i].fd = -1;
			if(app->clients[i].type == ITMS_CONN)
				soap_closesock(&soap);
			app->clients[i].type = NONE_TYPE;
		}
	}
	return 0;
}

int rm_listener(int fd, fd_set *set)
{
	//cpe_app* app = get_app();
	TR69CLOG(TR69C_INFO, "TR69C remove a listener, fd = %d(SOAP FD = %d).", fd, soap.socket);
	//TR69CLOG(TR69C_INFO, "KEEP: %d, MODE: %d, IMODE: %d, OMODE: %d", soap.keep_alive, soap.mode, soap.imode, soap.omode);
	FD_CLR(fd, set);
	return 0;
}

int close_clients()
{
	cpe_app* app = get_app();
	int i = 0;
	for(; i < MAXCLIENTS; i++)
	{
		if(app->clients[i].fd > 0)
		{
			FD_CLR(app->clients[i].fd, &app->readfds);
			close(app->clients[i].fd);
			app->clients[i].fd = -1;
			app->clients[i].type = NONE_TYPE;
		}
	}
	return 0;
}

//make use JZ config or XML databanding
int cpe_get_config(cpe_app *app)
{
	return 0;
}

int cpe_post(struct soap *soap, const char *endpoint, const char *host, int port, const char *path, const char *action, size_t count)
{
	return 0;
}

void print_info()
{
	fprintf(stderr, "----------------------------------------------------------\n");
	fprintf(stderr, "              .-'''''-.         \n");
	fprintf(stderr, "            .'         `.       \n");
	fprintf(stderr, "           :             :   *****  ****     ***   ***  \n");
	fprintf(stderr, "          :               :  * * *   *  *   *     *   * \n");
	fprintf(stderr, "          :      _/|      :    *     *  *  *      *   *  \n");
	fprintf(stderr, "           :   =/_/      :     *     ***   ****    **** \n");
	fprintf(stderr, "            `._/ |     .'      *     * *   *   *      * \n");
	fprintf(stderr, "         (   /  ,|...-'        *     *  *  *   *     *  \n");
	fprintf(stderr, "          \\_/^\\/||__          ***   ***  *  ***   ***  \n");
	fprintf(stderr, "       _/~  `\"\"~`\"` \\_      \n");
	fprintf(stderr, "    __/  -'/  `-._ `\\_\\__     \n");
	fprintf(stderr, "  /     /-'`  `\\   \\  \\-.\\  \n");
	fprintf(stderr, "----------------------------------------------------------\n");
	//TR69CLOG(TR69C_INFO, "TR69C application begin.");
}

void print_help()
{
	fprintf(stderr, "--port(-p) set local listen port.\n");
	fprintf(stderr, "--server(-s) set ACS url(must full url and add port). example: http://127.0.0.1:8080/\n");
	fprintf(stderr, "--console(-c) use console mode.\n");
}

void print_clihelp()
{
	//cpe_app* app = get_app();
	//DDI("stdfd", STDERR_FILENO)
	//DDI("rtfd", app->client_fd)
	/*int s_fd, n_fd;
	if(app->client_fd > 0){
		//close(STDERR_FILENO);
		//dup(app->client_fd);
		s_fd = dup(STDERR_FILENO);
		n_fd = dup2(app->client_fd, STDERR_FILENO);
	}*/
	fprintf(stderr, "TR69C CLI help:\n");
	fprintf(stderr, "--------------------------------------------------\n");
	fprintf(stderr, "inform(i) para1 para2(value change)-- send inform request to ACS.\n");
	fprintf(stderr, "   para1 -- bootstrap(bs) -- send bootstrap inform.\n");
	fprintf(stderr, "         -- boots(b) -- send boot inform.\n");
	fprintf(stderr, "         -- valuechange(vc) -- send value change inform.\n");
	fprintf(stderr, "   	 para2 -- value change inform parameter value.\n");
	fprintf(stderr, "         -- connectionrequest(cr) -- send connection request inform.\n");
	fprintf(stderr, "         -- upgrade(u) -- send upgrade inform.\n");
	fprintf(stderr, "         -- diagnostic(d) -- send diagnostic inform.\n");
	fprintf(stderr, "         -- xshutdown(xsd) -- send x ctc shutdown inform.\n");
	fprintf(stderr, "         -- mtransfercomplete(mtc) -- send m transfer complete inform.\n");
	fprintf(stderr, "         -- xlogperiodic(xlp) -- send x log periodic inform.\n");
	fprintf(stderr, "         -- mreboot(mr) -- send mreboot inform.\n");
	fprintf(stderr, "empty(e) -- send empty request to ACS.\n");
	fprintf(stderr, "clients(c) -- show clients states.\n");
	fprintf(stderr, "tree(t) -- show TR69C parameters tree.\n");
	fprintf(stderr, "   para1 -- chlid node name(full name).\n");
	fprintf(stderr, "set(sp) para1 para2 -- set TR69C parameter value.\n");
	fprintf(stderr, "   para1 -- parameter name.\n");
	fprintf(stderr, "   para2 -- parameter value.\n");
	fprintf(stderr, "get(gp) para1 -- get TR69C parameter value.\n");
	fprintf(stderr, "   para1 -- parameter name.\n");
	fprintf(stderr, "help(h) -- show cli help.\n");
	fprintf(stderr, "quit(q) -- quit.\n");
	fprintf(stderr, "--------------------------------------------------\n");
	
	/*if(app->client_fd > 0){
		dup2(s_fd, n_fd);
	}*/
}

int buf_args(char *buf, int (*optfunc)(int, char **))
{
	char	*ptr, *argv[MAXARGC];
	int		argc;

	if (strtok(buf, WHITE) == NULL)		/* an argv[0] is required */
		return(-1);
	argv[argc = 0] = buf;

	while ( (ptr = strtok(NULL, WHITE)) != NULL) {
		if (++argc >= MAXARGC-1)	/* -1 for room for NULL at end */
			return(-1);
		argv[argc] = ptr;
	}
	argv[++argc] = NULL;

	return( (*optfunc)(argc, argv) );
}

/*
return value
-1 error
0 return
>0 keeping fd
*/
int process_cli(int argc, char *argv[])
{
	TR69CLOG(TR69C_INFO, "Process_cli");
	//DDS(argv[0])
	//DDS(argv[1])
	//DDS(argv[2])
	struct soap *soap = get_soap();
	char *s;
	
	//int i = strcmp(argv[0],"c");
	//DDI("compare", i)
	if(!strcmp(argv[0],"quit") || !strcmp(argv[0],"q"))
		cpe_exit();
	else if(!strcmp(argv[0],"inform") || !strcmp(argv[0],"i"))
	{
		if(argc < 2)
			fprintf(stderr, "CLI ERROR::The inform command need a parameter.\n");
		else if(!strcmp(argv[1],"bootstrap") || !strcmp(argv[1],"bs"))
			return send_inform(soap, IF_BOOTSTRAP, NULL);
		else if(!strcmp(argv[1],"boots") || !strcmp(argv[1],"b"))
			return send_inform(soap, IF_BOOT, NULL);
		else if(!strcmp(argv[1],"valuechange") || !strcmp(argv[1],"vc"))/*TO DO: add value*/
			return send_inform(soap, IF_VALUECHANGE, argv[2]);
		else if(!strcmp(argv[1],"connectionrequest") || !strcmp(argv[1],"cr"))
			return send_inform(soap, IF_CONNECTIONREQUEST, NULL);
		else if(!strcmp(argv[1],"upgrade") || !strcmp(argv[1],"u"))
			return send_inform(soap, IF_UPGRADE, NULL);
		else if(!strcmp(argv[1],"diagnostic") || !strcmp(argv[1],"d"))
			return send_inform(soap, IF_DIAGNOSTIC, NULL);
		else if(!strcmp(argv[1],"xshutdown") || !strcmp(argv[1],"xsd"))
			return send_inform(soap, IF_X_CTC_SHUTDOWN, NULL);
		else if(!strcmp(argv[1],"mtransfercomplete") || !strcmp(argv[1],"mtc"))
			return send_inform(soap, IF_MTRANSFERCOMPLETE, NULL);
		else if(!strcmp(argv[1],"xlogperiodic") || !strcmp(argv[1],"mlp"))
			return send_inform(soap, IF_MLOGPERIODIC, NULL);
		else if(!strcmp(argv[1],"mreboot") || !strcmp(argv[1],"mr"))
			return send_inform(soap, IF_MREBOOT, NULL);
		else
			fprintf(stderr, "CLI ERROR::The inform command not support the parameter:%s.\n", argv[1]);
	}
	else if(!strcmp(argv[0],"clients") || !strcmp(argv[0],"c"))
		print_clients();
	else if(!strcmp(argv[0],"help") || !strcmp(argv[0],"h"))
		print_clihelp();
	else if(!strcmp(argv[0],"empty") || !strcmp(argv[0],"e"))
		send_empty(soap);
	else if(!strcmp(argv[0],"tree") || !strcmp(argv[0],"t"))
	{
		if(argc == 1)
		{
		fprintf(stderr, "tr69c parameters data model tree:\n");
		fprintf(stderr, "--------------------------------------------------\n");
		print_tree(get_rootnode());
		}
		else if(argc == 2)
		{
			fprintf(stderr, "tr69c parameters node tree:\n");
			print_tree(get_node(argv[1], get_rootnode())->child_node);
		}
	}
	else if(!strcmp(argv[0],"get") || !strcmp(argv[0],"gp"))
	{
		if(argc < 2)
			fprintf(stderr, "CLI ERROR::The get command need a parameter name.\n");
		else if(get_parameter(argv[1], &s))
		{
			fprintf(stderr, "The %s = %s.\n", argv[1], s);
			free(s);
		}
		else
			fprintf(stderr, "CLI ERROR::The get command error.\n");
	}
	else if(!strcmp(argv[0],"set") || !strcmp(argv[0],"sp"))
	{
		if(argc < 3)
			fprintf(stderr, "CLI ERROR::The set command need parameter name and parameter value.\n");
		else if(set_parameter(argv[1], argv[2]))
		{
			fprintf(stderr, "Set success.\n");
		}
		else
			fprintf(stderr, "CLI ERROR::The set command error.\n");
	}
	else
	{
			fprintf(stderr, "CLI ERROR::TR69C CLI not support the command:%s.\n", argv[0]);
			print_clihelp();
	}
	
	return 0;
}
