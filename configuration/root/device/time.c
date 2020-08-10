#include "cpedef.h"
#include "datamodel.h"



static TR_RET get_NTPServer1(char **value);
static TR_RET set_NTPServer1(char *value);
static TR_RET get_NTPServer2(char **value);
static TR_RET set_NTPServer2(char *value);
static TR_RET get_CurrentLocalTime(char **value);
static TR_RET set_CurrentLocalTime(char *value);
static TR_RET get_LocalTimeZone(char **value);
static TR_RET set_LocalTimeZone(char *value);



NODE _time[] = {
	{"NTPServer1", get_NTPServer1, set_NTPServer1, NULL, NULL},
	{"NTPServer2", get_NTPServer2, set_NTPServer2, NULL, NULL},
	{"CurrentLocalTime", get_CurrentLocalTime, set_CurrentLocalTime, NULL, NULL},
	{"LocalTimeZone", get_LocalTimeZone, set_LocalTimeZone, NULL, NULL},
	{NULL}
};

static TR_RET get_NTPServer1(char **value)
{
	return TRDO_OK;
}

static TR_RET set_NTPServer1(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_NTPServer2(char **value)
{
	return TRDO_OK;
}

static TR_RET set_NTPServer2(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_CurrentLocalTime(char **value)
{
	return TRDO_OK;
}

static TR_RET set_CurrentLocalTime(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_LocalTimeZone(char **value)
{
	return TRDO_OK;
}

static TR_RET set_LocalTimeZone(char *value)
{	
	return TRDO_OK;
}

