#include "cpedef.h"
#include "datamodel.h"



static TR_RET get_ManufacturerOUI(char **value);
static TR_RET set_ManufacturerOUI(char *value);
static TR_RET get_ProductClass(char **value);
static TR_RET set_ProductClass(char *value);
static TR_RET get_SerialNumber(char **value);
static TR_RET set_SerialNumber(char *value);



NODE _gatewayinfo[] = {
	{"ManufacturerOUI", get_ManufacturerOUI, set_ManufacturerOUI, NULL, NULL},
	{"ProductClass", get_ProductClass, set_ProductClass, NULL, NULL},
	{"SerialNumber", get_SerialNumber, set_SerialNumber, NULL, NULL},
	{NULL}
};

static TR_RET get_ManufacturerOUI(char **value)
{
	return TRDO_OK;
}

static TR_RET set_ManufacturerOUI(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_ProductClass(char **value)
{
	return TRDO_OK;
}

static TR_RET set_ProductClass(char *value)
{	
	return TRDO_OK;
}

static TR_RET get_SerialNumber(char **value)
{	
	return TRDO_OK;
}

static TR_RET set_SerialNumber(char *value)
{	
	return TRDO_OK;
}

