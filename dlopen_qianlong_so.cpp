//########################################################################
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <locale.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <assert.h>
//#include <stringprep.h>
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif

#include <dlfcn.h>
#include <iostream> 
using namespace std;
//2010_12_21 by greshem. 
int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s file.so \n", argv[0]);
		exit(-1);
	}
	printf("%s\n", "dlopen_qianlong_so.c");

	void *handle=NULL;
	handle=	dlopen(argv[1] , RTLD_LAZY);
	if(handle == NULL)
	{
		cout<<"dl open failuer "<<endl;	
		//perror("dlopen ");
		printf("%s \n", dlerror());
	}
	else
	{
			
		//void *dlsym(void *handle, const char *symbol);
		char *ptr_init=(char *)dlsym(handle, "Instance");
		if(ptr_init)
		{
			cout<<"success"<<endl;
			printf("Instance () %x\n" , ptr_init);
		}
		else
		{
			cout<<"init function ptr failure \n"<<endl;
		}
	}

	return 1;
}
