include $(ROOTDIR)/rules.make

SUBDIR= $(CWMP)

ifdef httpda
CFLAGS+=-DHTTP_DA -DWITH_OPENSSL
SUBDIR += plugin
endif

SRCS = $(wildcard *.c)
	 
OBJS = $(SRCS:.c=.o)



.PHONY:all clean 
all: subdir $(OBJS)

subdir:
	@for i in $(SUBDIR); do echo Making in "./"$$i; make -C $$i  || exit; done
$(OBJS):%.o:%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@cp $@ $(TR69CDIR)/release

clean:
	@for i in $(SUBDIR); do make -C $$i $@;  done
	@rm -rf $(OBJS) *~
