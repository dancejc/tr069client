#ifndef _CPEFUNC_H_
#define _CPEFUNC_H_

#include "soapH.h"

typedef enum
{
	IF_BOOTSTRAP = 0,
	IF_BOOT,
	IF_PERIODIC,
	IF_SCHEDULED,
	IF_VALUECHANGE = 4,
	IF_CONNECTIONREQUEST = 6,
	IF_UPGRADE,
	IF_DIAGNOSTIC,
	IF_X_CTC_SHUTDOWN = 20,
	IF_MTRANSFERCOMPLETE,
	IF_MLOGPERIODIC,
	IF_MREBOOT
}INFORMTYPE;

int send_inform(struct soap *soap, INFORMTYPE type, char *parameter);
int send_bootstrap_inform(struct soap *soap);
int send_boot_inform();

int send_empty(struct soap *soap);

#endif
