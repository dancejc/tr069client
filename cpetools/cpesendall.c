//ITMS killer Ver 1.0
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <memory.h>

int get_value(const char* buf, const char* key, char *value, int offset, int len)
{
	char* p = strstr(buf, key);
	if(!p)
		return 0;
	strncpy(value, p + strlen(key) + offset, len);
	return 1;
}

int main(int argc, char *argv[])
{
	printf("\nITMS Killer Ver1.0\n");
	printf("    Usage   : cpesend host port request(message/request.txt)\n    example : cpesend 127.0.0.1 8080 inform\n\n");

	if(argc < 4)
	{
		argv[1] = "182.138.3.190";
		argv[2] = "9090";
		argv[3] = "inform";
	}
	
	char block[5120], infile[128];
  char *host = argv[1];
  int sockfd;
  struct sockaddr_in address;
  struct hostent *hostinfo;
	int in, nread;
	memset(block, 0, sizeof(block));
	
	sprintf(infile, "message/%s.txt", argv[3]);
	//in = open("message/test.txt", O_RDONLY); 
	in = open(infile, O_RDONLY); 
	nread = read(in, block, sizeof(block));
	
	int len, recvlen = 0;
	int result;
	//char ch = 'A';

	//Create a socket for the client.
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	hostinfo = gethostbyname(host);
	//Name the socket, as agreed with the server.
	address.sin_family = AF_INET;
	address.sin_addr = *(struct in_addr *)*hostinfo -> h_addr_list;
	//address.sin_addr.s_addr = inet_addr(host);
	address.sin_port = htons(atoi(argv[2]));
	len = sizeof(address);

	//Now connect our socket to the server's socket.
	result = connect(sockfd, (struct sockaddr *)&address, len);

	if(result == -1) {
		perror("oops: client3");
		exit(1);
	}
	
	//We can now read/write via sockfd.
	//write(sockfd, &ch, 1);
	
	//=================================send inform===============================
	
	write(sockfd, block, nread);
	printf("Send Message : \n%s\n", block);
	//int i = send(sockfd, block, nread, 0);printf("send %d byte.\n", i);
	memset(block, 0, sizeof(block));
	if(!(recvlen = read(sockfd, block, sizeof(block))))
	{
		printf("Not receive any response. May be message error?\n");
		exit(1);
	}
	printf("Get HTTP message : \n%s\n", block);
	/*char value[10];
	//we only support "Content-Length", Not support HTTP chunked method.
	if(!get_value(block, "Content-Length", value, 2, 4))
	{
		printf("Not found Content-Length, May be HTTP chunked.\n");
		exit(1);
	}
	int htmllen = atoi(value);
	if(htmllen < recvlen)exit(0);
	
	recvlen = 0;
	printf("Content-Length = %d\n", htmllen);
	while(recvlen < htmllen)
	{
		recvlen += recv( sockfd, block + recvlen, 10240, 0 );
		if(!recvlen)
			break;
	}
	printf("Get XML message : \n%s\n", block);*/
	
	//=================================send post===============================
	
	memset(block, 0, sizeof(block));
	in = open("message/empty.txt", O_RDONLY);
	nread = read(in, block, sizeof(block));
	write(sockfd, block, nread);
	printf("Send Message : \n%s\n", block);
	memset(block, 0, sizeof(block));
	if(!(recvlen = read(sockfd, block, sizeof(block))))
	{
		printf("Not receive any response. May be message error?\n");
		exit(1);
	}
	printf("Get HTTP message : \n%s\n", block);
	
	//=================================send set parameter response===============================
	
	memset(block, 0, sizeof(block));
	in = open("message/setparameterres.txt", O_RDONLY);
	nread = read(in, block, sizeof(block));
	write(sockfd, block, nread);
	printf("Send Message : \n%s\n", block);
	memset(block, 0, sizeof(block));
	if(!(recvlen = read(sockfd, block, sizeof(block))))
	{
		printf("Not receive any response. May be message error?\n");
		exit(1);
	}
	printf("Get HTTP message : \n%s\n", block);
	
	//=================================send reboot response===============================
	
	close(sockfd);
	exit(0);
}
