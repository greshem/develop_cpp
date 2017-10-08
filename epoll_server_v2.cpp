#include <unistd.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/types.h>

#include <string.h>
#include <stdio.h>


#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h> 
#include <stdlib.h>
#include <sys/epoll.h>
#include <pthread.h>
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
using namespace std;

#define MAX_EPOLL_NUM 200
#define BUFFER_SIZE 65536

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


void* serverport(void* arg);
void* recv_process(void* arg);

static const int      SERVER_PORT = 1300;
static const int      CLIENT_PORT = 1325; // define the defualt connect port id
static const int      LENGTH_OF_LISTEN_QUEUE = 5; //length of listen queue in server

static struct epoll_event ev_reg;
int epoll_fd;

int main(int argc ,char** argv)
{

	init_daemon();
	epoll_fd=epoll_create(MAX_EPOLL_NUM);


	pthread_t send_thread[2];
	pthread_create(&send_thread[0],NULL,serverport,(void*)0);  
	pthread_create(&send_thread[1],NULL,recv_process,(void*)0); 
	pthread_join(send_thread[0],NULL);
	pthread_join(send_thread[1],NULL);
	return 0; 
}

void* serverport(void* arg)
{
	int servfd,clifd;
	struct sockaddr_in servaddr,cliaddr;

	if ((servfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
	   printf("create socket error!\n");
	   exit(1);
	}
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERVER_PORT);
	servaddr.sin_addr.s_addr = htons(INADDR_ANY);

	if (bind(servfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0)
	{
	   printf("bind to port %d failure!\n",SERVER_PORT);
	   exit(1);
	}

	if (listen(servfd,LENGTH_OF_LISTEN_QUEUE) < 0)
	{
	   printf("call listen failure!\n");
	   exit(1);
	}
	   
	while (1)
	{
		socklen_t length = sizeof(cliaddr);
		clifd = accept(servfd,(struct sockaddr*)&cliaddr,&length);
		if(clifd == -1)
		{
			continue;
		}
		else
		{       
			ev_reg.data.fd=clifd;
			ev_reg.events=EPOLLIN;
			if (epoll_ctl(epoll_fd,EPOLL_CTL_ADD,clifd,&ev_reg)<0) 
			{
				printf("***** server add client to epoll failed %d \n",clifd);
				continue;
			}
	   }                
	}//exit

	close(servfd);
	return NULL;
}

void* recv_process(void* arg)
{
	int client_sock;
	int maxfds,i;
	struct epoll_event eventstmp[MAX_EPOLL_NUM];
	char buf[BUFFER_SIZE];

	while(1) 
	{
	   maxfds = -1;
	   maxfds = epoll_wait(epoll_fd,eventstmp,MAX_EPOLL_NUM,-1);

	   for(i=0;i<maxfds;i++)
	   {
			client_sock = eventstmp[i].data.fd; 
			int ret = recv(client_sock,buf,BUFFER_SIZE,0);
			printf("client_fp=%d receive size = %d\n",client_sock,ret);
			if(ret>0)
			{
				printf(" recv succ.   client_sock=%d   len=%d\n",client_sock,ret);
			} 
			else
			{
				close(client_sock);
				printf("recv_process: close socket success.\n");

				ev_reg.data.fd=client_sock;
				if (epoll_ctl(epoll_fd,EPOLL_CTL_DEL,client_sock,&ev_reg)<0) 
				{
					printf("recv_process:epoll delete success \n\n");
				}
				else
				{
					printf("recv_process:epoll delete FAILED \n\n");
				}     
			}
	   }
	}
	return NULL;
}

