
//#2010_09_28_18:22:59 add by greshem
#include <unistd.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/types.h>

#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif

#include <Baselib.hpp> 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
//#include <dirent.h>
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
//2010_07_15 by qzj. 
//
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

using namespace std;
int main(int argc, char *argv[])
{
	socklen_t len;
	len=sizeof(struct sockaddr_in);
	char buffer[1024];
	int fd=socket(AF_INET, SOCK_STREAM, 0);
	if(fd == -1 )
	{
			printf("socket socket %d ����ʧ��");
			die<char> ("socket %d ����ʧ��\n");
	}	
	
	init_daemon();
	struct  sockaddr_in addr;
	/*struct hostent *srv;
	
	if( (srv= gethostbyname("192.168.7.87") )== 0)	
	{
		logger.WriteError("DNS", "192.168.7.87 DNS ����ʧ��\n");
		die( "192.168.7.87 DNS ����ʧ��\n");
	}*/
	
	memset(&addr, '\0', sizeof(addr));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(1234);
	addr.sin_addr.s_addr=htonl(INADDR_ANY);
	
	int ret=bind(fd, (sockaddr *) &addr, sizeof(addr));
	if(ret !=  0)
	{
		die<char> ("bind", "bind error\n");
	}
	
	ret = listen(fd, 3);
	if(ret < 0)
	{
		die<char>("listen ", "listen error\n");
	}
	int cfd;
	while( (cfd =accept( fd, (sockaddr *)&addr, &len)) > 0  )
	{
			while(1)
			{
				memset(buffer, '\0', sizeof(buffer));
				int count=read(cfd, buffer, sizeof(buffer));
				//if(count< 0)
				printf("%s\n", buffer);
				if(count<=0)
				{
					cout<<"�ͻ��˶Ͽ�������"<<endl;
					break;
				}	
			}	
	}
	return 0;
}
