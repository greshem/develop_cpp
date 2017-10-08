#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
#include <Baselib.hpp>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
//#include <dirent.h>
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
#include <gtest/gtest.h>
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif
//###################################################
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/un.h>

//2010_09_06 by greshem. 
// 来自于 pdnsd 的 状态的线程。 
template <typename T> class book {
};

using namespace std;
int main(int argc, char *argv[])
{
	struct sockaddr_un *sa;
	int sa_len;
	int sock=-1;
	if((sock = socket(PF_UNIX, SOCK_STREAM, 0)) == -1)
	{
		die<char>("create unix socket error\n");
	}
	sa_len=(offsetof(struct sockaddr_un, sun_path) +  strlen("./test.status"));

	sa=(struct sockaddr_un *) malloc( sa_len+1);
	memset( sa, '\0', sa_len);
	strcpy(	sa->sun_path, "./test.status");
	sa->sun_family=AF_UNIX;
	
	if(connect(sock, (struct sockaddr *)sa, sa_len)== -1)
	{
		die<char>("ERROR: open socker  %s:%s\n", sa->sun_path, strerror(errno));
	}	
	printf("Opening socket %s\n",sa->sun_path);
	
	for(int i=0; i<=16; i++)
	{
		write(sock, &i, sizeof(i));
	}
	return 0;
}
