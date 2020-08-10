#include "cpedef.h"
#include "cpeutility.h"
#include "datamodel.h"



static TR_RET get_DiagnosticsState(char **value);
static TR_RET set_DiagnosticsState(char *value);
static TR_RET get_Host(char **value);
static TR_RET set_Host(char *value);
static TR_RET get_NumberOfRepetitions(char **value);
static TR_RET set_NumberOfRepetitions(char *value);
static TR_RET get_Timeout(char **value);
static TR_RET set_Timeout(char *value);
static TR_RET get_DataBlockSize(char **value);
static TR_RET set_DataBlockSize(char *value);
static TR_RET get_DSCP(char **value);
static TR_RET set_DSCP(char *value);
static TR_RET get_SuccessCount(char **value);
static TR_RET get_FailureCount(char **value);
static TR_RET get_AverageResponseTime(char **value);
static TR_RET get_MinimumResponseTime(char **value);
static TR_RET get_MaximumResponseTime(char **value);

NODE _ippingdiagnostics[] = {
	{"DiagnosticsState", get_DiagnosticsState, set_DiagnosticsState, NULL, NULL},
	{"Host", get_Host, set_Host, NULL, NULL},
	{"NumberOfRepetitions", get_NumberOfRepetitions, set_NumberOfRepetitions, NULL, NULL},
	{"Timeout", get_Timeout, set_Timeout, NULL, NULL},
	{"DataBlockSize", get_DataBlockSize, set_DataBlockSize, NULL, NULL},
	{"DSCP", get_DSCP, set_DSCP, NULL, NULL},
	{"SuccessCount", get_SuccessCount, NULL, NULL, NULL},
	{"FailureCount", get_FailureCount, NULL, NULL, NULL},
	{"AverageResponseTime", get_AverageResponseTime, NULL, NULL, NULL},
	{"MinimumResponseTime", get_MinimumResponseTime, NULL, NULL, NULL},
	{"MaximumResponseTime", get_MaximumResponseTime, NULL, NULL, NULL},
	{NULL}
};

static TR_RET get_DiagnosticsState(char **value)
{
	*value = strdup(get_ippingpara()->diagnosticstate);
	
	return TRDO_OK;
}

static TR_RET set_DiagnosticsState(char *value)
{
	strcpy(get_ippingpara()->diagnosticstate, value);
	
	return TRDO_OK;
}

static TR_RET get_Host(char **value)
{
	*value = strdup(get_ippingpara()->host);
	
	return TRDO_OK;
}

static TR_RET set_Host(char *value)
{
	strcpy(get_ippingpara()->host, value);
	
	return TRDO_OK;
}

static TR_RET get_NumberOfRepetitions(char **value)
{
	char tempstr[32];
	
	sprintf(tempstr, "%d", get_ippingpara()->numberofrepetition);
	*value = strdup(tempstr);
	
	return TRDO_OK;
}

static TR_RET set_NumberOfRepetitions(char *value)
{
	get_ippingpara()->numberofrepetition = atoi(value);
	
	return TRDO_OK;
}

static TR_RET get_Timeout(char **value)
{
	char tempstr[32];

	sprintf(tempstr, "%d", get_ippingpara()->timeout);
	*value = strdup(tempstr);
	
	return TRDO_OK;
}

static TR_RET set_Timeout(char *value)
{
	get_ippingpara()->timeout = atoi(value);
	
	return TRDO_OK;
}

static TR_RET get_DataBlockSize(char **value)
{
	char tempstr[32];

	sprintf(tempstr, "%d", get_ippingpara()->datablocksize);
	*value = strdup(tempstr);
	
	return TRDO_OK;
}

static TR_RET set_DataBlockSize(char *value)
{
	get_ippingpara()->datablocksize = atoi(value);
	
	return TRDO_OK;
}

static TR_RET get_DSCP(char **value)
{
	char tempstr[32];

	sprintf(tempstr, "%d", get_ippingpara()->dscp);
	*value = strdup(tempstr);
	
	return TRDO_OK;
}

static TR_RET set_DSCP(char *value)
{
	get_ippingpara()->dscp = atoi(value);
	
	return TRDO_OK;
}

static TR_RET get_SuccessCount(char **value)
{
	char tempstr[32];

	sprintf(tempstr, "%d", get_ippingpara()->successcount);
	*value = strdup(tempstr);
	
	return TRDO_OK;
}

static TR_RET get_FailureCount(char **value)
{
	char tempstr[32];

	sprintf(tempstr, "%d", get_ippingpara()->failurecount);
	*value = strdup(tempstr);
	
	return TRDO_OK;
}

static TR_RET get_AverageResponseTime(char **value)
{
	char tempstr[32];

	sprintf(tempstr, "%d", get_ippingpara()->averageresponsetime);
	*value = strdup(tempstr);
	
	return TRDO_OK;
}

static TR_RET get_MinimumResponseTime(char **value)
{
	char tempstr[32];

	sprintf(tempstr, "%d", get_ippingpara()->minimumresponsetime);
	*value = strdup(tempstr);
	
	return TRDO_OK;
}

static TR_RET get_MaximumResponseTime(char **value)
{
	char tempstr[32];

	sprintf(tempstr, "%d", get_ippingpara()->maximumresponsetime);
	*value = strdup(tempstr);
	
	return TRDO_OK;
}

