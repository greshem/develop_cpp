//########################################################################
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
//#include <Baselib.hpp>
#include <fstream>
//#include <dirent.h>
#include <string> 
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif

#include <dlfcn.h>


using namespace std;
int main(int argc, char *argv[])
{
	void *handle=NULL;
	handle=	dlopen("/lib/libc-2.12.so", RTLD_LAZY);
	if(handle == NULL)
	{
	cout<<"dl open failuer "<<endl;	
	}
	else
	{
		cout<<"success"<<endl;
	}
		
	return 0;
}
