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
#include <stringprep.h>
int main()
{
	char time_str[256]={0};
	time_t timep;
	time(&timep);
	struct tm * gtime = gmtime(&timep);
	sprintf(time_str, "%d-%d-%d\n", gtime->tm_year + 1900, gtime->tm_mon + 1, gtime->tm_mday);
	printf("%s\n", time_str);
}

