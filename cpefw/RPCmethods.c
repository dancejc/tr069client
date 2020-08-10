#include "RPCmethods.h"
#include "soapH.h"

#include "cpe.h"
#include "datamodel.h"

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__GetRPCMethods(struct soap *soap, struct _cwmp1__GetRPCMethods *cwmp1__GetRPCMethods, struct _cwmp1__GetRPCMethodsResponse *cwmp1__GetRPCMethodsResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__SetParameterValues(struct soap *soap, struct _cwmp1__SetParameterValues *cwmp1__SetParameterValues, struct _cwmp1__SetParameterValuesResponse *cwmp1__SetParameterValuesResponse)
{
	TR69CLOG(TR69C_INFO, "received call SetParameterValues RPC method.");
	
	http_da_restore(soap, get_app()->httpda_info);
	int i = 0;
	for(; i < cwmp1__SetParameterValues->ParameterList->__size; i++)
	{
		set_parameter(cwmp1__SetParameterValues->ParameterList->__ptrParameterValueStruct[i]->Name ,cwmp1__SetParameterValues->ParameterList->__ptrParameterValueStruct[i]->Value);
		//printf("The %d parameter name: %s\n", i+1, cwmp1__SetParameterValues->ParameterList->__ptrParameterValueStruct[i]->Name);
		//printf("The %d parameter value: %s\n", i+1, cwmp1__SetParameterValues->ParameterList->__ptrParameterValueStruct[i]->Value);
	}
	
	/*if(get_app()->pingstat->pingstate == PING_DO)
	{
		TR69CLOG(TR69C_INFO, "Begin ping test.");
		do_ping();
	}*/
	
	//need reboot. so return 1
	//cwmp1__SetParameterValuesResponse->Status = _cwmp1__SetParameterValuesResponse_Status__1;
	//soap->plugins = NULL;
	cwmp1__SetParameterValuesResponse->Status = _cwmp1__SetParameterValuesResponse_Status__0;
	
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__GetParameterValues(struct soap *soap, struct _cwmp1__GetParameterValues *cwmp1__GetParameterValues, struct _cwmp1__GetParameterValuesResponse *cwmp1__GetParameterValuesResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__GetParameterNames(struct soap *soap, struct _cwmp1__GetParameterNames *cwmp1__GetParameterNames, struct _cwmp1__GetParameterNamesResponse *cwmp1__GetParameterNamesResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__SetParameterAttributes(struct soap *soap, struct _cwmp1__SetParameterAttributes *cwmp1__SetParameterAttributes, struct _cwmp1__SetParameterAttributesResponse *cwmp1__SetParameterAttributesResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__GetParameterAttributes(struct soap *soap, struct _cwmp1__GetParameterAttributes *cwmp1__GetParameterAttributes, struct _cwmp1__GetParameterAttributesResponse *cwmp1__GetParameterAttributesResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__AddObject(struct soap *soap, struct _cwmp1__AddObject *cwmp1__AddObject, struct _cwmp1__AddObjectResponse *cwmp1__AddObjectResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__DeleteObject(struct soap *soap, struct _cwmp1__DeleteObject *cwmp1__DeleteObject, struct _cwmp1__DeleteObjectResponse *cwmp1__DeleteObjectResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__Download(struct soap *soap, struct _cwmp1__Download *cwmp1__Download, struct _cwmp1__DownloadResponse *cwmp1__DownloadResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__Reboot(struct soap *soap, struct _cwmp1__Reboot *cwmp1__Reboot, struct _cwmp1__RebootResponse *cwmp1__RebootResponse)
{
	TR69CLOG(TR69C_INFO, "received call Reboot RPC method.");
	
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__GetQueuedTransfers(struct soap *soap, struct _cwmp1__GetQueuedTransfers *cwmp1__GetQueuedTransfers, struct _cwmp1__GetQueuedTransfersResponse *cwmp1__GetQueuedTransfersResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__ScheduleInform(struct soap *soap, struct _cwmp1__ScheduleInform *cwmp1__ScheduleInform, struct _cwmp1__ScheduleInformResponse *cwmp1__ScheduleInformResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__SetVouchers(struct soap *soap, struct _cwmp1__SetVouchers *cwmp1__SetVouchers, struct _cwmp1__SetVouchersResponse *cwmp1__SetVouchersResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__GetOptions(struct soap *soap, struct _cwmp1__GetOptions *cwmp1__GetOptions, struct _cwmp1__GetOptionsResponse *cwmp1__GetOptionsResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__Upload(struct soap *soap, struct _cwmp1__Upload *cwmp1__Upload, struct _cwmp1__UploadResponse *cwmp1__UploadResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__FactoryReset(struct soap *soap, struct _cwmp1__FactoryReset *cwmp1__FactoryReset, struct _cwmp1__FactoryResetResponse *cwmp1__FactoryResetResponse)
{
	return SOAP_OK;
}

#ifdef TR069V11
SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__GetAllQueuedTransfers(struct soap *soap, struct _cwmp1__GetAllQueuedTransfers *cwmp1__GetAllQueuedTransfers, struct _cwmp1__GetAllQueuedTransfersResponse *cwmp1__GetAllQueuedTransfersResponse)
{
	return SOAP_OK;
}
#endif

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__Inform(struct soap *soap, struct _cwmp1__Inform *cwmp1__Inform, struct _cwmp1__InformResponse *cwmp1__InformResponse)
{
	TR69CLOG(TR69C_INFO, "received call INFORM RPC method.");
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__TransferComplete(struct soap *soap, struct _cwmp1__TransferComplete *cwmp1__TransferComplete, struct _cwmp1__TransferCompleteResponse *cwmp1__TransferCompleteResponse)
{
	return SOAP_OK;
}

#ifdef TR069V11
SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__AutonomousTransferComplete(struct soap *soap, struct _cwmp1__AutonomousTransferComplete *cwmp1__AutonomousTransferComplete, struct _cwmp1__AutonomousTransferCompleteResponse *cwmp1__AutonomousTransferCompleteResponse)
{
	return SOAP_OK;
}
#endif

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__Kicked(struct soap *soap, struct _cwmp1__Kicked *cwmp1__Kicked, struct _cwmp1__KickedResponse *cwmp1__KickedResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__RequestDownload(struct soap *soap, struct _cwmp1__RequestDownload *cwmp1__RequestDownload, struct _cwmp1__RequestDownloadResponse *cwmp1__RequestDownloadResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__Fault(struct soap *soap, struct _cwmp1__Fault *cwmp1__Fault)
{
	return SOAP_OK;
}

//for cwmp1.1
/*SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__GetAllQueuedTransfers(struct soap *soap, struct _cwmp1__GetAllQueuedTransfers *cwmp1__GetAllQueuedTransfers, struct _cwmp1__GetAllQueuedTransfersResponse *cwmp1__GetAllQueuedTransfersResponse)
{
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __cwmp1__AutonomousTransferComplete(struct soap *soap, struct _cwmp1__AutonomousTransferComplete *cwmp1__AutonomousTransferComplete, struct _cwmp1__AutonomousTransferCompleteResponse *cwmp1__AutonomousTransferCompleteResponse)
{
	return SOAP_OK;
}*/
//for cwmp1.1
