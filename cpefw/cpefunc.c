#include "stdsoap2.h"

#include "cpedef.h"
#include "cpefunc.h"
#include "cpeutility.h"
#include "cpe.h"
#include "datamodel.h"
#include "httpda.h"
#include "soapStub.h"

#define NECESSARY_INFORM_PARAMS 2


static void set_DeviceIdStruct(struct cwmp1__DeviceIdStruct * DeviceIdStruct)
{
	get_parameter("Device.DeviceInfo.Manufacturer", &DeviceIdStruct->Manufacturer);
	get_parameter("Device.DeviceInfo.ManufacturerOUI", &DeviceIdStruct->OUI);
	get_parameter("Device.DeviceInfo.ProductClass", &DeviceIdStruct->ProductClass);
	get_parameter("Device.DeviceInfo.SerialNumber", &DeviceIdStruct->SerialNumber);
	//DeviceIdStruct->Manufacturer = get_manufacturer();
	//DeviceIdStruct->OUI = get_OUI();
	//DeviceIdStruct->ProductClass = get_productclass();
	//DeviceIdStruct->SerialNumber = get_serialnumber();

	return;
}

static void free_DeviceIdStruct(struct cwmp1__DeviceIdStruct * DeviceIdStruct)
{
	free(DeviceIdStruct->Manufacturer);
	free(DeviceIdStruct->OUI);
	free(DeviceIdStruct->ProductClass);
	free(DeviceIdStruct->SerialNumber);

	return;
}

static void set_EventList(int type, struct cwmp1EventList * EventList)
{
	switch(type)
	{
		case IF_BOOTSTRAP :
			EventList->__size = 1;
			EventList->__ptrEventStruct[0]->EventCode = strdup("0 BOOTSTRAP");
			EventList->__ptrEventStruct[0]->CommandKey = strdup("");
			break;
		case IF_BOOT :
			EventList->__size = 1;
			EventList->__ptrEventStruct[0]->EventCode = strdup("1 BOOT");
			EventList->__ptrEventStruct[0]->CommandKey = strdup("");
			break;
		case IF_PERIODIC :
			EventList->__size = 1;
			EventList->__ptrEventStruct[0]->EventCode = strdup("2 PERIODIC");
			EventList->__ptrEventStruct[0]->CommandKey = strdup("");
			break;
		case IF_VALUECHANGE :
			EventList->__size = 1;
			EventList->__ptrEventStruct[0]->EventCode = strdup("4 VALUECHANGE");
			EventList->__ptrEventStruct[0]->CommandKey = strdup("");
			break;
		case IF_CONNECTIONREQUEST :
			EventList->__size = 1;
			EventList->__ptrEventStruct[0]->EventCode = strdup("6 CONNECTION REQUEST");
			EventList->__ptrEventStruct[0]->CommandKey = strdup("");
			break;
		case IF_MTRANSFERCOMPLETE :
			EventList->__size = 3;
			EventList->__ptrEventStruct[0]->EventCode = strdup("M TRANSFERCOMPLETE");
			EventList->__ptrEventStruct[0]->CommandKey = strdup("");
			EventList->__ptrEventStruct[1]->EventCode = strdup("1 BOOT");
			EventList->__ptrEventStruct[1]->CommandKey = strdup("");
			EventList->__ptrEventStruct[2]->EventCode = strdup("4 VALUECHANGE");
			EventList->__ptrEventStruct[2]->CommandKey = strdup("");
			break;
		case IF_DIAGNOSTIC :
			EventList->__size = 1;
			EventList->__ptrEventStruct[0]->EventCode = strdup("8 DIAGNOSTIC COMPLETE");
			EventList->__ptrEventStruct[0]->CommandKey = strdup("");
			break;
		case IF_MLOGPERIODIC :
			EventList->__size = 1;
			EventList->__ptrEventStruct[0]->EventCode = strdup("M CTC LOG_PERIODIC");
			EventList->__ptrEventStruct[0]->CommandKey = strdup("");
			break;
		case IF_X_CTC_SHUTDOWN :
			EventList->__size = 1;
			EventList->__ptrEventStruct[0]->EventCode = strdup("M X_CTC_SHUT_DOWN");
			EventList->__ptrEventStruct[0]->CommandKey = strdup("");
			break;
		case IF_MREBOOT :
			EventList->__size = 2;
			EventList->__ptrEventStruct[0]->EventCode = strdup("1 BOOT");
			EventList->__ptrEventStruct[0]->CommandKey = strdup("");
			EventList->__ptrEventStruct[1]->EventCode = strdup("M REBOOT");
			EventList->__ptrEventStruct[1]->CommandKey = strdup("");
			break;
		default:
			TR69CLOG(TR69C_INFO, "Unknown inform type : %d", type);
	}

	return;
}

