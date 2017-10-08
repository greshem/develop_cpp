#include <algorithm>
#include <arpa/inet.h>
#include <fstream>
#include <gtest/gtest.h>
#include <iostream> 
#include <iterator>  
#include <map>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector> 
//###################################################
//########################################################################
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>

#define MYPORT 2345
int arp_force ( in_addr_t dst)
{
	struct sockaddr_in sin;
	int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if(fd < 0)
	{
		printf(" create socket error\n");
		exit(-1);
	}
	
	memset(&sin, 0, sizeof(sin));
	sin.sin_family=AF_INET;
	sin.sin_addr.s_addr=dst;
	sin.sin_port= htons(MYPORT);
	
	int	i=sendto(fd, NULL, 0, 0, (sockaddr *) &sin, sizeof(sin));
	close(fd);
	return (i==0);
}

int main()
{
	return 0;
}
