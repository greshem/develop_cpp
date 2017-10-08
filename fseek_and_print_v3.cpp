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
//tmp ������Ҫ���з��� 20100708.qzj
using namespace std;
void putChar( char *tmp, int size);
int main(int argc, char *argv[])
{
	FILE *file;
	char tmp[512];
//	char *tmp;
	int ret;
	unsigned int count;
	if(argc < 3)
	{
		die<char>  ("Usage: %s file offset [readcount]", argv[0]);
	}
	if(argv[3])
	{
		count=atoi(argv[3]);
	}
	else
	{
		 count=512;
	}

//	tmp=(char *)malloc(count);
	file=fopen(argv[1] , "r");
	if(file==NULL)
	{
		die<char> ("open file %s", argv[0]);
	}
	long  offset=atol(argv[2]);
	fseek(file, 0, SEEK_END);

	long long  length=	ftell(file);

	if( offset > length)
	{
		die<char> (" offset is larger than fileSize %d", length);
	}
	
	if(length -offset < count)
	{
		int readLen=length-offset;
		fseek(file, offset, SEEK_SET);
		//д��  fread(tmp, sizeof(tmp), 1 , file)���� ��ȡ�˼����ṹ
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
		ret=fread(tmp, 1,count, file);
		if(ret != count)
		{
			die<char> (" read length not correct \n");
		}
		putChar(tmp, count);
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
