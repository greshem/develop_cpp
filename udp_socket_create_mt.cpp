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
int work_net()
{

	socklen_t len;
	int count=0;	
	vector<int> vecSock(100);
	generate(vecSock.begin(), vecSock.end(), zeor);	

	for(vector<int>::iterator it=vecSock.begin(); it!= vecSock.end(); it++)
	{
		len=sizeof(struct sockaddr_in);
		int fd=socket(AF_INET, SOCK_STREAM, 0);
		if(fd == -1 )
		{
				printf("socket socket %d 创建失败",count);
				printf("socket %d 创建失败", count); 
		}	
		else
		{
			*it=fd;
			count++;
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
			warn<char> ("bind %d port error", *it);
			printf("端口  %d 端口绑定失败", *it);
		}
		else
		{
			printf("端口	%d 端口绑定成功", *it);
		}

	}


	for(vector<int>::iterator it=vecSock.begin(); it!= vecSock.end(); it++)
	{
		int ret=listen(*it, 3);
		if(ret !=  0)
		{
			printf("端口  %d 端口绑定失败", *it);
		}
		else
		{
			printf("端口  %d 端口绑定成功", *it);
		}

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
	return 1;
}
static 
void * __stdcall work( void *in)
{

	int i;
	i=*(int *)in;
	//while(1)
	{
	//	printf("%d\n", i);
		i++;
		work_net();
		sleep(1);
	}
}
int main(int argc, char *argv[])
{
	MThread<char>  thread;

	int a=100;
	int b=1000;
	thread.StartThread("test1", work, &a);
	thread.StartThread("test2", work, &b);
	// while(1)
	// {
	// 	sleep(1);
	// }
	return 0;
}
