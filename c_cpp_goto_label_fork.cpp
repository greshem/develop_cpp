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
#include <stringprep.h>
#include <sys/wait.h> 

int main(int argc, char *argv[])
{

	printf("start \n");
	int pid=0;
	int number=0;

	child:
		if( (pid=fork()) < 0)
		{
			printf(" fork error \n");	
		}
		else if( pid==0)
		{
			printf("child  start\n");
			int i=0;
			for( i=0; i<=10; i++)
			{
				printf("child  %d 's %d loop \n", number, i);
				sleep(1);
			}
			
			printf("child  pid= %d, 退出 \n", getpid());
			//exit(-1);	
		} 
		else
		{
			int j;
			number++;
			if(number < 10)
			{
				goto  child;
			}
			while( wait(NULL)< 0)
			{
				printf("wait error\n");	
			}
			// if( (j=waitpid(pid, NULL, 0))< 0)
			// {
			// 	printf("断言 错误 waitpid 错误\n");
			// }
			// else
			// {
			// 	printf("child 进程发生变化， 父进程需要退出了, 子进程为 %d \n",j );
			// }
			printf("父进程 最后退出 \n");
		}
	return 0;
}
