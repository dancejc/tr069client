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

int main(int argc, char *argv[])
{
	if(argc<2)
		argv[1] = "9000";
	char block[5120], infile[128];
	int server_sockfd, client_sockfd;
  int server_len, client_len;
  struct sockaddr_in server_address;
  struct sockaddr_in client_address;
  int nread;
	
/*  Create an unnamed socket for the server.  */

  server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

/*  Name the socket.  */

  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
  server_address.sin_port = htons(atoi(argv[1]));
  server_len = sizeof(server_address);
  bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

/*  Create a connection queue and wait for clients.  */

  listen(server_sockfd, 5);
  

  printf("server waiting\n");

/*  Accept a connection.  */

  client_len = sizeof(client_address);
  client_sockfd = accept(server_sockfd, 
        (struct sockaddr *)&client_address, &client_len);

/*  We can now read/write to client on client_sockfd.  */

  //read(client_sockfd, &ch, 1);
  read(client_sockfd, block, sizeof(block));
  printf("Get message : \n%s\n", block);
  bzero(block, 5120);
  
  sprintf(infile, "message/%s.txt", argv[2]);
  printf("open Message %s\n", infile);
	int in = open(infile, O_RDONLY); 
	nread = read(in, block, sizeof(block));
  write(client_sockfd, block, nread);
  printf("Send Message : \n%s\n", block);
  bzero(block, 5120);
  //write(client_sockfd, &ch, 1);
  
  nread = read(client_sockfd, block, sizeof(block));
  printf("Get message %d: \n%s\n", nread, block);
  bzero(block, 5120);
  close(client_sockfd);
	
	return 0;
}
