#include "cpedef.h"
#include "datamodel.h"



static TR_RET get_Enable(char **value);
static TR_RET set_Enable(char *value);
static TR_RET get_MsgOrFile(char **value);
static TR_RET set_MsgOrFile(char *value);
static TR_RET get_LogFtpServer(char **value);
static TR_RET set_LogFtpServer(char *value);
static TR_RET get_LogFtpUser(char **value);
static TR_RET set_LogFtpUser(char *value);
static TR_RET get_LogFtpPassword(char **value);
static TR_RET set_LogFtpPassword(char *value);
static TR_RET get_Duration(char **value);
static TR_RET set_Duration(char *value);
static TR_RET get_RTSPInfo(char **value);
static TR_RET get_HTTPInfo(char **value);
static TR_RET get_IGMPInfo(char **value);
static TR_RET get_PkgTotalOneSec(char **value);
static TR_RET get_ByteTotalOneSec(char **value);
static TR_RET get_PkgLostRate(char **value);
static TR_RET get_AvarageRate(char **value);
static TR_RET get_BUFFER(char **value);
static TR_RET get_ERROR(char **value);
static TR_RET get_VendorExt(char **value);

NODE _logmsg[] = {
	{"Enable", get_Enable, set_Enable, NULL, NULL},
	{"MsgOrFile", get_MsgOrFile, set_MsgOrFile, NULL, NULL},
	{"LogFtpServer", get_LogFtpServer, set_LogFtpServer, NULL, NULL},
	{"LogFtpUser", get_LogFtpUser, set_LogFtpUser, NULL, NULL},
	{"LogFtpPassword", get_LogFtpPassword, set_LogFtpPassword, NULL, NULL},
	{"Duration", get_Duration, set_Duration, NULL, NULL},
	{"RTSPInfo", get_RTSPInfo, NULL, NULL, NULL},
	{"HTTPInfo", get_HTTPInfo, NULL, NULL, NULL},
	{"IGMPInfo", get_IGMPInfo, NULL, NULL, NULL},
	{"PkgTotalOneSec", get_PkgTotalOneSec, NULL, NULL, NULL},
	{"ByteTotalOneSec", get_ByteTotalOneSec, NULL, NULL, NULL},
	{"PkgLostRate", get_PkgLostRate, NULL, NULL, NULL},
	{"AvarageRate", get_AvarageRate, NULL, NULL, NULL},
	{"BUFFER", get_BUFFER, NULL, NULL, NULL},
	{"ERROR", get_ERROR, NULL, NULL, NULL},
	{"VendorExt", get_VendorExt, NULL, NULL, NULL},
	{NULL}
};

static TR_RET get_Enable(char **value)
{
	return TRDO_OK;
}

static TR_RET set_Enable(char *value)
{
	return TRDO_OK;
}

static TR_RET get_MsgOrFile(char **value)
{
	return TRDO_OK;
}

static TR_RET set_MsgOrFile(char *value)
{
	return TRDO_OK;
}

static TR_RET get_LogFtpServer(char **value)
{
	return TRDO_OK;
}

static TR_RET set_LogFtpServer(char *value)
{
	return TRDO_OK;
}

static TR_RET get_LogFtpUser(char **value)
{
	return TRDO_OK;
}

static TR_RET set_LogFtpUser(char *value)
{
	return TRDO_OK;
}

static TR_RET get_LogFtpPassword(char **value)
{
	return TRDO_OK;
}

static TR_RET set_LogFtpPassword(char *value)
{
	return TRDO_OK;
}

static TR_RET get_Duration(char **value)
{
	return TRDO_OK;
}

static TR_RET set_Duration(char *value)
{
	return TRDO_OK;
}

static TR_RET get_RTSPInfo(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HTTPInfo(char **value)
{
	return TRDO_OK;
}

static TR_RET get_IGMPInfo(char **value)
{
	return TRDO_OK;
}

static TR_RET get_PkgTotalOneSec(char **value)
{
	return TRDO_OK;
}

static TR_RET get_ByteTotalOneSec(char **value)
{
	return TRDO_OK;
}

static TR_RET get_PkgLostRate(char **value)
{
	return TRDO_OK;
}

static TR_RET get_AvarageRate(char **value)
{
	return TRDO_OK;
}

static TR_RET get_BUFFER(char **value)
{
	return TRDO_OK;
}

static TR_RET get_ERROR(char **value)
{
	return TRDO_OK;
}

static TR_RET get_VendorExt(char **value)
{
	return TRDO_OK;
}

