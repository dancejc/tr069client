include $(ROOTDIR)/rules.make

SUBDIR = root
				  
SRCS = $(wildcard *.c)
	 
OBJS = $(SRCS:.c=.o)




.PHONY:all clean install
all: subdir $(OBJS)

subdir:
	@for i in $(SUBDIR); do echo Making in "./"$$i; make -C $$i  || exit; done
$(OBJS):%.o:%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@cp $@ $(TR69CDIR)/release

clean:
	@for i in $(SUBDIR); do make -C $$i $@;  done
	@rm -rf $(OBJS) *~
