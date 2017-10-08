#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
#include <vector> 
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <iostream> 
using namespace std;
int find(char *in);
int main(int argc, char *argv[])
{
	char *tmpbuf=".";
	find(tmpbuf);
	return 0;
}
int find(char *in)
{
	chdir(in);
	DIR *dirp;
	struct dirent *dp;
	if((dirp=opendir(in))==NULL)
	{
		printf("opendir error\n");
		return -1;
	}
	while(dp=readdir(dirp))
	{
		if(dp->d_type==DT_DIR)
		{
			if(!strcmp(dp->d_name, ".")&&  !strcmp(dp->d_name,".."))
			{
				find(dp->d_name);
			}
		}
		else
		{
			printf("%s\n", dp->d_name);
		}
	}
}

