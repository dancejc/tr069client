#include <stdarg.h> 

#include "cpe.h"
#include "cpeutility.h"

#include <time.h>
#include <pthread.h>
#include <sys/stat.h>
//for get local ip
#include <net/if.h> 
#include <netinet/in.h> 
#include <net/if_arp.h> 

#include "adapter.h"

pthread_t ping_thread;
static t_ipping_para ping_para;
static t_traceroute_para traceroute_para;
static int rpc_stat;
/*
if we want to save debug log, follow this:
vi /etc/syslog.conf, 
add user.debug                  /var/log/debug 
service syslog restart
http://blog.sina.com.cn/s/blog_718aec8f0100rgx0.html
*/
int TR69CLOG(LOGLEVEL level, char *message, ...)
{
	va_list args; 
	va_start(args ,message);
	
	char buf[128];
	
	switch(level)
	{
		case TR69C_INFO:
		sprintf(buf, "TR69C_RUN_INFO::%s\n", message);
#ifdef CPE_DEBUG
		vfprintf(stderr, buf, args);
#else
		syslog(LOG_INFO|LOG_USER, "TR69C_LOG_INFO::%s\n", buf);
#endif
			return 0;
		default:
			return 0;
	}
	
	/*FILE* fp;
	fp = fopen("not_here", "r");
	if(!fp)
		syslog(LOG_ERR|LOG_USER, "oops - %m\n");
		
	openlog("testsyslog", LOG_CONS | LOG_PID, 0);    
  syslog(LOG_DEBUG|LOG_USER, "syslog test message generated in program %s \n", argv[0]);    
  closelog();*/
  
	va_end(args); 

  return 0;
}

int trprint(char *message,...)
{
	cpe_app* app = get_app();
	return 0;
}

time_t get_nowtime()
{
	return time(NULL);
}

int get_cpe_config()
{
	return 0;
}

int do_ping_thread()
{
	pthread_create(&ping_thread, NULL, do_ping, NULL);
	return 0;
}

unsigned int get_ping_time(char *buf)
{
	return 0;
}

void *do_ping()
{
	char cmd[1024];
	char result[1024];
	unsigned int time, totaltime, maxtime, mintime;
	bzero(cmd, 1024);
	bzero(result, 1024);
	cpe_app *app = get_app();
	sprintf(cmd, "ping %s -c %d -s %d -w %d", app->pingstat->host, 
			app->pingstat->numofrepetition, app->pingstat->datasize, app->pingstat->timeout);
	//printf("%s\n", cmd);
	executeCMD(cmd, result);
}

/*int main()
{
  char result[1024];
  bzero(result, 1024);
  //executeCMD( "ls /opt/*.rpm | awk -F '[-|.]' '{print $3}'", result);
  executeCMD( "ping -c 2 www.163.com|grep receive", result);
  printf("%s", result );
  return 0;
}*/
void executeCMD(const char *cmd, char *result)
{
  char buf_ps[CMDLENGTH];
  char ps[CMDLENGTH]={0};
  FILE *ptr;
  strcpy(ps, cmd);
  if((ptr = popen(ps, "r"))!=NULL)
  {
	  while(fgets(buf_ps, CMDLENGTH, ptr)!=NULL)
	  {
		  strcat(result, buf_ps);
		  if(strlen(result) > CMDLENGTH)
		  break;
	  }
	  pclose(ptr);
	  ptr = NULL;
  }
  else
  {
  	printf("popen %s error\n", ps);
  }
}

void get_local_ip(int family, char *address, int size)
{
  int fd, intrface; 
	struct ifreq buf[16]; 
	//struct arpreq arp; 
	struct ifconf ifc; 
	
	memset(address, 0, size);
	
	if ((fd = socket (family, SOCK_DGRAM, 0)) >= 0) 
	{ 
		ifc.ifc_len = sizeof buf; 
		ifc.ifc_buf = (caddr_t) buf; 
		if (!ioctl (fd, SIOCGIFCONF, (char *) &ifc)) 
		{ 
			intrface = ifc.ifc_len / sizeof (struct ifreq)-1; 
			//Get local NIC ip address 
			if (!(ioctl (fd, SIOCGIFADDR, (char *) &buf[intrface]))) 
			{
				//strcpy(address, inet_ntoa(((struct sockaddr_in*)(&buf[intrface].ifr_addr))->sin_addr));
				snprintf(address, size, (char *)inet_ntoa(((struct sockaddr_in*)(&buf[intrface].ifr_addr))->sin_addr));
			} 
			else 
			{ 
				char str[256]; 
				sprintf (str, "cpm: ioctl device %s", buf[intrface].ifr_name); 
				perror (str); 
			} 
		}else 
			perror ("cpm: ioctl"); 
	}else 
		perror ("cpm: socket"); 
	close (fd); 
}

