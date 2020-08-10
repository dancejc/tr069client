#ifndef _CPEDEFINE_H_
#define _CPEDEFINE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "soapH.h"

#include "cpeutility.h"

//cpe application costant define
#define TR69SERVER_PORT 		8080
#define CLISERVER_PORT 			8081
#define MAXCLIENTS 					5
#define IPADDRMAXLENS 			32

//Running model
#define DOMAIN_SOCKET 			1

//only for debug
#define DD printf("DDDDDEEEEEBBBBBUUUUUGGGGG__%s__%d\n", __FILE__, __LINE__);
#define DDS(XX) fprintf(stderr, "DDDEEEBBBUUUGGG string = %s \n", XX);
//#define DDI(XX) fprintf(stderr, "DDDEEEBBBUUUGGG integer = %d \n", XX);
#define DDI(XX,YY) fprintf(stderr, "DDDEEEBBBUUUGGG %s = %d \n", XX, YY);

#endif
