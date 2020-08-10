#include "cpedef.h"
#include "datamodel.h"



static TR_RET get_BACDomainName(char **value);
static TR_RET set_BACDomainName(char *value);
static TR_RET get_BACAddress1(char **value);
static TR_RET set_BACAddress1(char *value);
static TR_RET get_BACAddress2(char **value);
static TR_RET set_BACAddress2(char *value);
static TR_RET get_UserID(char **value);
static TR_RET set_UserID(char *value);
static TR_RET get_Password(char **value);
static TR_RET set_Password(char *value);

NODE _imsinfo[] = {
	{"BACDomainName", get_BACDomainName, set_BACDomainName, NULL, NULL},
	{"BACAddress1", get_BACAddress1, set_BACAddress1, NULL, NULL},
	{"BACAddress2", get_BACAddress2, set_BACAddress2, NULL, NULL},
	{"UserID", get_UserID, set_UserID, NULL, NULL},
	{"Password", get_Password, set_Password, NULL, NULL},
	{NULL}
};

static TR_RET get_BACDomainName(char **value)
{
	return TRDO_OK;
}

static TR_RET set_BACDomainName(char *value)
{
	return TRDO_OK;
}

static TR_RET get_BACAddress1(char **value)
{
	return TRDO_OK;
}

static TR_RET set_BACAddress1(char *value)
{
	return TRDO_OK;
}

static TR_RET get_BACAddress2(char **value)
{
	return TRDO_OK;
}

static TR_RET set_BACAddress2(char *value)
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

