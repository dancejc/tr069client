#ifndef _CPEADPATER_H_
#define _CPEADPATER_H_

typedef enum
{
	UP_STAGE_REQUEST,
	REBOOT_SYSTEM_REQUEST
}MSGTYPE_t;

//TODO
int process_message(SOAP_SOCKET fd, int (*optfunc)(int, char **));
int send_message(int MSG);

#endif

