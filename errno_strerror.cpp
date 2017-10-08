
//char *strerror(int errno)
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
int main()
{
	int i=0;
	for(i=0;i<=512; i++)
	{
		printf("%d. ==  %s\n",i, strerror(i));
	}
}
