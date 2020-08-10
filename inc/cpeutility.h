#ifndef _TR69UTILITY_H_
#define _TR69UTILITY_H_

#define CMDLENGTH 1024

typedef enum
{
	TR69C_INFO,
	TR69C_MSG,
	TR69C_ERROR
}LOGLEVEL;

enum
{
	RPC_OTHER,
	RPC_REBOOT,
	RPC_DOWNLOAD,
	RPC_UPLOAD,
	RPC_PING,
	RPC_TRACEROUTE
};

typedef struct t_ipping_para_b t_ipping_para;
struct t_ipping_para_b
{
	int stat;
	char diagnosticstate[32];
	char host[256];
	unsigned int numberofrepetition;
	unsigned int timeout;
	unsigned int datablocksize;
	unsigned int dscp;
	unsigned int successcount;
	unsigned int failurecount;
	unsigned int averageresponsetime;
	unsigned int minimumresponsetime;
	unsigned int maximumresponsetime;
};

typedef struct t_traceroute_para_b t_traceroute_para;
struct t_traceroute_para_b
{
	int stat;
	char diagnosticstate[32];
	char host[256];
	unsigned int timeout;
	unsigned int datablocksize;
	unsigned int maxhopcount;
	unsigned int dscp;
	unsigned int responsetime;
	unsigned int numberofroutehops;
	char **RouteHops;
};

int TR69CLOG(LOGLEVEL level, char *message,...);
int trprint(char *message,...);

unsigned int get_ping_time(char *buf);
void *do_ping();
int do_ping_thread();
void executeCMD(const char *cmd, char *result);
void get_local_ip(int family, char *address, int size);
time_t get_nowtime();
char *get_manufacturer();
char *get_OUI();
char *get_productclass();
char *get_serialnumber();
char *get_ipaddr();
char *get_macaddr();
void process_rpcstat();
int get_rpcstat();
void set_rpcstat(int stat);

void * process_ping();
t_ipping_para * get_ippingpara();
void * process_traceroute();
t_traceroute_para * get_traceroutepara();

#if 0
int ftp_download_configfile(char* url, char* userName, char* password, unsigned int fileSize, char* targetFileName);

#endif




/**
 *
 * @brief	       download file, support http/ftp protocol.
 *
 * @param	url	[in]	specify the resource to be download
 *
 * @param	userName [in]	 can be NULL
 *
 * @param	password [in]	 can be NULL
 *
 * @param       fileSize[in] size fo the file to be download
 *
 * @param      transferMode: 0 use binary transfer mode , other value use ascii transfer mode
 *
 * @param      localFileName[in] the absolute path where to store the  file downloaded 
 *
 * @return	0: downlaod successfully; -1: failed to download
 *
 */
 int download_file(char *url, char* userName, char* password, int fileSize, int transferMode, char* localFileName);


/**
 *
 *  @brief	       upload file, support http/ftp protocol.
 *
 * @param	url	[in]	specify the path in server where to store the uploaded file
 *
 * @param	userName [in]	 can be NULL
 *
 * @param	password [in]	 can be NULL
 *
 * @param      transferMode: 0 use binary transfer mode , other value use ascii transfer mode
 *
 * @param      localFileName[in] the absolute path specify the file to be upload
 *
 * @return	0: upload successfully; -1: failed to upload
 *
 */
int upload_file(char *url, char* userName, char* password, int transferMode, char* localFileName);

#endif
