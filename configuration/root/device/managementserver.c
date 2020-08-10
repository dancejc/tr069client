#include "cpedef.h"
#include "datamodel.h"
#include "cpeutility.h"



static TR_RET get_URL(char **value);
static TR_RET set_URL(char *value);
static TR_RET get_URLBackup(char **value);
static TR_RET set_URLBackup(char *value);
static TR_RET get_Username(char **value);
static TR_RET set_Username(char *value);
static TR_RET get_Password(char **value);
static TR_RET set_Password(char *value);
static TR_RET get_PeriodicInformEnable(char **value);
static TR_RET set_PeriodicInformEnable(char *value);
static TR_RET get_PeriodicInformInterval(char **value);
static TR_RET set_PeriodicInformInterval(char *value);
static TR_RET get_PeriodicInformTime(char **value);
static TR_RET set_PeriodicInformTime(char *value);
static TR_RET get_ParameterKey(char **value);
static TR_RET get_ConnectionRequestURL(char **value);
static TR_RET get_ConnectionRequestUsername(char **value);
static TR_RET set_ConnectionRequestUsername(char *value);
static TR_RET get_ConnectionRequestPassword(char **value);
static TR_RET set_ConnectionRequestPassword(char *value);
static TR_RET get_UpgradesManaged(char **value);
static TR_RET set_UpgradesManaged(char *value);
static TR_RET get_KickURL(char **value);
static TR_RET get_DownloadProgressURL(char **value);
static TR_RET get_UDPConnectionRequestAddress(char **value);
static TR_RET set_UDPConnectionRequestAddress(char *value);
static TR_RET get_UDPConnectionRequestAddressNotificationLimit(char **value);
static TR_RET set_UDPConnectionRequestAddressNotificationLimit(char *value);
static TR_RET get_STUNEnable(char **value);
static TR_RET set_STUNEnable(char *value);
static TR_RET get_STUNServerAddress(char **value);
static TR_RET set_STUNServerAddress(char *value);
static TR_RET get_STUNServerPort(char **value);
static TR_RET set_STUNServerPort(char *value);
static TR_RET get_STUNUsername(char **value);
static TR_RET set_STUNUsername(char *value);
static TR_RET get_STUNPassword(char **value);
static TR_RET set_STUNPassword(char *value);
static TR_RET get_STUNMaximumKeepAlivePeriod(char **value);
static TR_RET set_STUNMaximumKeepAlivePeriod(char *value);
static TR_RET get_STUNMinimumKeepAlivePeriod(char **value);
static TR_RET set_STUNMinimumKeepAlivePeriod(char *value);



NODE _managementserver[] = {
	{"URL", get_URL, set_URL, NULL, NULL},
	{"URLBackup", get_URLBackup, set_URLBackup, NULL, NULL},
	{"Username", get_Username, set_Username, NULL, NULL},
	{"Password", get_Password, set_Password, NULL, NULL},
	{"PeriodicInformEnable", get_PeriodicInformEnable, set_PeriodicInformEnable, NULL, NULL},
	{"PeriodicInformInterval", get_PeriodicInformInterval, set_PeriodicInformInterval, NULL, NULL},
	{"PeriodicInformTime", get_PeriodicInformTime, set_PeriodicInformTime, NULL, NULL},
	{"ParameterKey", get_ParameterKey, NULL, NULL, NULL},
	{"ConnectionRequestURL", get_ConnectionRequestURL, NULL, NULL, NULL},
	{"ConnectionRequestUsername", get_ConnectionRequestUsername, set_ConnectionRequestUsername, NULL, NULL},
	{"ConnectionRequestPassword", get_ConnectionRequestPassword, set_ConnectionRequestPassword, NULL, NULL},
	{"UpgradesManaged", get_UpgradesManaged, set_UpgradesManaged, NULL, NULL},
	{"KickURL", get_KickURL, NULL, NULL, NULL},
	{"DownloadProgressURL", get_DownloadProgressURL, NULL, NULL, NULL},
	{"UDPConnectionRequestAddress", get_UDPConnectionRequestAddress, set_UDPConnectionRequestAddress, NULL, NULL},
	{"UDPConnectionRequestAddressNotificationLimit", get_UDPConnectionRequestAddressNotificationLimit, set_UDPConnectionRequestAddressNotificationLimit, NULL, NULL},
	{"STUNEnable", get_STUNEnable, set_STUNEnable, NULL, NULL},
	{"STUNServerAddress", get_STUNServerAddress, set_STUNServerAddress, NULL, NULL},
	{"STUNServerPort", get_STUNServerPort, set_STUNServerPort, NULL, NULL},
	{"STUNUsername", get_STUNUsername, set_STUNUsername, NULL, NULL},
	{"STUNPassword", get_STUNPassword, set_STUNPassword, NULL, NULL},
	{"STUNMaximumKeepAlivePeriod", get_STUNMaximumKeepAlivePeriod, set_STUNMaximumKeepAlivePeriod, NULL, NULL},
	{"STUNMinimumKeepAlivePeriod", get_STUNMinimumKeepAlivePeriod, set_STUNMinimumKeepAlivePeriod, NULL, NULL},
	{"NATDetected", NULL, NULL, NULL, NULL},
	{NULL}
};

static TR_RET get_URL(char **value)
{
	*value = strdup("http://182.138.3.190:9090/ACS-server/ACS");
	
	return TRDO_OK;
}

static TR_RET set_URL(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_URLBackup(char **value)
{
	*value = strdup("http://182.138.3.190:9090/ACS-server/ACS");
	
	return TRDO_OK;
}

static TR_RET set_URLBackup(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_Username(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET set_Username(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_Password(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET set_Password(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_PeriodicInformEnable(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET set_PeriodicInformEnable(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_PeriodicInformInterval(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET set_PeriodicInformInterval(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_PeriodicInformTime(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET set_PeriodicInformTime(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_ParameterKey(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET get_ConnectionRequestURL(char **value)
{
	char url[128];
   	char *ip = "10.10.10.10";
     	//get_ipaddr(&ip);

     	memset(url,0,sizeof(url));
	sprintf(url,"http://%s:20000",ip);
	//free(ip);
	*value = strdup(url);
	
	return TRDO_OK;
}

static TR_RET get_ConnectionRequestUsername(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET set_ConnectionRequestUsername(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_ConnectionRequestPassword(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET set_ConnectionRequestPassword(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_UpgradesManaged(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET set_UpgradesManaged(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_KickURL(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET get_DownloadProgressURL(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET get_UDPConnectionRequestAddress(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET set_UDPConnectionRequestAddress(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_UDPConnectionRequestAddressNotificationLimit(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET set_UDPConnectionRequestAddressNotificationLimit(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_STUNEnable(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET set_STUNEnable(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_STUNServerAddress(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET set_STUNServerAddress(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_STUNServerPort(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET set_STUNServerPort(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_STUNUsername(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET set_STUNUsername(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_STUNPassword(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET set_STUNPassword(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_STUNMaximumKeepAlivePeriod(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET set_STUNMaximumKeepAlivePeriod(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_STUNMinimumKeepAlivePeriod(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET set_STUNMinimumKeepAlivePeriod(char *value)
{	
	return TRDO_OK;
}

