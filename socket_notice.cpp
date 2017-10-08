
//#2010_09_28_18:21:53 add by greshem
#include <unistd.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/types.h>


#include <Baselib.hpp>
#include <fstream>
//#include <dirent.h>
#include <string> 
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

void init_daemon(void)
{
	int pid;
	int i;
	
	if((pid=fork()))
	{
		exit(0);//�Ǹ����̣�����������
	}
	else if(pid< 0)
	{
		exit(1);//forkʧ�ܣ��˳�
	}
	//�ǵ�һ�ӽ��̣���̨����ִ��
	
	setsid();//��һ�ӽ��̳�Ϊ�µĻỰ�鳤�ͽ����鳤
	//��������ն˷���
	if((pid=fork()))
	{
		exit(0);//�ǵ�һ�ӽ��̣�������һ�ӽ���
	}
	else if(pid< 0)
	{
		exit(1);//forkʧ�ܣ��˳�
	}
	//�ǵڶ��ӽ��̣�����
	//�ڶ��ӽ��̲����ǻỰ�鳤
	
	for(i=0;i< NOFILE;++i)//�رմ򿪵��ļ�������
		close(i);
	chdir("/tmp");//�ı乤��Ŀ¼��/tmp
	umask(0);//�����ļ�������ģ
	return;
}

int main(int argc, char *argv[])
{
	socklen_t len;
	sockaddr_in server_addr;
	sockaddr_in client_addr;

	int ret;
	int client_fd;
	int server_fd;
	fd_set  read_fdset;

	server_fd=socket(AF_INET, SOCK_STREAM, 0);

	if(server_fd < 0)
	{
		die<char>("create socket error\n");
	}
	init_daemon();
	server_addr.sin_family= AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port	=htons(2345);
	len=sizeof(server_addr);
	
	ret=bind(server_fd,(sockaddr*) &server_addr, len);
	if(ret < 0)
	{
		die<char>("bind error\n");
	}	
	
	ret=listen(server_fd, 5);	
	if(ret <0)
	{
		die<char>("listen error\n");
	}
	
	while(1)
	{
		char tmp[1024];
		char *welcome= "Welcome to server";

		client_fd=accept(server_fd, (struct sockaddr *)& client_addr, &len); 
		if(client_fd<0)
		{
			warn<char>(" accept error\n");
		}
		ret=write(client_fd, welcome, strlen(welcome));
		if(ret != strlen(welcome))
		{
			warn<char>(" send len != strlen(messgae)");
		}
		
		ret=read(client_fd, tmp, sizeof(tmp));
		if(ret > 0)
		{
			printf("%s\n", tmp);
		}
	}	
}
