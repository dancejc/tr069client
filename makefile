#############################
#    tr69c makefile				  #
#############################
export TR69CDIR=$(PWD)
export ROOTDIR = $(PWD)
include $(TR69CDIR)/rules.make

APPROOT	=	$(TR69CDIR)/..
TARGET_PATH = $(ROOTDIR)/target
#############################
#    cwmp version						#
#############################
export CWMP = cwmp-1-0
#export CWMP = cwmp-1-1



#############################
#    source directroy				#
#############################
SUBDIRS =  configuration  			\
				cpefw  							\
					stub 			\
					stub/plugin
			
#############################
#    	target								#
#############################
TARGET = tr69c


export CFLAGS = -Wall -fno-strict-aliasing  -DCPE_DEBUG -DDEBUG -g -DHTTP_DA -DWITH_OPENSSL
export CPPFLAGS = -I$(APPROOT)/include -I$(TR69CDIR)/inc/ -I$(TR69CDIR)/inc/stub/ -I$(TR69CDIR)/inc/stub/$(CWMP)/
LDFLAGS =  -L$(APPROOT)/lib

#LIBS= -lpthread  -lini -lreadip
LIBS= -lpthread lib/x86/libssl.a lib/x86/libcrypto.a -ldl

#ifdef httpda
#LIBS+=lib/x86/libssl.a lib/x86/libcrypto.a -ldl
#CFLAGS+=-DHTTP_DA -DWITH_OPENSSL
#endif

OBJS = $(wildcard release/*.o)


.PHONY:releasedir obj  target clean

all:releasedir obj  target
releasedir:
	@mkdir -p release

obj: 
	@for i in $(SUBDIRS); do echo Making in "./"$$i; make -C $$i || exit; done 

target:
	$(CC)  -o ${TARGET} $(OBJS) $(LDFLAGS) $(LIBS)
	#$(STRIP) $(TARGET)
	@cp $(TARGET) $(TARGET_PATH)/bin/

clean:
	@for i in $(SUBDIRS); do make -C $$i $@;  done
	rm -rf $(TARGET)
	rm -rf release
