#include "cpedef.h"
#include "datamodel.h"



static TR_RET get_PersistentData(char **value);
static TR_RET set_PersistentData(char *value);
static TR_RET get_ConfigFile(char **value);
static TR_RET set_ConfigFile(char *value);



NODE _config[] = {
	{"PersistentData", get_PersistentData, set_PersistentData, NULL, NULL},
	{"ConfigFile", get_ConfigFile, set_ConfigFile, NULL, NULL},
	{NULL}
};

static TR_RET get_PersistentData(char **value)
{
	return TRDO_OK;
}

static TR_RET set_PersistentData(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_ConfigFile(char **value)
{
	return TRDO_OK;
}

static TR_RET set_ConfigFile(char *value)
{	
	return TRDO_OK;
}

