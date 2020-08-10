#include "cpedef.h"
#include "datamodel.h"



static TR_RET get_Startpoint(char **value);
static TR_RET get_Endpoint(char **value);
static TR_RET get_AuthNumbers(char **value);
static TR_RET get_AuthFailNumbers(char **value);
static TR_RET get_AuthFailInfo(char **value);
static TR_RET get_MultiReqNumbers(char **value);
static TR_RET get_MultiRRT(char **value);
static TR_RET get_MultiFailNumbers(char **value);
static TR_RET get_MultiFailInfo(char **value);
static TR_RET get_VodReqNumbers(char **value);
static TR_RET get_VodRRT(char **value);
static TR_RET get_VodFailNumbers(char **value);
static TR_RET get_VodFailInfo(char **value);
static TR_RET get_HTTPReqNumbers(char **value);
static TR_RET get_HTTPRRT(char **value);
static TR_RET get_HTTPFailNumbers(char **value);
static TR_RET get_HTTPFailInfo(char **value);
static TR_RET get_MultiAbendNumbers(char **value);
static TR_RET get_VODAbendNumbers(char **value);
static TR_RET get_MultiAbendUPNumbers(char **value);
static TR_RET get_VODAbendUPNumbers(char **value);
static TR_RET get_HD_MultiAbendNumbers(char **value);
static TR_RET get_HD_VODAbendNumbers(char **value);
static TR_RET get_HD_MultiUPAbendNumbers(char **value);
static TR_RET get_HD_VODUPAbendNumbers(char **value);
static TR_RET get_PlayErrorNumbers(char **value);
static TR_RET get_PlayErrorInfo(char **value);
static TR_RET get_MultiPacketsLostR1Nmb(char **value);
static TR_RET get_MultiPacketsLostR2Nmb(char **value);
static TR_RET get_MultiPacketsLostR3Nmb(char **value);
static TR_RET get_MultiPacketsLostR4Nmb(char **value);
static TR_RET get_MultiPacketsLostR5Nmb(char **value);
static TR_RET get_FECMultiPacketsLostR1Nmb(char **value);
static TR_RET get_FECMultiPacketsLostR2Nmb(char **value);
static TR_RET get_FECMultiPacketsLostR3Nmb(char **value);
static TR_RET get_FECMultiPacketsLostR4Nmb(char **value);
static TR_RET get_FECMultiPacketsLostR5Nmb(char **value);
static TR_RET get_VODPacketsLostR1Nmb(char **value);
static TR_RET get_VODPacketsLostR2Nmb(char **value);
static TR_RET get_VODPacketsLostR3Nmb(char **value);
static TR_RET get_VODPacketsLostR4Nmb(char **value);
static TR_RET get_VODPacketsLostR5Nmb(char **value);
static TR_RET get_ARQVODPacketsLostR1Nmb(char **value);
static TR_RET get_ARQVODPacketsLostR2Nmb(char **value);
static TR_RET get_ARQVODPacketsLostR3Nmb(char **value);
static TR_RET get_ARQVODPacketsLostR4Nmb(char **value);
static TR_RET get_ARQVODPacketsLostR5Nmb(char **value);
static TR_RET get_MultiBitRateR1Nmb(char **value);
static TR_RET get_MultiBitRateR2Nmb(char **value);
static TR_RET get_MultiBitRateR3Nmb(char **value);
static TR_RET get_MultiBitRateR4Nmb(char **value);
static TR_RET get_MultiBitRateR5Nmb(char **value);
static TR_RET get_VODBitRateR1Nmb(char **value);
static TR_RET get_VODBitRateR2Nmb(char **value);
static TR_RET get_VODBitRateR3Nmb(char **value);
static TR_RET get_VODBitRateR4Nmb(char **value);
static TR_RET get_VODBitRateR5Nmb(char **value);
static TR_RET get_HD_MultiPacketsLostR1Nmb(char **value);
static TR_RET get_HD_MultiPacketsLostR2Nmb(char **value);
static TR_RET get_HD_MultiPacketsLostR3Nmb(char **value);
static TR_RET get_HD_MultiPacketsLostR4Nmb(char **value);
static TR_RET get_HD_MultiPacketsLostR5Nmb(char **value);
static TR_RET get_HD_FECMultiPacketsLostR1Nmb(char **value);
static TR_RET get_HD_FECMultiPacketsLostR2Nmb(char **value);
static TR_RET get_HD_FECMultiPacketsLostR3Nmb(char **value);
static TR_RET get_HD_FECMultiPacketsLostR4Nmb(char **value);
static TR_RET get_HD_FECMultiPacketsLostR5Nmb(char **value);
static TR_RET get_HD_VODPacketsLostR1Nmb(char **value);
static TR_RET get_HD_VODPacketsLostR2Nmb(char **value);
static TR_RET get_HD_VODPacketsLostR3Nmb(char **value);
static TR_RET get_HD_VODPacketsLostR4Nmb(char **value);
static TR_RET get_HD_VODPacketsLostR5Nmb(char **value);
static TR_RET get_BufferIncNmb(char **value);
static TR_RET get_BufferDecNmb(char **value);
static TR_RET get_FramesLostR1Nmb(char **value);
static TR_RET get_FramesLostR2Nmb(char **value);
static TR_RET get_FramesLostR3Nmb(char **value);
static TR_RET get_FramesLostR4Nmb(char **value);
static TR_RET get_FramesLostR5Nmb(char **value);

