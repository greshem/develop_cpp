#include <unistd.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/types.h>

#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
#include <Baselib.hpp>
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif
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
#include <gtest/gtest.h>

//###################################################
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/un.h>

//2010_09_06 by greshem. 
// 来自于 pdnsd 的 状态的线程。 

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


using namespace std;
int main(int argc, char *argv[])
{
	struct sockaddr_un *sa;
	int stat_sock;
	unsigned int sa_len = (offsetof(struct sockaddr_un, sun_path) + strlen("./test.status"));
	sa=(struct sockaddr_un  *) malloc(sa_len+1);
	strcpy( sa->sun_path, "./test.status");
	
	init_daemon();

	if((unlink(sa->sun_path) != 0) &&  errno != ENOENT)
	{
		die<char>("./test.status 删除不了\n");
	}
	if((stat_sock=socket(PF_UNIX, SOCK_STREAM, 0)) == -1)
	{
		die<char>("open unix socket error\n");
	}
	sa->sun_family=AF_UNIX;
	if(	bind(stat_sock, (struct  sockaddr *) sa, sa_len)== -1)
	{
		die<char>("bind error");
	}
	
	if(listen(stat_sock, 5) == -1)
	{
		die<char>(" listen socke error\n");
	}	
	
	for(;;)
	{
		struct sockaddr_un ra;
		socklen_t res=sizeof(ra);
		int rs;
	if(( rs=accept(stat_sock, (struct sockaddr *) &ra, &res)) != -1)
	{
		int tmp[10]={0};
		printf("sun_path -> %s\n", ra.sun_path);	
		if(read(rs,  &tmp, sizeof(tmp)))
		{
			for(int i=0; i<10; i++)
			{
				cout<<tmp[i]<<endl;
			}

		}
	}
	}
	return 0;
}
