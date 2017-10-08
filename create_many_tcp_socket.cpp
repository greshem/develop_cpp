#include <algorithm>
#include <fstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <sys/socket.h>
#include <vector> 
#include <unistd.h>
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//2010_07_15 by qzj. 

using namespace std;
int main(int argc, char *argv[])
{
	//for(int i=0; i<=66000 ; i++)
	for(int i=0; i<=1300 ; i++)
	{	
		int fd=socket(AF_INET, SOCK_STREAM, 0);
		if(fd == -1 )
		{
				printf("socket socket %d 创建失败", i);
				printf("socket %d 创建失败", i);
		
		}	
		else
		{
				printf("socket socket %d 创建成功", fd);
		}
	}	
	sleep(1);
	return 0;
}