t_ipping_para * get_ippingpara()
{
	return &ping_para;
}

t_traceroute_para * get_traceroutepara()
{
	return &traceroute_para;
}

void process_rpcstat()
{
	//struct cmd_st cmdsnd;
	pthread_attr_t attr;
	pthread_t id_thread;

	//bzero(&cmdsnd, sizeof(struct cmd_st));
	switch(get_rpcstat())
	{
	case RPC_DOWNLOAD :
		/*cmdsnd.cmd = CMD_UP_STAGE_REQUEST;
		cmdsnd.ext = SOFT_UP_STAG_BEGIN;
		strcpy(cmdsnd.dt, "test");
		cmdsend(TYPE_MSG_APPSWITCH, cmdsnd);*/
		send_message(UP_STAGE_REQUEST);
		break;
	case RPC_REBOOT :
		/*cmdsnd.cmd = CMD_REBOOT_SYSTEM_REQUEST;
		cmdsnd.ext = 4;
		cmdsend(TYPE_MSG_APPSWITCH, cmdsnd);*/
		send_message(REBOOT_SYSTEM_REQUEST);
		break;
	case RPC_PING :
		pthread_attr_init(&attr);
		if (pthread_create(&id_thread, &attr, process_ping, NULL) != 0)
			printf("pthread_create--process_ping--error!\n");
		break;
	case RPC_TRACEROUTE :
		pthread_attr_init(&attr);
		if (pthread_create(&id_thread, &attr, process_traceroute, NULL) != 0)
			printf("pthread_create--process_traceroute--error!\n");
		break;
	case RPC_OTHER :
		break;
	default :
		break;
	}

	set_rpcstat(RPC_OTHER);
	return;
}

void * process_ping()
{
	char cmd[128] = {0};
	char str[64] = {0};
	char tmp[32] = {0};
	FILE *ptr;
	unsigned int transmitted, received, avg, min, max;
	t_ipping_para  * pingpara;

	pingpara = get_ippingpara();
	sprintf(cmd, "ping %s -c %d -s %d -w %d", pingpara->host, pingpara->numberofrepetition, 
		pingpara->datablocksize, pingpara->timeout);
	
	if ((ptr = popen(cmd, "r")) != NULL)
	{
		while (fgets(str, 128, ptr) != NULL)
		{
			if (strstr(str, "ping statistics"))
				break;
		}
		fgets(str, 1024, ptr);
		sscanf(str, "%d packets transmitted, %d packets received, %*s packet loss", &transmitted, &received);
		fgets(str, 1024, ptr);
		sscanf(str, "round-trip min/avg/max = %d%[^/]/%d%[^/]/%d ms", &min, tmp, &avg, tmp, &max);
	}
	else
	{
		printf("popen cmd error. \n");
		return NULL;
	}

	pingpara->successcount = received;
	pingpara->failurecount = transmitted - received;
	pingpara->averageresponsetime = avg;
	pingpara->minimumresponsetime = min;
	pingpara->maximumresponsetime = max;
	
	//send message for inform

	pclose(ptr);
	ptr = NULL;
	
	return NULL;
}

void * process_traceroute()
{
	char cmd[128];
	char str[128];
	FILE *ptr;
	t_traceroute_para * traceroutepara;
	unsigned int responsetime, numberofroutehops;

	traceroutepara = get_traceroutepara();
	memset((void *)cmd, 0, 128);
	sprintf(cmd, "traceroute %s -m %d -t %d -w %d", traceroutepara->host, traceroutepara->maxhopcount, 
		traceroutepara->datablocksize, traceroutepara->timeout);

	if ((ptr = popen(cmd, "r")) != NULL)
	{
	}
	else
	{
		printf("popen cmd error. \n");
		return NULL;
	}

	//send message for inform
	
	pclose(ptr);
	ptr = NULL;
	
	return NULL;
}

int get_rpcstat()
{
	return rpc_stat;
}

void set_rpcstat(int stat)
{
	rpc_stat = stat;

	return;
}