static void free_EventList(struct cwmp1EventList * EventList)
{
	int i;

	for (i = 0; i < EventList->__size; i++)
	{
		free(EventList->__ptrEventStruct[i]->EventCode);
		free(EventList->__ptrEventStruct[i]->CommandKey);
	}

	return;
}

static void set_ParameterValueList(char * name, struct cwmp1ParameterValueList * ParameterValueList)
{
	int i;
	char * infind;
	char str[128];
	char * strtmp;
	
	ParameterValueList->__size = NECESSARY_INFORM_PARAMS;
	ParameterValueList->__ptrParameterValueStruct[0]->Name = strdup("Device.X_CTC_IPTV.STBID");
	get_parameter(ParameterValueList->__ptrParameterValueStruct[0]->Name, &ParameterValueList->__ptrParameterValueStruct[0]->Value);
	ParameterValueList->__ptrParameterValueStruct[1]->Name = strdup("Device.LAN.IPAddress");
	get_parameter(ParameterValueList->__ptrParameterValueStruct[1]->Name, &ParameterValueList->__ptrParameterValueStruct[1]->Value);
	i = 2;
	infind = name;
	while (*infind != '\0')
	{
		if(!strlen(infind))break;
		bzero(str, 128);
		sscanf(infind, "%[^,]", str);
		ParameterValueList->__ptrParameterValueStruct[i]->Name = strdup(str);
		get_parameter(ParameterValueList->__ptrParameterValueStruct[i]->Name, &ParameterValueList->__ptrParameterValueStruct[i]->Value);
		i++;
		ParameterValueList->__size++;
		strtmp = infind;
		if(!strlen(infind))
			break;
		infind = strstr(strtmp, ",") + 1;
	}
}

static void free_ParameterValueList(struct cwmp1ParameterValueList * ParameterValueList)
{
	int i;

	for(i = 0; i < ParameterValueList->__size; i++)
	{
		free(ParameterValueList->__ptrParameterValueStruct[i]->Name);
		free(ParameterValueList->__ptrParameterValueStruct[i]->Value);
	}
	
	return;
}

static int post_inform_request(struct soap * soap, struct cwmp1__DeviceIdStruct * DeviceIdStruct, struct cwmp1EventList * EventList, struct cwmp1ParameterValueList * ParameterValueList)
{
	struct _cwmp1__Inform inform;
	struct _cwmp1__InformResponse informresponse;

	inform.RetryCount = 0;
	inform.MaxEnvelopes = 1;
	inform.CurrentTime = time(NULL);
	inform.DeviceId = DeviceIdStruct;
	inform.Event = EventList;
	inform.ParameterList = ParameterValueList;	

	soap_call___cwmp1__Inform(soap, get_app()->acsurl, "", &inform, &informresponse);
	if (soap->error)
	{
#ifdef HTTP_DA
		if(soap->error == 401)
		{		
			DDS(soap->authrealm);
			//DDI("socket", soap->socket)
			if (!strcmp(soap->authrealm, "testrealm@host.com")) // determine authentication realm 
			{
				//struct http_da_info info; // to store userid and passwd
				//http_da_save(soap, &info, "testrealm@host.com", "aaa", "111"); // set userid and passwd for this realm
				http_da_save(soap, get_app()->httpda_info, "testrealm@host.com", "aaa", "111");
				soap_call___cwmp1__Inform(soap, get_app()->acsurl, "", &inform, &informresponse);
				soap_print_fault(soap, stderr);
				/*if (soap_call___cwmp1__Inform(soap, get_app()->acsurl, "", &inform, &informres) == SOAP_OK) // retry
				{
					DD
					//soap_end(soap); // userid and passwd were deallocated
					//http_da_restore(&soap, &info); // restore userid and passwd	
					//http_da_release(&soap, &info); // remove userid and passwd
				}*/
			}
		}
		else
		{
#endif
			soap_print_fault(soap, stderr);
#ifdef HTTP_DA
		}
#endif
	}
	else
		TR69CLOG(TR69C_INFO, "Send inform request succeeded.");

	if (soap->error)
		return -1;

	return soap->socket;
}

