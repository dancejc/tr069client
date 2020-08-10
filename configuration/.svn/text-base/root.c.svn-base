#include "cpedef.h"
#include "datamodel.h"



extern NODE _device[];

static TR_RET get_DeviceSummary(char **value);

NODE _root[] = {
	{"Device", NULL, NULL, NULL, _device},
	{"DeviceSummary", get_DeviceSummary, NULL, NULL, NULL},
	{NULL}
};



static TR_RET get_DeviceSummary(char **value)
{	
	*value = strdup("");
	return TRDO_OK;
}

