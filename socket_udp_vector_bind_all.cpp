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

template< class T> int  dump(T &in)
{
    typedef typename   T::iterator IT; 
    IT it; 
    
    for(it=in.begin(); it!= in.end(); it++)
    {   
        cout<<*it<<endl;
    }   
    return 1;
}

using namespace std;
int zeor()
{
	return 0;
}
int main(int argc, char *argv[])
{

	socklen_t len;
	
	vector<int> vecSock(1000);
	generate(vecSock.begin(), vecSock.end(), zeor);	

	for(vector<int>::iterator it=vecSock.begin(); it!= vecSock.end(); it++)
	{
		len=sizeof(struct sockaddr_in);
		int fd=socket(AF_INET, SOCK_DGRAM, 0);
		if(fd == -1 )
		{
				printf("socket socket %d 创建失败");
				printf("socket %d 创建失败");
		}	
		else
		{
			*it=fd;
		}
	}
		
//	dump<vector<int> > (vecSock);

	struct  sockaddr_in addr;

	for(vector<int>::iterator it=vecSock.begin(); it!= vecSock.end(); it++)
	{
		memset(&addr, '\0', sizeof(addr));
		addr.sin_family=AF_INET;
		addr.sin_port=htons(*it);
		addr.sin_addr.s_addr=htonl(INADDR_ANY);
		
		int ret=bind(*it, (sockaddr *) &addr, sizeof(addr));
		if(ret !=  0)
		{
			//die("bind", "bind error");
			printf("端口 %d 端口绑定失败", *it);
		}
		else
		{
			printf("端口 %d 端口绑定成功", *it);
		}

	}


	for(vector<int>::iterator it=vecSock.begin(); it!= vecSock.end(); it++)
	{
		int ret=listen(*it, 3);
		if(ret !=  0)
		{
			printf("端口 %d 端口绑定失败", *it);
		}
		else
		{
			printf("端口 %d 端口绑定成功", *it);
		}

	}

	//sleep(10000);
	/********int ret = listen(fd, 3);
	if(ret < 0)
	{
		die("listen ", "listen error\n");
	}*/
	
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
