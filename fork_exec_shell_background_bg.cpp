
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
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

char *g_find_argv[]={"find", "/", '\0'};
char *g_NULL_argv[]={'\0','\0'};
char *g_cat_argv[]={"/etc/passwd", '\0'};

//void call_execve(char *cmd);
void call_execve_with_fd_redir(char *cmd,  char **my_argv, char * stdin_redir_file,  char * stdout_redir_file );

int main(int argc, char *argv[])
{
	while (1)
	{
		printf("fork exec and rediect with  \"find / \"  \n");
		char buffer[1024];
		fgets(buffer, sizeof(buffer), stdin );
		printf("%s\n", buffer);

		pid_t cpid;

		
		sleep(5);
		cpid = fork();
		if (cpid == -1) 
		{
		   perror("fork");
		   exit(EXIT_FAILURE);
		}

		if (cpid == 0)  /* Code executed by child */
		{            
		   printf("Child PID is %ld\n", (long) getpid());
		   //if (argc == 1)
			//   pause();                    /* Wait for signals */
			//call_execve("/bin/loop_bash_while.sh" );
			//call_execve("/usr/bin/find",g_find_argv,  NULL, "output_find.txt" );  //ok
			//call_execve("/usr/bin/find",g_find_argv,  NULL, NULL );				//ok
			call_execve_with_fd_redir("/usr/bin/cat", g_NULL_argv,  "/tmp/tmp", NULL );
		} 
		else 
		{                    /* Code executed by parent */
		}
	}
}

void call_execve_with_fd_redir(char *cmd, char **my_argv, char * stdin_redir_file,  char * stdout_redir_file )
{
    int i;
    printf("[call_execve]cmd is %s\n", cmd);
	//sleep(5);
	if(stdin_redir_file)
	{
		printf("not suport with  stdin redir now \n");
		return ;
	}
    if(fork() == 0)  //child 
	{
		int fd_stdin =-1;
		int fd_stdout=-1;
		if(stdin_redir_file && (strlen(stdin_redir_file)>0))
		{
			printf("stdin redir ok %s \n", stdin_redir_file);
			FILE *fp=fopen(stdin_redir_file, "r");
			if(fp==NULL)
			{
				printf("open %s error \n",  stdin_redir_file);
				exit(-1);
			}
			fd_stdin=fileno(fp);
			dup2(fd_stdin, 0);
		}


		if(stdout_redir_file && (strlen(stdout_redir_file)>0))
		{
			FILE *fp=fopen(stdout_redir_file, "w+");
			if(fp==NULL)
			{
				printf("open %s error \n",  stdout_redir_file);
				exit(-1);
			}
			int fd_stdout=fileno(fp);
			dup2(fd_stdout, 1);
		}

		
		if( my_argv ==NULL ) //bug for  cat 
		{
			i=	system(cmd);
		}
		else if( my_argv != NULL && my_argv[0]=='\0')
		{
			i=	system(cmd);
		}
		else
		{
       		i = execve(cmd, my_argv, NULL);
		}
        //i = execve(cmd, NULL, NULL);
        //printf("errno is %d\n", errno);
        if(i < 0) 
		{
            printf("%s: %s\n", cmd, "command not found");
            exit(1);
        }
		close(fd_stdin);
		close(fd_stdout);
		//close(0);
		//close(1);	
    } else 
	{
        wait(NULL);
		printf("cmd: %s is over \n", cmd );
    }
}
