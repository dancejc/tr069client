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
	if(argc<3)
	{
		printf("Error: Not enough parameters.\n");
		exit(0);
	}
	char block[5120], infile[128];
	int server_sockfd, client_sockfd;
  int server_len, client_len;
  struct sockaddr_in server_address;
  struct sockaddr_in client_address;
  int nread = 0, nsend = 0, in;
  int i = 2;
	
/*  Create an unnamed socket for the server.  */

  server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

/*  Name the socket.  */

  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = htonl(INADDR_ANY);
  //server_address.sin_addr.s_addr = inet_addr("10.2.7.29");
  server_address.sin_port = htons(atoi(argv[1]));
  server_len = sizeof(server_address);
  nread = bind(server_sockfd, (struct sockaddr *)&server_address, server_len);
  if(nread < 0){perror("bind");return 0;}

/*  Create a connection queue and wait for clients.  */

  listen(server_sockfd, 5);
  
  printf("server waiting\n");

/*  Accept a connection.  */

  client_len = sizeof(client_address);
  client_sockfd = accept(server_sockfd, 
        (struct sockaddr *)&client_address, &client_len);

/*  We can now read/write to client on client_sockfd.  */
	while(argc-- > 2)
	{
		//read(client_sockfd, &ch, 1);
	  nread = read(client_sockfd, block, sizeof(block));
	  printf("Get message : %d\n%s\n", nread, block);
	  bzero(block, 5120);nread = 0;
	  
	  sprintf(infile, "message/%s.txt", argv[i++]);
		in = open(infile, O_RDONLY); 
		nread = read(in, block, sizeof(block));
	  write(client_sockfd, block, nread);
	  printf("Send  inform res Message : \n%s\n", block);
	  //write(client_sockfd, &ch, 1);
	  bzero(block, 5120);nread = 0;
	}
  
  close(client_sockfd);
	
	return 0;
}
