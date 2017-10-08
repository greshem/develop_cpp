#include <algorithm>
#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <fstream>
#include <iostream> 
#include <iterator>  
#include <locale.h>
#include <map>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <vector> 
using namespace std;
//########################################################################
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//#include <dirent.h>
//#include <gtest/gtest.h>
//#include <stringprep.h>

int iw_sockets_open(void)
{
	static const int families[] = {
	AF_INET, AF_IPX, AF_AX25, AF_APPLETALK
	};
	unsigned int  i;
	int           sock;

	/*
	*    * Now pick any (exisiting) useful socket family for generic queries
	* Note : don't open all the socket, only returns when one matches,
	* all protocols might not be valid.
	* Workaround by Jim Kaba <jkaba@sarnoff.com>
	* Note : in 99% of the case, we will just open the inet_sock.
	* The remaining 1% case are not fully correct...
	*/
	/* Try all families we support */
	for(i = 0; i < sizeof(families)/sizeof(int); ++i)
	{
	  /* Try to open the socket, if success returns it */
	  sock = socket(families[i], SOCK_DGRAM, 0);
	  if(sock >= 0)
		return sock;
	}

	return -1;
}


int main()
{

	int fd=iw_sockets_open();
	if(fd < 0)
	{	
		printf("Open wireless socket error\n");
	}
	else
	{
		cout<<"fd "<< fd<<endl;
	}
}
