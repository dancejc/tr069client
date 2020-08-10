#include "cpedef.h"
#include "cpeutility.h"
#include "datamodel.h"



static TR_RET get_DiagnosticsState(char **value);
static TR_RET set_DiagnosticsState(char *value);
static TR_RET get_Host(char **value);
static TR_RET set_Host(char *value);
static TR_RET get_Timeout(char **value);
static TR_RET set_Timeout(char *value);
static TR_RET get_DataBlockSize(char **value);
static TR_RET set_DataBlockSize(char *value);
static TR_RET get_MaxHopCount(char **value);
static TR_RET set_MaxHopCount(char *value);
static TR_RET get_DSCP(char **value);
static TR_RET set_DSCP(char *value);
static TR_RET get_ResponseTime(char **value);
static TR_RET get_NumberOfRouteHops(char **value);
static TR_RET get_RouteHops(char **value);

NODE _traceroutediagnostics[] = {
	{"DiagnosticsState", get_DiagnosticsState, set_DiagnosticsState, NULL, NULL},
	{"Host", get_Host, set_Host, NULL, NULL},
	{"Timeout", get_Timeout, set_Timeout, NULL, NULL},
	{"DataBlockSize", get_DataBlockSize, set_DataBlockSize, NULL, NULL},
	{"MaxHopCount", get_MaxHopCount, set_MaxHopCount, NULL, NULL},
	{"DSCP", get_DSCP, set_DSCP, NULL, NULL},
	{"ResponseTime", get_ResponseTime, NULL, NULL, NULL},
	{"NumberOfRouteHops", get_NumberOfRouteHops, NULL, NULL, NULL},
	{"RouteHops", get_RouteHops, NULL, NULL, NULL},
	//Device.LAN.TraceRouteDiagnostics.RouteHops.{i}.
	//HopHost
	{NULL}
};

static TR_RET get_DiagnosticsState(char **value)
{
	*value = strdup(get_traceroutepara()->diagnosticstate);
	
	return TRDO_OK;
}

static TR_RET set_DiagnosticsState(char *value)
{
	strcpy(get_traceroutepara()->diagnosticstate, value);

	return TRDO_OK;
}

static TR_RET get_Host(char **value)
{
	*value = strdup(get_traceroutepara()->host);
	
	return TRDO_OK;
}

static TR_RET set_Host(char *value)
{
	strcpy(get_traceroutepara()->host, value);
	
	return TRDO_OK;
}

static TR_RET get_Timeout(char **value)
{
	char tempstr[32];

	sprintf(tempstr, "%d", get_traceroutepara()->timeout);
	*value = strdup(tempstr);
	
	return TRDO_OK;
}

static TR_RET set_Timeout(char *value)
{
	get_traceroutepara()->timeout = atoi(value);
	
	return TRDO_OK;
}

static TR_RET get_DataBlockSize(char **value)
{
	char tempstr[32];

	sprintf(tempstr, "%d", get_traceroutepara()->datablocksize);
	*value = strdup(tempstr);
	
	return TRDO_OK;
}

static TR_RET set_DataBlockSize(char *value)
{
	get_traceroutepara()->datablocksize = atoi(value);
	
	return TRDO_OK;
}

static TR_RET get_MaxHopCount(char **value)
{
	char tempstr[32];

	sprintf(tempstr, "%d", get_traceroutepara()->maxhopcount);
	*value = strdup(tempstr);
	
	return TRDO_OK;
}

static TR_RET set_MaxHopCount(char *value)
{
	get_traceroutepara()->maxhopcount = atoi(value);
	
	return TRDO_OK;
}

static TR_RET get_DSCP(char **value)
{
	char tempstr[32];

	sprintf(tempstr, "%d", get_traceroutepara()->dscp);
	*value = strdup(tempstr);
	
	return TRDO_OK;
}

static TR_RET set_DSCP(char *value)
{
	get_traceroutepara()->dscp = atoi(value);

	return TRDO_OK;
}

static TR_RET get_ResponseTime(char **value)
{
	char tempstr[32];

	sprintf(tempstr, "%d", get_traceroutepara()->responsetime);
	*value = strdup(tempstr);
	
	return TRDO_OK;
}

static TR_RET get_NumberOfRouteHops(char **value)
{
	char tempstr[32];

	sprintf(tempstr, "%d", get_traceroutepara()->numberofroutehops);
	*value = strdup(tempstr);
	
	return TRDO_OK;
}

static TR_RET get_RouteHops(char **value)
{
	return TRDO_OK;
}

