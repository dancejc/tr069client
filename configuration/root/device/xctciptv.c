#include "cpedef.h"
#include "datamodel.h"



extern NODE _statisticconfiguration[];
extern NODE _servicestatistics[];
extern NODE _logmsg[];
extern NODE _serviceinfo[];
extern NODE _imsinfo[];

static TR_RET get_STBID(char **value);
static TR_RET get_PhyMemSize(char **value);
static TR_RET get_StorageSize(char **value);
static TR_RET get_ForceUpgrade(char **value);
static TR_RET set_ForceUpgrade(char *value);

NODE _xctciptv[] = {
	{"STBID", get_STBID, NULL, NULL, NULL},
	{"PhyMemSize", get_PhyMemSize, NULL, NULL, NULL},
	{"StorageSize", get_StorageSize, NULL, NULL, NULL},
	{"ForceUpgrade", get_ForceUpgrade, set_ForceUpgrade, NULL, NULL},
	{"StatisticConfiguration", NULL, NULL, NULL, _statisticconfiguration},
	{"ServiceStatistics", NULL, NULL, NULL, _servicestatistics},
	{"LogMsg", NULL, NULL, NULL, _logmsg},
	{"ServiceInfo", NULL, NULL, NULL, _serviceinfo},
	{"IMSInfo", NULL, NULL, NULL, _imsinfo},
	{NULL}
};

static TR_RET get_STBID(char **value)
{
	*value = strdup("00100199010211400000D0154AD4934C");

	return TRDO_OK;
}

static TR_RET get_PhyMemSize(char **value)
{
	return TRDO_OK;
}

static TR_RET get_StorageSize(char **value)
{
	return TRDO_OK;
}

static TR_RET get_ForceUpgrade(char **value)
{
	return TRDO_OK;
}

static TR_RET set_ForceUpgrade(char *value)
{
	return TRDO_OK;
}

