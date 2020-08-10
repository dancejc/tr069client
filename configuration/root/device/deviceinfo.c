#include "cpedef.h"
#include "datamodel.h"



static TR_RET get_Manufacturer(char **value);
static TR_RET get_ManufacturerOUI(char **value);
static TR_RET get_ModeName(char **value);
static TR_RET get_ModeID(char **value);
static TR_RET get_Description(char **value);
static TR_RET get_ProductClass(char **value);
static TR_RET get_SerialNumber(char **value);
static TR_RET get_HardwareVersion(char **value);
static TR_RET get_SoftwareVersion(char **value);
static TR_RET get_ConfigFileVersion(char **value);
static TR_RET get_EnabledOptions(char **value);
static TR_RET get_AdditionalHardwareVersion(char **value);
static TR_RET get_AdditionalSoftwareVersion(char **value);
static TR_RET get_ProvisioningCode(char **value);
static TR_RET set_ProvisioningCode(char *value);
static TR_RET get_DeviceStatus(char **value);
static TR_RET get_UpTime(char **value);
static TR_RET get_FirstUseDate(char **value);
static TR_RET get_DeviceLog(char **value);



NODE _deviceInfo[] = {
	{"Manufacturer", get_Manufacturer, NULL, NULL, NULL},
	{"ManufacturerOUI", get_ManufacturerOUI, NULL, NULL, NULL},
	{"ModeName", get_ModeName, NULL, NULL, NULL},
	{"ModeID", get_ModeID, NULL, NULL, NULL},
	{"Description", get_Description, NULL, NULL, NULL},
	{"ProductClass", get_ProductClass, NULL, NULL, NULL},
	{"SerialNumber", get_SerialNumber, NULL, NULL, NULL},
	{"HardwareVersion", get_HardwareVersion, NULL, NULL, NULL},
	{"SoftwareVersion", get_SoftwareVersion, NULL, NULL, NULL},
	{"ConfigFileVersion", get_ConfigFileVersion, NULL, NULL, NULL},
	{"EnabledOptions", get_EnabledOptions, NULL, NULL, NULL},
	{"AdditionalHardwareVersion", get_AdditionalHardwareVersion, NULL, NULL, NULL},
	{"AdditionalSoftwareVersion", get_AdditionalSoftwareVersion, NULL, NULL, NULL},
	{"ProvisioningCode", get_ProvisioningCode, set_ProvisioningCode, NULL, NULL},
	{"DeviceStatus", get_DeviceStatus, NULL, NULL, NULL},
	{"UpTime", get_UpTime, NULL, NULL, NULL},
	{"FirstUseDate", get_FirstUseDate, NULL, NULL, NULL},
	{"DeviceLog", get_DeviceLog, NULL, NULL, NULL},
	{NULL}
};

static TR_RET get_Manufacturer(char **value)
{
	*value = strdup("JIUZHOU");
	return TRDO_OK;
}

static TR_RET get_ManufacturerOUI(char **value)
{
	*value = strdup("990102");
	
	return TRDO_OK;
}

static TR_RET get_ModeName(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET get_ModeID(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET get_Description(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET get_ProductClass(char **value)
{
	*value = strdup("JIUZHOUV10");
	
	return TRDO_OK;
}

static TR_RET get_SerialNumber(char **value)
{
	*value = strdup("00100199010211400000D0154AD4934C");
	
	return TRDO_OK;
}

static TR_RET get_HardwareVersion(char **value)
{

	return TRDO_OK;
}

static TR_RET get_SoftwareVersion(char **value)
{


	return TRDO_OK;
}

static TR_RET get_ConfigFileVersion(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET get_EnabledOptions(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET get_AdditionalHardwareVersion(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET get_AdditionalSoftwareVersion(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET get_ProvisioningCode(char **value)
{
	*value =strdup("Sichun Jiuzhou");
	
	return TRDO_OK;
}

static TR_RET set_ProvisioningCode(char *value)
{
	return TRDO_OK;
}

static TR_RET get_DeviceStatus(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET get_UpTime(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET get_FirstUseDate(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

static TR_RET get_DeviceLog(char **value)
{
	*value = strdup("");
	
	return TRDO_OK;
}

