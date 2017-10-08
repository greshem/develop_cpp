#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
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
#include <gtest/gtest.h>
//2010_09_15 by greshem. 
// 用来处理文件拷贝时候的sed  的替换工作的， 不支持， sed , sed 没法处理二进制
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

using namespace std;
int main(int argc, char *argv[])
{
	char buffer[4096];
	
	if(argc != 3)
	{
	printf("Usage: %s in_file out_file \n", argv[0]);
	exit(0);
	}
	int fd=open(argv[1], O_RDONLY, 00777);
	if(fd < 0)
	{
		die<char>("open file error\n");		
	}
	int out=open(argv[2], O_CREAT|O_RDWR);
	if(out< 0)
	{
		die<char>("create  file error\n");		
	}
	int ret=0;
	while( (ret=read(fd, buffer, sizeof(buffer)) )>0)
	{
		char *tmp=NULL;
		while(tmp=strstr(buffer, "reboot"))
		{
			memcpy(tmp, "wenwen", 6);
		}
		write(out, buffer, ret);	
	}
	close(out);
	close(fd);
	assert(filesize<char>(argv[1]) == filesize<char>(argv[2]));
	return 0;
}
