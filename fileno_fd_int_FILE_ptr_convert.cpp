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

//FILE *fp  和 int fd 之间的转换   convert 
int main()
{
	char stdin_redir_file[1024]={0};
	printf("stdin redir ok %s \n", stdin_redir_file);
	FILE *fp=fopen(stdin_redir_file, "r");
	if(fp==NULL)
	{
		printf("open %s error \n",  stdin_redir_file);
		exit(-1);
	}

	int fd_stdin=fileno(fp);
}
