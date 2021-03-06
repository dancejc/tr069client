#default for ST architecture
ifndef ARCH
ARCH=x86
endif

GCC_CROSS_PREFIX=
$(warning ARCH=$(ARCH))
ifeq ($(ARCH), sh)
GCC_CROSS_PREFIX=sh4-linux-
CC=sh4-linux-gcc
CXX=sh4-linux-g++
CC_PLUS=sh4-linux-g++
AR=sh4-linux-ar
RANLIB=sh4-linux-ranlib
STRIP=sh4-linux-strip
ST_DERIVED_OBJS=32BITS
ST_CONTEXT_DIR=/opt/STM/stapisdk
ST_ARCH_PATH=$(DVD_PLATFORM)_$(DVD_BACKEND)_$(ARCHITECTURE)_$(DVD_OS)_$(ST_DERIVED_OBJS)
ST_LIB_NAME_EXT=$(DVD_BACKEND)_$(ARCHITECTURE)_$(DVD_OS)_$(ST_DERIVED_OBJS)
ST_DEBUG_LIB=$(ST_CONTEXT_DIR)/stdebug/stdebug.dir/$(ST_ARCH_PATH)/libstdebug.a
ST_APP_LIB=$(ST_CONTEXT_DIR)/stapp/stapp.dir/$(ST_ARCH_PATH)/libstapp.a
PLAYREC_LIBTAG=hnd
ST_PLAYREC_LIB=$(ST_CONTEXT_DIR)/stapp/stapp.dir/$(ST_ARCH_PATH)/libplayrec$(PLAYREC_LIBTAG)_$(ST_LIB_NAME_EXT).a
ST_API_TRANSPORT_LIB=$(ST_CONTEXT_DIR)/apilib/lib/$(ST_ARCH_PATH)/libstapi_$(DVD_TRANSPORT).a
ST_EXTERN_LIB_LINK = $(ST_API_TRANSPORT_LIB) $(ST_PLAYREC_LIB) $(ST_APP_LIB) -lpthread -lrt
ST_EXT_LIB_SYM_LINK = -lstapp -lplayrec$(PLAYREC_LIBTAG)_$(ST_LIB_NAME_EXT) -lstapi_$(DVD_TRANSPORT) -L$(ST_CONTEXT_DIR)/stapp/stapp.dir/$(ST_ARCH_PATH) -L$(ST_CONTEXT_DIR)/apilib/lib/$(ST_ARCH_PATH)

ST_MEDIAPLAY_LIB_PATH = $(ST_CONTEXT_DIR)/opensource/lib/linux
ST_MEDIAPLAY_LIB_LINK = $(ST_MEDIAPLAY_LIB_PATH)/libz.a $(ST_MEDIAPLAY_LIB_PATH)/libcurl.a $(ST_MEDIAPLAY_LIB_PATH)/libavutil.a $(ST_MEDIAPLAY_LIB_PATH)/libavformat.a $(ST_MEDIAPLAY_LIB_PATH)/libavcodec.a

ST_SDK_INCLUDE=-I$(ST_CONTEXT_DIR)/stapp -I$(ST_CONTEXT_DIR)/stapp/include -I$(ST_CONTEXT_DIR)/apilib/include -I$(ST_CONTEXT_DIR)/apilib/config/chip -I$(ST_CONTEXT_DIR)/apilib/config/platform/mb680_7105  -I$(ST_CONTEXT_DIR)/stapp/platform/$(DVD_PLATFORM)/$(DVD_BACKEND) -I$(ST_CONTEXT_DIR)/apilib/src/multicom/v3.2.3/include 
CC_FLAG_ST=-Wall -fno-strict-aliasing -O2
CC_SYMBOL_ST=-DST_$(DVD_BACKEND) -DDVD_FRONTEND_TUNER='"NIM_362"' -DST_LINUX -D$(DVD_PLATFORM) -D$(DVD_TRANSPORT) -D$(DVD_SERVICE) -DPROCESSOR_SH4 -DARCHITECTURE_$(ARCHITECTURE) -DDVD_TRANSPORT_STPTI4 -DDVD_TRANSPORT_STPTI   -DSTTUNER_USE_TER -DTUNER_TER_INCLUDED -DSTPTI_DVB_SUPPORT -DSDK_MEMORY_CONFIG=256 -DSTMERGE_INTERRUPT_SUPPORT -DSTVTG_CLK_HDMI -DSTVTG_HDMI -DHDMI_CEC_ON -DSTHDMI_CEC -DSTPTI_INDEX_SUPPORT -DSERVICE_DVB -DSTVID_DEBUG_GET_STATISTICS -DSTAPI_INTERRUPT_BY_NUMBER -DATAPI_USING_INTERRUPTS -DRDE_DISPLAY_SERVICE -DDISABLE_OSD_DISPLAY_SERVICE -DRDE_ENABLE_NOTIFY_COMMAND_IS_POSTED -DSTTTX_SUBT_SYNC_ENABLE -DSTTTX_SYNC_OFFSET=0 -DSERVICE_$(DVD_SERVICE) -DTCPIP -DDVR -DDISPLAY_SD=$(DVD_DISPLAY_SD) -DDISPLAY_HD=$(DVD_DISPLAY_HD) -DSTCLKRV_EXT_CLKA_MHZ=30 -DSTCLKRV_EXT_CLKB_MHZ=0 -DSTCLKRV_EXT_CLK_MHZ=0 -DSTSDK -DRUN_FROM_FLASH -DLINUX_UNIFIED_STAPI -DDVD_ADDRESSMODE=32 -DHARDWARE_REVISION=2 -DST_OSLINUX -DDVD_PLATFORM='"mb680"' -DDVD_BACKEND='"7105"' 

endif

ifeq ($(ARCH), x86)
GCC_CROSS_PREFIX=
CC=gcc
CXX=g++
AR=ar
RANLIB=ranlib
endif

ifeq ($(ARCH), arm)
GCC_CROSS_PREFIX=arm_v5t_le-
CC=arm_v5t_le-gcc
CXX=arm_v5t_le-g++
AR=arm_v5t_le-ar
RANLIB=arm_v5t_le-ranlib
endif

ifeq ($(ARCH), mips)
GCC_CROSS_PREFIX=mipsel-linux-
CC=mipsel-linux-gcc
CXX=mipsel-linux-g++
AR=mipsel-linux-ar
RANLIB=mipsel-linux-ranlib
endif

