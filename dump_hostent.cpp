#include <algorithm>
#include <arpa/inet.h>
#include <fstream>
#include <iostream>
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
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//#include <gtest/gtest.h>
//2010_09_06 by greshem. 



using namespace std;
int main(int argc, char *argv[])
{
	
	struct hostent *srv;
	if ((srv=gethostbyname("www.baidu.com"))==0)
	{
		printf("dns resolver fail\n");
	}
		
	cout<< srv->h_name<<endl;

	char **tmp;
	tmp=srv->h_aliases;
	while( (*tmp) != NULL)
	{
		printf("%s \n", *tmp);
		tmp++;
	} 

	cout<<"h_addrtype "<< srv-> h_addrtype<<endl;
	cout<<"length of address"<< srv->h_length<<endl;

	tmp=srv->h_addr_list;
	while( (*tmp) != NULL)
	{
		printf("%s\n", inet_ntoa(*(struct in_addr *) (*tmp)));	
		tmp++;
	}
	return 0;
}
