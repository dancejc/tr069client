#ifndef _CPEMAIN_H_
#define _CPEMAIN_H_

#include "cpedef.h"
#include "httpda.h"

typedef enum
{
	NONE_TYPE,
	ITMS_CONN,
	RM_CONN,
	RM1_CONN,
	CLI_TYPE
}CLIENTTYPE;

typedef enum
{
	PING_END,
	PING_DO
}PINGSTATE;

typedef enum
{
	CPE_IDEL,
	TRSESSION_RUNNING =1
}RUNNINGSTATE;

typedef struct tr_client
{
	SOAP_SOCKET fd;
	CLIENTTYPE type;
	/* char username[32]; */
	/* char userpass[32]; */
}tr_client;

typedef struct ping_stat
{
	char diagnosticstat[32];
	char host[IPADDRMAXLENS];
	unsigned int numofrepetition;
	unsigned int timeout;
	unsigned int datasize;
	unsigned int successcount;
	unsigned int failurecount;
	unsigned int averesp;
	unsigned int minresp;
	unsigned int maxresp;
	PINGSTATE pingstate;
}ping_stat;

typedef struct tracert_stat
{
}tracert_stat;

typedef struct cpe_app
{
	char acsurl[64];
	int localport;
	fd_set readfds;
	//unsigned int clientnum;
	int debugflag;
	int cliflag;
	int running_stat;
	CLIENTTYPE rtmode; /* runtime processing mode flag */
	SOAP_SOCKET server_sockfd;	/* server listen fd */
	SOAP_SOCKET cliserver_sockfd;	/* cli server listen fd */
	SOAP_SOCKET client_fd;	/* run-time accept client fd */
	SOAP_SOCKET cli_fd;					/* cpe cli event fd */
	SOAP_SOCKET max_fd;
	ping_stat *pingstat;
	tracert_stat *tracertstat;
	tr_client *clients;
	struct http_da_info *httpda_info;
}cpe_app;

int cpe_init(int argc, char *argv[]);
void cpe_exit();
int even_loop();
int cpe_get_config(cpe_app *app);
void print_info();
void print_help();
void print_clihelp();
void print_clients();
int app_init(cpe_app *app);
cpe_app* get_app();
struct soap* get_soap();

int add_client(int fd, CLIENTTYPE type, fd_set *set);
int rm_client(int fd, fd_set *set);

int add_listener(int fd ,fd_set *set);
int rm_listener(int fd, fd_set *set);

int close_clients();

int buf_args(char *buf, int (*optfunc)(int, char **));
int process_cli(int argc, char *argv[]);
int process_clievent(struct soap *soap, SOAP_SOCKET fd);

int cpe_post(struct soap *soap, const char *endpoint, const char *host, 
				int port, const char *path, const char *action, size_t count);

#endif