#if 0
int ftp_download_configfile(char* url, char* userName, char* password, unsigned int fileSize, char* targetFileName)
{
	FILE *fpCmd;
	FILE *fpPipe;
	
	char *pFileName;
	char *pIpAddress;
	char *pPath;
	char  tmpBuf[512];
	int  receiveSize = 0;

	if (url && (strlen(url) >= sizeof(tmpBuf)))
	{
		TR69CLOG(TR69C_ERROR,"invalid url\n");
		return -1;
	}

	/* get server ip from url  */
	pIpAddress = strstr(url,"://");
	if (pIpAddress == NULL)
	{
		TR69CLOG(TR69C_ERROR,"invalid url\n");
		return -1;
	}
	pIpAddress+=3;

    /* get path  from url  */
	pPath = strchr(pIpAddress,'/');
	if (pPath == NULL)
	{
		TR69CLOG(TR69C_ERROR,"invalid url\n");
		return -1;
	}

	pFileName = strrchr(url,'/');
	if (pFileName < pIpAddress)
	{
   		TR69CLOG(TR69C_ERROR,"invalid url\n");
   		return -1;
	}
	
	/* save path  */
	bzero(tmpBuf,sizeof(tmpBuf));
	if (pFileName == pPath)
	{
		tmpBuf[0] = '/';
	}
	else
	{
		strncpy(tmpBuf,pPath,pFileName-pPath+1);
	}
	
	/* get fileName */
	if( *(pFileName+1) != '\0' )
	{
		pFileName++;
	}
	else if( targetFileName!= NULL)
	{
		pFileName = targetFileName;
	}
	else
	{
		TR69CLOG(TR69C_ERROR,"not found filename\n");
		return -1;
	}
	
    /* generate command file */ 
	fpCmd = fopen("/tmp/ftp_cmd.txt","wt");
	if (fpCmd == NULL)
	{
   		return -1;	
	}
	
	if (userName != NULL)
	{
		fprintf(fpCmd,"user %s %s\n",userName,password);
	}
	fprintf(fpCmd,"cd %s\n",tmpBuf);
	fprintf(fpCmd,"ascii\n");
	fprintf(fpCmd,"lcd /tmp/\n");
	fprintf(fpCmd,"get %s\n",pFileName);
	fclose(fpCmd);	
	
	bzero(tmpBuf,sizeof(tmpBuf));
	sprintf(tmpBuf,"ftp -idnv ");
	strncpy(tmpBuf+strlen(tmpBuf),pIpAddress,pPath-pIpAddress);
	sprintf(tmpBuf+strlen(tmpBuf)," < /tmp/ftp_cmd.txt");

	
	TR69CLOG(TR69C_INFO,"call shell: %s\n",tmpBuf);

	/* call shell */
	fpPipe=popen(tmpBuf,"r"); 
	if(fpPipe == NULL) 
 	{ 
      TR69CLOG(TR69C_ERROR,"popen failed()!\n");
      remove("/tmp/ftp_cmd.txt");
      return -1;
	} 

	/* detect whether download is successful */
	bzero(tmpBuf,sizeof(tmpBuf));
	while (fgets(tmpBuf, sizeof(tmpBuf), fpPipe) != NULL)
	{
		if (strstr(tmpBuf, "bytes received in") != NULL)
		{
				sscanf(tmpBuf, "%d bytes received in %*s secs (%*s kB/s)",&receiveSize);
				break;
		}
		bzero(tmpBuf,sizeof(tmpBuf));
	}
	pclose(fpPipe); 
	remove("/tmp/ftp_cmd.txt");

	TR69CLOG(TR69C_INFO,"ftp-download: %s, %d bytes!\n",pFileName,receiveSize);
	
	if ( (receiveSize != 0) && ((fileSize == 0) || (receiveSize == fileSize)))
	{
			char buf[128];
			bzero(tmpBuf,sizeof(tmpBuf));
			sprintf(tmpBuf,"/tmp/%s",pFileName);
			sprintf(buf,"/cfg/%s",pFileName);
			rename(tmpBuf,buf);
			return 0;	
	}
	
	return -1;
} 
#endif




