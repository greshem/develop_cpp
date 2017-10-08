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
//2010_06_29 by qzj. 
using namespace std;
void putChar( char *tmp, int size);
int main(int argc, char *argv[])
{
	FILE *file;
	char tmp[512];
	int ret;
	if(argc != 3)
	{
		die<char> ("Usage: %s file offset ", argv[0]);
	}

	file=fopen(argv[1] , "r");
	if(file==NULL)
	{
		die<char>  ("open file %s", argv[0]);
	}
	int offset=atoi(argv[2]);
	fseek(file, 0, SEEK_END);

	int length=	ftell(file);

	if( offset > length)
	{
		die<char> (" offset is larger than fileSize %d", length);
	}
	
	if(length -offset < 512)
	{
		int readLen=length-offset;
		fseek(file, offset, SEEK_SET);
		//写成  fread(tmp, sizeof(tmp), 1 , file)返回 读取了几个结构
		ret=fread(tmp, 1, sizeof(tmp),   file);
		if(ret != readLen)
		{
			die<char> (" read length not correct \n");
		}	
		//printf("%s\n", tmp);
		putChar(tmp, ret);
		return 1;
	}
	else
	{
		fseek(file, offset, SEEK_SET);
		ret=fread(tmp, 1,512, file);
		if(ret != 512)
		{
			die<char> (" read length not correct \n");
		}
		putChar(tmp, 512);
		return 1;
	}	
	return 1;
}
void putChar( char *tmp, int size)
{
	for (int i=0; i<size ; i++)
	{
		putchar(tmp[i]);
	}
}
