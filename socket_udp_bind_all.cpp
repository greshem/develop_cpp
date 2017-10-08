#include <algorithm>
#include <arpa/inet.h>
#include <fstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <sys/socket.h>
#include <vector> 
//#include <Baselib.hpp> 
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//2010_07_15 by qzj. 

using namespace std;
int main(int argc, char *argv[])
{
	socklen_t len;
	len=sizeof(struct sockaddr_in);
	char buffer[1024];
	int fd=socket(AF_INET, SOCK_DGRAM, 0);
	if(fd == -1 )
	{
			printf("socket socket %d 创建失败");
			printf ("socket %d 创建失败");
	}	
	
	struct  sockaddr_in addr;
	/*struct hostent *srv;
	
	if( (srv= gethostbyname("192.168.7.87") )== 0)	
	{
		logger.WriteError("DNS", "192.168.7.87 DNS 解析失败\n");
		die( "192.168.7.87 DNS 解析失败\n");
	}*/

	for(int i=11; i<=1024; i++)
	{	
		memset(&addr, '\0', sizeof(addr));
		addr.sin_family=AF_INET;
		addr.sin_port=htons(i);
		addr.sin_addr.s_addr=htonl(INADDR_ANY);
		
		int ret=bind(fd, (sockaddr *) &addr, sizeof(addr));
		if(ret !=  0)
		{
			//die("bind", "bind error");
		//	logger.WriteError("端口", "%d 端口绑定失败", i);
		}
		else
		{
			printf("端口", "%d 端口绑定成功", i);
		}
	
	}
	int ret = listen(fd, 3);
	if(ret < 0)
	{
		printf ("listen ", "listen error\n");
		exit(-1);
	}
	
/*	int cfd;
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
					cout<<"客户端断开连接了"<<endl;
					break;
				}	
			}	
	}*/
	return 0;
}
