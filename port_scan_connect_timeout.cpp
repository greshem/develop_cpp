#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

//#include <sys/socket.h>
//#include <netinet/in.h>
#include <arpa/inet.h>

int scan_port_block(const char *hostname, int  port)
{
	int fd;
	struct sockaddr_in addr;
	struct timeval timeo = {3, 0};
	socklen_t len = sizeof(timeo);
	fd = socket(AF_INET, SOCK_STREAM, 0);
	
	//timeo.tv_sec = atoi(argv[3]); 
	timeo.tv_sec = 3;
	
	setsockopt(fd, SOL_SOCKET, SO_SNDTIMEO, &timeo, len);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(hostname);
	//addr.sin_port = htons(atoi(argv[2]));
	addr.sin_port = htons(port);
	if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) 
	{
		if (errno == EINPROGRESS) 
		{
			fprintf(stderr, "timeout/n");
			return -1;
		}
		perror("connect");
		return -1;
	}
	else
	{
		printf("ip_addr: %s, port  %d connected\n", hostname, port);
		return 0;
	}

}
int main(int argc, char *argv[])
{

	if(argc!=2)
	{
		printf("Usgae: %s  ip \n", argv[0]);
		exit(-1);
	}

	int scanport;  
	int start_port=0;  
	int end_port=1024;  

	for(scanport=start_port;scanport<end_port;scanport++)  
	{  
		//printf("Deal with port %d \n", scanport );
		scan_port_block(argv[1], scanport);
	}

	scan_port_block(argv[1], 7495);
	scan_port_block(argv[1], 22);
	scan_port_block(argv[1], 3333);


	return 0;  

}
