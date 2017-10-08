#include <stdlib.h>
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <string> 
#include <vector> 
//#include <Baselib.hpp> 
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//2010_07_15 by qzj. 

using namespace std;

int main(int argc, char *argv[])
{
	struct hostent *srv;
      
	if( (srv= gethostbyname("192.168.7.87") )== 0)  
	{
		printf("DNS  192.168.7.87 DNS Ω‚Œˆ ß∞‹\n");
		printf( "192.168.7.87 DNS Ω‚Œˆ ß∞‹\n");
		exit(-1);
     }

	return 0;
}
