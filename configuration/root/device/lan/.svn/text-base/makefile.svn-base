include $(ROOTDIR)/rules.make
			  
SRCS = $(wildcard *.c)
	 
OBJS = $(SRCS:.c=.o)




.PHONY:all clean
all: $(OBJS) 


$(OBJS):%.o:%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@cp $@ $(TR69CDIR)/release

clean:
	rm -rf $(OBJS) *~
