#include <string.h>
#include "cpedef.h"
#include "datamodel.h"



TR_RET get_StreamingControlProtocols(char **value);
TR_RET get_StreamingTransportProtocols(char **value);
TR_RET get_StreamingTransportControlProtocols(char **value);
TR_RET get_DownloadTransportProtocols(char **value);
TR_RET get_MultiplexType(char **value);
TR_RET get_MaxDejitteringBufferSize(char **value);
TR_RET get_AudioStandards(char **value);
TR_RET get_VideoStandards(char **value);



NODE _stbservice[] = {
	{"StreamingControlProtocols", get_StreamingControlProtocols, NULL, NULL, NULL},
	{"StreamingTransportProtocols", get_StreamingTransportProtocols, NULL, NULL, NULL},
	{"StreamingTransportControlProtocols", get_StreamingTransportControlProtocols, NULL, NULL, NULL},
	{"DownloadTransportProtocols", get_DownloadTransportProtocols, NULL, NULL, NULL},
	{"MultiplexType", get_MultiplexType, NULL, NULL, NULL},
	{"MaxDejitteringBufferSize", get_MaxDejitteringBufferSize, NULL, NULL, NULL},
	{"AudioStandards", get_AudioStandards, NULL, NULL, NULL},
	{"VideoStandards", get_VideoStandards, NULL, NULL, NULL},
	{NULL}
};

TR_RET get_StreamingControlProtocols(char **value)
{
	*value=strdup("RTSP,IGMPv2");

	return TRDO_OK;
}

TR_RET get_StreamingTransportProtocols(char **value)
{
	*value=strdup("UDP,TCP,RTP");

	return TRDO_OK;
}

TR_RET get_StreamingTransportControlProtocols(char **value)
{
	*value=strdup("RTCP");

	return TRDO_OK;
}

TR_RET get_DownloadTransportProtocols(char **value)
{
	*value=strdup("HTTP,HTTPS,FTP,FTPS,TFTP");

	return TRDO_OK;
}

TR_RET get_MultiplexType(char **value)
{
	*value=strdup("MPEG1-SYS,MPEG2-PS,VOB,MPEG2-TS");

	return TRDO_OK;
}

TR_RET get_MaxDejitteringBufferSize(char **value)
{
	*value=strdup("-1");

	return TRDO_OK;
}

TR_RET get_AudioStandards(char **value)
{
	*value=strdup("MPEG1-Part2-Layer2,MPEG1-Part2-Layer3,MPEG2-Part3-Layer2,MPEG2-Part3-Layer3,MP3-Surround,DOLBY-AC3");

	return TRDO_OK;
}

TR_RET get_VideoStandards(char **value)
{
	*value=strdup("MPEG2-Part2,H.264");

	return TRDO_OK;
}