NODE _servicestatistics[] = {
	{"Startpoint", get_Startpoint, NULL, NULL, NULL},
	{"Endpoint", get_Endpoint, NULL, NULL, NULL},
	{"AuthNumbers", get_AuthNumbers, NULL, NULL, NULL},
	{"AuthFailNumbers", get_AuthFailNumbers, NULL, NULL, NULL},
	{"AuthFailInfo", get_AuthFailInfo, NULL, NULL, NULL},
	{"MultiReqNumbers", get_MultiReqNumbers, NULL, NULL, NULL},
	{"MultiRRT", get_MultiRRT, NULL, NULL, NULL},
	{"MultiFailNumbers", get_MultiFailNumbers, NULL, NULL, NULL},
	{"MultiFailInfo", get_MultiFailInfo, NULL, NULL, NULL},
	{"VodReqNumbers", get_VodReqNumbers, NULL, NULL, NULL},
	{"VodRRT", get_VodRRT, NULL, NULL, NULL},
	{"VodFailNumbers", get_VodFailNumbers, NULL, NULL, NULL},
	{"VodFailInfo", get_VodFailInfo, NULL, NULL, NULL},
	{"HTTPReqNumbers", get_HTTPReqNumbers, NULL, NULL, NULL},
	{"HTTPRRT", get_HTTPRRT, NULL, NULL, NULL},
	{"HTTPFailNumbers", get_HTTPFailNumbers, NULL, NULL, NULL},
	{"HTTPFailInfo", get_HTTPFailInfo, NULL, NULL, NULL},
	{"MultiAbendNumbers", get_MultiAbendNumbers, NULL, NULL, NULL},
	{"VODAbendNumbers", get_VODAbendNumbers, NULL, NULL, NULL},
	{"MultiAbendUPNumbers", get_MultiAbendUPNumbers, NULL, NULL, NULL},
	{"VODAbendUPNumbers", get_VODAbendUPNumbers, NULL, NULL, NULL},
	{"HD_MultiAbendNumbers", get_HD_MultiAbendNumbers, NULL, NULL, NULL},
	{"HD_VODAbendNumbers", get_HD_VODAbendNumbers, NULL, NULL, NULL},
	{"HD_MultiUPAbendNumbers", get_HD_MultiUPAbendNumbers, NULL, NULL, NULL},
	{"HD_VODUPAbendNumbers", get_HD_VODUPAbendNumbers, NULL, NULL, NULL},
	{"PlayErrorNumbers", get_PlayErrorNumbers, NULL, NULL, NULL},
	{"PlayErrorInfo", get_PlayErrorInfo, NULL, NULL, NULL},
	{"MultiPacketsLostR1Nmb", get_MultiPacketsLostR1Nmb, NULL, NULL, NULL},
	{"MultiPacketsLostR2Nmb", get_MultiPacketsLostR2Nmb, NULL, NULL, NULL},
	{"MultiPacketsLostR3Nmb", get_MultiPacketsLostR3Nmb, NULL, NULL, NULL},
	{"MultiPacketsLostR4Nmb", get_MultiPacketsLostR4Nmb, NULL, NULL, NULL},
	{"MultiPacketsLostR5Nmb", get_MultiPacketsLostR5Nmb, NULL, NULL, NULL},
	{"FECMultiPacketsLostR1Nmb", get_FECMultiPacketsLostR1Nmb, NULL, NULL, NULL},
	{"FECMultiPacketsLostR2Nmb", get_FECMultiPacketsLostR2Nmb, NULL, NULL, NULL},
	{"FECMultiPacketsLostR3Nmb", get_FECMultiPacketsLostR3Nmb, NULL, NULL, NULL},
	{"FECMultiPacketsLostR4Nmb", get_FECMultiPacketsLostR4Nmb, NULL, NULL, NULL},
	{"FECMultiPacketsLostR5Nmb", get_FECMultiPacketsLostR5Nmb, NULL, NULL, NULL},
	{"VODPacketsLostR1Nmb", get_VODPacketsLostR1Nmb, NULL, NULL, NULL},
	{"VODPacketsLostR2Nmb", get_VODPacketsLostR2Nmb, NULL, NULL, NULL},
	{"VODPacketsLostR3Nmb", get_VODPacketsLostR3Nmb, NULL, NULL, NULL},
	{"VODPacketsLostR4Nmb", get_VODPacketsLostR4Nmb, NULL, NULL, NULL},
	{"VODPacketsLostR5Nmb", get_VODPacketsLostR5Nmb, NULL, NULL, NULL},
	{"ARQVODPacketsLostR1Nmb", get_ARQVODPacketsLostR1Nmb, NULL, NULL, NULL},
	{"ARQVODPacketsLostR2Nmb", get_ARQVODPacketsLostR2Nmb, NULL, NULL, NULL},
	{"ARQVODPacketsLostR3Nmb", get_ARQVODPacketsLostR3Nmb, NULL, NULL, NULL},
	{"ARQVODPacketsLostR4Nmb", get_ARQVODPacketsLostR4Nmb, NULL, NULL, NULL},
	{"ARQVODPacketsLostR5Nmb", get_ARQVODPacketsLostR5Nmb, NULL, NULL, NULL},
	{"MultiBitRateR1Nmb", get_MultiBitRateR1Nmb, NULL, NULL, NULL},
	{"MultiBitRateR2Nmb", get_MultiBitRateR2Nmb, NULL, NULL, NULL},
	{"MultiBitRateR3Nmb", get_MultiBitRateR3Nmb, NULL, NULL, NULL},
	{"MultiBitRateR4Nmb", get_MultiBitRateR4Nmb, NULL, NULL, NULL},
	{"MultiBitRateR5Nmb", get_MultiBitRateR5Nmb, NULL, NULL, NULL},
	{"VODBitRateR1Nmb", get_VODBitRateR1Nmb, NULL, NULL, NULL},
	{"VODBitRateR2Nmb", get_VODBitRateR2Nmb, NULL, NULL, NULL},
	{"VODBitRateR3Nmb", get_VODBitRateR3Nmb, NULL, NULL, NULL},
	{"VODBitRateR4Nmb", get_VODBitRateR4Nmb, NULL, NULL, NULL},
	{"VODBitRateR5Nmb", get_VODBitRateR5Nmb, NULL, NULL, NULL},
	{"HD_MultiPacketsLostR1Nmb", get_HD_MultiPacketsLostR1Nmb, NULL, NULL, NULL},
	{"HD_MultiPacketsLostR2Nmb", get_HD_MultiPacketsLostR2Nmb, NULL, NULL, NULL},
	{"HD_MultiPacketsLostR3Nmb", get_HD_MultiPacketsLostR3Nmb, NULL, NULL, NULL},
	{"HD_MultiPacketsLostR4Nmb", get_HD_MultiPacketsLostR4Nmb, NULL, NULL, NULL},
	{"HD_MultiPacketsLostR5Nmb", get_HD_MultiPacketsLostR5Nmb, NULL, NULL, NULL},
	{"HD_FECMultiPacketsLostR1Nmb", get_HD_FECMultiPacketsLostR1Nmb, NULL, NULL, NULL},
	{"HD_FECMultiPacketsLostR2Nmb", get_HD_FECMultiPacketsLostR2Nmb, NULL, NULL, NULL},
	{"HD_FECMultiPacketsLostR3Nmb", get_HD_FECMultiPacketsLostR3Nmb, NULL, NULL, NULL},
	{"HD_FECMultiPacketsLostR4Nmb", get_HD_FECMultiPacketsLostR4Nmb, NULL, NULL, NULL},
	{"HD_FECMultiPacketsLostR5Nmb", get_HD_FECMultiPacketsLostR5Nmb, NULL, NULL, NULL},
	{"HD_VODPacketsLostR1Nmb", get_HD_VODPacketsLostR1Nmb, NULL, NULL, NULL},
	{"HD_VODPacketsLostR2Nmb", get_HD_VODPacketsLostR2Nmb, NULL, NULL, NULL},
	{"HD_VODPacketsLostR3Nmb", get_HD_VODPacketsLostR3Nmb, NULL, NULL, NULL},
	{"HD_VODPacketsLostR4Nmb", get_HD_VODPacketsLostR4Nmb, NULL, NULL, NULL},
	{"HD_VODPacketsLostR5Nmb", get_HD_VODPacketsLostR5Nmb, NULL, NULL, NULL},
	{"BufferIncNmb", get_BufferIncNmb, NULL, NULL, NULL},
	{"BufferDecNmb", get_BufferDecNmb, NULL, NULL, NULL},
	{"FramesLostR1Nmb", get_FramesLostR1Nmb, NULL, NULL, NULL},
	{"FramesLostR2Nmb", get_FramesLostR2Nmb, NULL, NULL, NULL},
	{"FramesLostR3Nmb", get_FramesLostR3Nmb, NULL, NULL, NULL},
	{"FramesLostR4Nmb", get_FramesLostR4Nmb, NULL, NULL, NULL},
	{"FramesLostR5Nmb", get_FramesLostR5Nmb, NULL, NULL, NULL},
	{NULL}
};

