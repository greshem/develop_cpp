#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

// sprintf(tmp, "%-*s %-*s %-*d %-*s\r\n",
// ��һ���ο�,  regexec_regcomp.c  31 �е�
int main()
{
	char buffer[1024]="0123456789abcdefgh";
	char tmp[1024]={0};

	//snprintf(tmp,sizeof(tmp),  "%-*s\n", 3, buffer);
	snprintf(tmp,sizeof(tmp),  "%.*s\n", 3,  buffer);
	
	printf("%s", tmp);
}