static int post_transfercomplete_request(struct soap *soap)
{
	struct _cwmp1__TransferComplete transfercomplete;
	struct _cwmp1__TransferCompleteResponse transfercompleteresponse;

	transfercomplete.CommandKey = "";
	transfercomplete.StartTime = time(NULL);//need to save
	transfercomplete.CompleteTime = time(NULL);
	transfercomplete.FaultStruct = NULL;
	
	soap_call___cwmp1__TransferComplete(soap, get_app()->acsurl, "", &transfercomplete, &transfercompleteresponse);

	if (soap->error)
		return -1;

	return soap->socket;
}

int send_inform(struct soap *soap, INFORMTYPE type, char *parameter)
{
	int i;
	int fd = 0;
	int ret = 0;

	TR69CLOG(TR69C_INFO, "Send inform request to %s, type = %d.", get_app()->acsurl, type);
	
	//set DeviceIdStruct
	//TR69CLOG(TR69C_INFO, "set DeviceIdStruct.");
	struct cwmp1__DeviceIdStruct DeviceIdStruct;
	set_DeviceIdStruct(&DeviceIdStruct);

	//set EventList
	//TR69CLOG(TR69C_INFO, "set EventList.");
	struct cwmp1EventList EventList;
	struct cwmp1__EventStruct EventStruct[64];
	struct cwmp1__EventStruct *pEventStruct[64];
	for(i = 0; i < 64; i++)
		pEventStruct[i] = &EventStruct[i];
	EventList.__ptrEventStruct = pEventStruct;
	set_EventList(type, &EventList);

	//set ParameterValueList
	//TR69CLOG(TR69C_INFO, "set ParameterValueList.");
	struct cwmp1ParameterValueList ParameterValueList;
	struct cwmp1__ParameterValueStruct ParameterValueStruct[128];
	struct cwmp1__ParameterValueStruct *pParameterValueStruct[128];
	for(i = 0; i < 128; i++)
		pParameterValueStruct[i] = &ParameterValueStruct[i];
	ParameterValueList.__ptrParameterValueStruct = pParameterValueStruct;
	set_ParameterValueList(parameter, &ParameterValueList);
	
	//post inform
	fd = post_inform_request(soap, &DeviceIdStruct, &EventList, &ParameterValueList);

	/*release the string memory!*/
	free_ParameterValueList(&ParameterValueList);
	free_EventList(&EventList);
	free_DeviceIdStruct(&DeviceIdStruct);
	
	if(fd > 0)
		send_empty(soap);

	return fd;
}

int send_transfercomplete(struct soap *soap)
{
	int fd = 0;

	TR69CLOG(TR69C_INFO, "Send transfercomplete request to %s.", get_app()->acsurl);
	
	fd = post_transfercomplete_request(soap);

	return fd;
}

int send_empty(struct soap *soap)
{
	//char emptystr[256] = {0};
	//char *emptystr = "POST /ACS-server/ACS HTTP/1.1\r\nHost: devacs.edatahome.com:9090\r\nUser-Agent: JZ TR69C/1.0\r\nContent-Type: text/xml; charset=\"utf-8\"\r\nConnection: Keep-Alive\r\nContent-Length: 0\r\nSOAPAction: ""\r\n\r\n";
	
	//struct http_da_info info; // to store userid and passwd
	//http_da_save(soap, &info, "testrealm@host.com", "aaa", "111"); // set userid and passwd for this realm
	
	//http_da_restore(soap, get_app()->httpda_info);
	int i = soap_send_empty_request(soap, get_app()->acsurl);
	
	return 0;
}

/*
ParameterValueStruct[index].Name = "Device.DeviceInfo.HardwareVersion";
get_parameter(ParameterValueStruct[index].Name, &value);
ParameterValueStruct[index++].Value = value;
ParameterValueStruct[index].Name = "Device.DeviceInfo.SoftwareVersion";
get_parameter(ParameterValueStruct[index].Name, &value);
ParameterValueStruct[index++].Value = value;
ParameterValueStruct[index].Name = "Device.ManagementServer.ConnectionRequestURL";
get_parameter(ParameterValueStruct[index].Name, &value);
ParameterValueStruct[index++].Value = value;
ParameterValueStruct[index].Name = "Device.LAN.MACAddress";
get_parameter(ParameterValueStruct[index].Name, &value);
ParameterValueStruct[index++].Value = value;*/