int download_file(char *url, char* userName, char* password, int fileSize, int transferMode, char* localFileName)
{
	char*  buf;
	char*  fileName;
	FILE*  fpPipe;
	char   tmpBuf[128];
	int    downloadSize = 0;
	int    urlLen = 0;
	int    userNameLen = 0;
	int    passwordLen = 0;
	
	if ((url == NULL) || (localFileName == NULL))
	{
		TR69CLOG(TR69C_ERROR,"url or localFileName is NULL\n");
		return -1;	
	}
	
	fileName = strrchr(localFileName,'/');
	if ((fileName == NULL) || (localFileName[0] != '/') || ((fileName+1)=='/0'))
	{
		return -1;	
	}
	
	urlLen = strlen(url);
	if (userName != NULL)
	{
		userNameLen = strlen(userName);
	}
	if (password != NULL)
	{
		passwordLen = strlen(password);
	}
	
	if (urlLen+userNameLen+passwordLen > 1024-128)
	{
		TR69CLOG(TR69C_ERROR,"url,username,password is too long!\n");
		return -1;
	}
	
	buf = (char*)malloc(1024);
	if (buf == NULL)
	{
		TR69CLOG(TR69C_ERROR,"malloc failed!\n");
		return -1;	
	}
	bzero(buf,sizeof(buf));

	if (transferMode != 0)
	{
		sprintf(buf,"curl -m 300 --connect-timeout 60 -s -w %%{size_download} -B");
	}
	else
	{
		sprintf(buf,"curl -m 300 --connect-timeout 60 -s -w %%{size_download}");
	}
	
	if ((userName != NULL) && (password != NULL))
	{
		sprintf(buf+strlen(buf)," -u %s:%s",userName,password);
	}
	
	sprintf(buf+strlen(buf)," -o /tmp/%s %s",fileName+1,url); 

	TR69CLOG(TR69C_INFO,"popen:%s\n",buf);
	
	fpPipe = popen(buf,"r"); 
	if(fpPipe == NULL) 
 	{ 
      TR69CLOG(TR69C_ERROR,"popen failed()!\n");
      goto DOWNLOAD_FAILED;;
	} 

	bzero(tmpBuf,sizeof(tmpBuf));
	bzero(buf,sizeof(buf));
	while (fgets(tmpBuf, sizeof(tmpBuf), fpPipe) != NULL)
	{
		 strcat(buf,tmpBuf);
		 bzero(tmpBuf,sizeof(tmpBuf));
	}
	downloadSize = atoi(buf);
	
	pclose(fpPipe);
	
	if (downloadSize == fileSize)
	{
		TR69CLOG(TR69C_INFO,"download successfully,url=%s,downloadSize=%d\n",url,downloadSize);
		bzero(buf,sizeof(buf));
		sprintf(buf,"/tmp/%s",fileName+1);
		rename(buf,localFileName);
		free(buf);
		return 0; 
	}
	
DOWNLOAD_FAILED:
	TR69CLOG(TR69C_ERROR,"fail to download,url=%s\n",url);
	free(buf);
	return -1;
}



int upload_file(char *url, char* userName, char* password, int transferMode, char* localFileName)
{
	char*  buf;
	FILE*  fpPipe;
	struct stat statBuf;
	int    uploadSize = 0;
	char   tmpBuf[128];
	
	if ((url == NULL) || (localFileName == NULL))
	{
		return -1;	
	}
	if (url && (strlen(url) > (1024-256)))
	{
		return -1;
	}
  
	buf = (char*)malloc(1024);
	if (buf == NULL)
	{
		printf("malloc failed!\n");
		return -1;	
	}
	
	bzero(buf,sizeof(buf));
	if (transferMode != 0)
	{
		sprintf(buf,"curl -m 120 --connect-timeout 20 -T %s -s -w %%{size_upload} -B",localFileName);
	}
	else
	{
		sprintf(buf,"curl -m 120 --connect-timeout 20 -T %s -s -w %%{size_upload}",localFileName);
	}
	
	if (userName != NULL && password != NULL)
	{
		sprintf(buf+strlen(buf)," -u %s:%s %s",userName,password,url);
	}
	else
	{
		sprintf(buf+strlen(buf)," %s",url);
	}

	fpPipe = popen(buf,"r"); 
	if(fpPipe == NULL) 
 	{ 
		TR69CLOG(TR69C_ERROR,"popen failed: %s!\n",buf);
		free(buf);
		return -1;
	} 

	bzero(buf,sizeof(buf));
	bzero(tmpBuf,sizeof(tmpBuf));
	while (fgets(tmpBuf, sizeof(tmpBuf), fpPipe) != NULL)
	{
		 strcat(buf,tmpBuf);
		 bzero(tmpBuf,sizeof(tmpBuf));
	}
	uploadSize = atoi(buf);
	
	pclose(fpPipe);
	free(buf);
	buf = NULL;
	
	stat(localFileName, &statBuf);
	if ( uploadSize >= statBuf.st_size)
	{
		TR69CLOG(TR69C_INFO,"upload successfully: url=%s,localFileName=%s\n",url,localFileName);
		return 0;
	}

	TR69CLOG(TR69C_ERROR,"fail to upload:url=%s,localFileName=%s\n",url,localFileName);
	return -1;
}
