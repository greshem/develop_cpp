
//#2010_09_28_18:15:48 add by greshem
#include <unistd.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/types.h>
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


#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 80
#define SERV_PORT 8888

void init_daemon(void)
{
	int pid;
	int i;
	
	if((pid=fork()))
	{
		exit(0);//是父进程，结束父进程
	}
	else if(pid< 0)
	{
		exit(1);//fork失败，退出
	}
	//是第一子进程，后台继续执行
	
	setsid();//第一子进程成为新的会话组长和进程组长
	//并与控制终端分离
	if((pid=fork()))
	{
		exit(0);//是第一子进程，结束第一子进程
	}
	else if(pid< 0)
	{
		exit(1);//fork失败，退出
	}
	//是第二子进程，继续
	//第二子进程不再是会话组长
	
	for(i=0;i< NOFILE;++i)//关闭打开的文件描述符
		close(i);
	chdir("/tmp");//改变工作目录到/tmp
	umask(0);//重设文件创建掩模
	return;
}

void do_echo(int sockfd, struct sockaddr *pcliaddr, socklen_t clilen) 
{
	int n;
	socklen_t len;
	char mesg[MAXLINE];
	for (;;)
		
	{
		len = clilen;
		
/* waiting for receive data */ 
		    n = recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);
		
/* sent data back to client */ 
		    sendto(sockfd, mesg, n, 0, pcliaddr, len);
	}
}

int main(void)  
{
	int sockfd;
	struct sockaddr_in servaddr, cliaddr;
	init_daemon();

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);	/* create a socket */
	
/* init servaddr */ 
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
	
/* bind address and port to socket */ 
	if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
	{
		perror("bind error");
		exit(1);
	}
	do_echo(sockfd, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
	return 0;
}