static TR_RET get_Startpoint(char **value)
{
	return TRDO_OK;
}

static TR_RET get_Endpoint(char **value)
{
	return TRDO_OK;
}

static TR_RET get_AuthNumbers(char **value)
{
	return TRDO_OK;
}

static TR_RET get_AuthFailNumbers(char **value)
{
	return TRDO_OK;
}

static TR_RET get_AuthFailInfo(char **value)
{
	return TRDO_OK;
}

static TR_RET get_MultiReqNumbers(char **value)
{
	return TRDO_OK;
}

static TR_RET get_MultiRRT(char **value)
{
	return TRDO_OK;
}

static TR_RET get_MultiFailNumbers(char **value)
{
	return TRDO_OK;
}

static TR_RET get_MultiFailInfo(char **value)
{
	return TRDO_OK;
}

static TR_RET get_VodReqNumbers(char **value)
{
	return TRDO_OK;
}

static TR_RET get_VodRRT(char **value)
{
	return TRDO_OK;
}

static TR_RET get_VodFailNumbers(char **value)
{
	return TRDO_OK;
}

static TR_RET get_VodFailInfo(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HTTPReqNumbers(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HTTPRRT(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HTTPFailNumbers(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HTTPFailInfo(char **value)
{
	return TRDO_OK;
}

static TR_RET get_MultiAbendNumbers(char **value)
{
	return TRDO_OK;
}

static TR_RET get_VODAbendNumbers(char **value)
{
	return TRDO_OK;
}

static TR_RET get_MultiAbendUPNumbers(char **value)
{
	return TRDO_OK;
}

static TR_RET get_VODAbendUPNumbers(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HD_MultiAbendNumbers(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HD_VODAbendNumbers(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HD_MultiUPAbendNumbers(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HD_VODUPAbendNumbers(char **value)
{
	return TRDO_OK;
}

static TR_RET get_PlayErrorNumbers(char **value)
{
	return TRDO_OK;
}

static TR_RET get_PlayErrorInfo(char **value)
{
	return TRDO_OK;
}

static TR_RET get_MultiPacketsLostR1Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_MultiPacketsLostR2Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_MultiPacketsLostR3Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_MultiPacketsLostR4Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_MultiPacketsLostR5Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_FECMultiPacketsLostR1Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_FECMultiPacketsLostR2Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_FECMultiPacketsLostR3Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_FECMultiPacketsLostR4Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_FECMultiPacketsLostR5Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_VODPacketsLostR1Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_VODPacketsLostR2Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_VODPacketsLostR3Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_VODPacketsLostR4Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_VODPacketsLostR5Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_ARQVODPacketsLostR1Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_ARQVODPacketsLostR2Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_ARQVODPacketsLostR3Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_ARQVODPacketsLostR4Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_ARQVODPacketsLostR5Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_MultiBitRateR1Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_MultiBitRateR2Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_MultiBitRateR3Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_MultiBitRateR4Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_MultiBitRateR5Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_VODBitRateR1Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_VODBitRateR2Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_VODBitRateR3Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_VODBitRateR4Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_VODBitRateR5Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HD_MultiPacketsLostR1Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HD_MultiPacketsLostR2Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HD_MultiPacketsLostR3Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HD_MultiPacketsLostR4Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HD_MultiPacketsLostR5Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HD_FECMultiPacketsLostR1Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HD_FECMultiPacketsLostR2Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HD_FECMultiPacketsLostR3Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HD_FECMultiPacketsLostR4Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HD_FECMultiPacketsLostR5Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HD_VODPacketsLostR1Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HD_VODPacketsLostR2Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HD_VODPacketsLostR3Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HD_VODPacketsLostR4Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_HD_VODPacketsLostR5Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_BufferIncNmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_BufferDecNmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_FramesLostR1Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_FramesLostR2Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_FramesLostR3Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_FramesLostR4Nmb(char **value)
{
	return TRDO_OK;
}

static TR_RET get_FramesLostR5Nmb(char **value)
{
	return TRDO_OK;
}

