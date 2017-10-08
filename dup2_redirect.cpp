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

void redir_stdin_test();
void redir_stdout_test();
int main()
{
	redir_stdout_test();
	//redir_stdin_test();
}	
void redir_stdin_test()
{
	FILE *pass=fopen("/etc/passwd", "r");
	if(pass==NULL)
	{
		printf("open /etc/passwd error \n");
		exit(-1);
	}
	int fd=fileno(pass);
	dup2(fd, 0);
	
	char buffer[1024]={0};
	while(fgets(buffer, sizeof(buffer), stdin))
	{
		printf("%s", buffer);
	}
	
}
void redir_stdout_test()
{	
	FILE *fp=fopen("output.txt", "a+");
	FILE *fp_stderr=fopen("output_stderr.txt", "a+");
	if(fp==NULL)
	{
		printf("open output.ext error \n");
		exit(-1);
	}
	int fd=fileno(fp);
	int fd_err=fileno(fp_stderr);
	dup2(fd, 1);
	dup2(fd_err, 2);
	
	int i;
	for(i=0; i<=1000;i++)
	{
		printf("this is  output line %d\n", i);
		fprintf(stderr,  "this is stderr output line %d\n", i);

	}
	fclose(fp);
}
