#include "cpedef.h"
#include "datamodel.h"



static TR_RET get_ServiceList(char **value);
static TR_RET get_PPPoEID(char **value);
static TR_RET set_PPPoEID(char *value);
static TR_RET get_PPPoEPassword(char **value);
static TR_RET set_PPPoEPassword(char *value);
static TR_RET get_DHCPID(char **value);
static TR_RET set_DHCPID(char *value);
static TR_RET get_DHCPPassword(char **value);
static TR_RET set_DHCPPassword(char *value);
static TR_RET get_UserID(char **value);
static TR_RET set_UserID(char *value);
static TR_RET get_Password(char **value);
static TR_RET set_Password(char *value);
static TR_RET get_AuthURL(char **value);
static TR_RET set_AuthURL(char *value);
static TR_RET get_AuthURLBackup(char **value);
static TR_RET set_AuthURLBackup(char *value);

NODE _serviceinfo[] = {
	{"ServiceList", get_ServiceList, NULL, NULL, NULL},
	{"PPPoEID", get_PPPoEID, set_PPPoEID, NULL, NULL},
	{"PPPoEPassword", get_PPPoEPassword, set_PPPoEPassword, NULL, NULL},
	{"DHCPID", get_DHCPID, set_DHCPID, NULL, NULL},
	{"DHCPPassword", get_DHCPPassword, set_DHCPPassword, NULL, NULL},
	{"UserID", get_UserID, set_UserID, NULL, NULL},
	{"Password", get_Password, set_Password, NULL, NULL},
	{"AuthURL", get_AuthURL, set_AuthURL, NULL, NULL},
	{"AuthURLBackup", get_AuthURLBackup, set_AuthURLBackup, NULL, NULL},
	{NULL}
};

static TR_RET get_ServiceList(char **value)
{
	return TRDO_OK;
}

static TR_RET get_PPPoEID(char **value)
{
	return TRDO_OK;
}

static TR_RET set_PPPoEID(char *value)
{
	return TRDO_OK;
}

static TR_RET get_PPPoEPassword(char **value)
{
	return TRDO_OK;
}

static TR_RET set_PPPoEPassword(char *value)
{
	return TRDO_OK;
}

static TR_RET get_DHCPID(char **value)
{
	return TRDO_OK;
}

static TR_RET set_DHCPID(char *value)
{
	return TRDO_OK;
}

static TR_RET get_DHCPPassword(char **value)
{
	return TRDO_OK;
}

static TR_RET set_DHCPPassword(char *value)
{
	return TRDO_OK;
}

static TR_RET get_UserID(char **value)
{
	return TRDO_OK;
}

static TR_RET set_UserID(char *value)
{
	return TRDO_OK;
}

static TR_RET get_Password(char **value)
{
	return TRDO_OK;
}

static TR_RET set_Password(char *value)
{
	return TRDO_OK;
}

static TR_RET get_AuthURL(char **value)
{
	return TRDO_OK;
}

static TR_RET set_AuthURL(char *value)
{
	return TRDO_OK;
}

static TR_RET get_AuthURLBackup(char **value)
{
	return TRDO_OK;
}

static TR_RET set_AuthURLBackup(char *value)
{
	return TRDO_OK;
}

