//########################################################################
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
//#include <dirent.h>
#include <unistd.h>
#include <locale.h>
#include <sys/stat.h>
//#include <sys/ioctl.h>
#include <errno.h>
//#include <fcntl.h>
#include <time.h>
#include <assert.h>
//#include <stringprep.h>

int changeToLinuxPath(char *in, int len)
{
	for(int i=0; i< len; i++)
	{
		if(in[i]=='\\')
		{
			in[i]='/';
		}
	}
	if(in[0] >= 'A' && in[0] <='z' && in[1]==':')
	{
		memmove(in, in+2, len-2);
	}
	return 1;
	
}
int main()
{
	//char *path="c:\\aaa\\bb\\cc\\ee";
	char path[1024]= "c:\\aaa\\bb\\cc\\ee";
	printf("%s\n", path);
	//path[0]='e';
	changeToLinuxPath(path, sizeof(path));
	printf("%s|\n", path);
}
