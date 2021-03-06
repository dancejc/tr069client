#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
//#include <common.h>
#include <netinet/in.h>
#include <net/if.h>
#include <netdb.h>
#include <linux/if_ether.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <fcntl.h>

//#include "common.h"
//#include "readip.h"
#include "cpedef.h"
#include "datamodel.h"
#include "cpeutility.h"



extern NODE _stats[];
extern NODE _ippingdiagnostics[];
extern NODE _traceroutediagnostics[];

static TR_RET get_AddressingType(char **value);
static TR_RET set_AddressingType(char *value);
static TR_RET get_IPAddress(char **value);
static TR_RET set_IPAddress(char *value);
static TR_RET get_SubnetMask(char **value);
static TR_RET set_SubnetMask(char *value);
static TR_RET get_DefaultGateway(char **value);
static TR_RET set_DefaultGateway(char *value);
static TR_RET get_DNSServers(char **value);
static TR_RET set_DNSServers(char *value);
static TR_RET get_MACAddress(char **value);
static TR_RET get_MACAddressOverride(char **value);
static TR_RET set_MACAddressOverride(char *value);
static TR_RET get_IsSupportIPv6(char **value);

NODE _lan[] = {
	{"AddressingType", get_AddressingType, set_AddressingType, NULL, NULL},
	{"IPAddress", get_IPAddress, set_IPAddress, NULL, NULL},
	{"SubnetMask", get_SubnetMask, set_SubnetMask, NULL, NULL},
	{"DefaultGateway", get_DefaultGateway, set_DefaultGateway, NULL, NULL},
	{"DNSServers", get_DNSServers, set_DNSServers, NULL, NULL},
	{"MACAddress", get_MACAddress, NULL, NULL, NULL},
	{"MACAddressOverride", get_MACAddressOverride, set_MACAddressOverride, NULL, NULL},
	{"IsSupportIPv6", get_IsSupportIPv6, NULL, NULL, NULL},
	{"Stats", NULL, NULL, NULL, _stats},
	{"IPPingDiagnostics", NULL, NULL, NULL, _ippingdiagnostics},
	{"TraceRouteDiagnostics", NULL, NULL, NULL, _traceroutediagnostics},
	{NULL}
};

static TR_RET get_AddressingType(char **value)
{
	return TRDO_OK;
}

static TR_RET set_AddressingType(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_IPAddress(char **value)
{
	*value = strdup("10.10.10.10");
	
	return TRDO_OK;
}

static TR_RET set_IPAddress(char *value)
{
	return TRDO_OK;
}

static TR_RET get_SubnetMask(char **value)
{
	return TRDO_OK;
}

static TR_RET set_SubnetMask(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_DefaultGateway(char **value)
{
	return TRDO_OK;
}

static TR_RET set_DefaultGateway(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_DNSServers(char **value)
{
	return TRDO_OK;
}

static TR_RET set_DNSServers(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_MACAddress(char **value)
{
	*value = strdup("AAAAAAAAAAAAAAAA");
	
	return TRDO_OK;
}

static TR_RET get_MACAddressOverride(char **value)
{
	return TRDO_OK;
}

static TR_RET set_MACAddressOverride(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_IsSupportIPv6(char **value)
{
	return TRDO_OK;
}

