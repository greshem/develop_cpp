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
//tmp 根据需要进行分配 20100708.qzj
using namespace std;
void putChar( char *tmp, int size);

char *file_seek64_and_read(FILE * file, int offset, int count, int * readLen)
{
	char *buffer;
	int ret;
	buffer=(char *)malloc(count);
	memset(buffer, '\0', count);
	lseek64(fileno(file), 0, SEEK_END);
	long long  length=lseek64(fileno(file), 0, SEEK_CUR);

	//请求的offset 大于文件的长度。 
	if( offset > length)
	{
		warn<char>(" offset is larger than fileSize %d", length);
		return NULL;
	}

	//在文件末尾的时候, 读取的字节会< count. 	
	if(length -offset < count)
	{
		fseek(file, offset, SEEK_SET);
		//写成  fread(tmp, sizeof(tmp), 1 , file)返回 读取了几个结构
		ret=fread(buffer, 1, count,   file);
		if(ret != count)
		{
			warn<char>(" read length not correct \n");
		}
		//*readLen=ret;	
		*readLen=ret;
		return buffer;
	}
	else
	{
		fseek(file, offset, SEEK_SET);
		ret=fread(buffer, 1,count, file);
		if(ret != count)
		{
			warn<char>(" read length not correct \n");
		}
		//putChar(tmp, count);
		*readLen=ret;
		return buffer;
	}	
}


int main(int argc, char *argv[])
{
	FILE *file;
	//char tmp[512];
	unsigned int count;
	if(argc < 3)
	{
		die<char>("Usage: %s file offset [readcount]", argv[0]);
	}
	
	file=fopen(argv[1] , "r");

	if(file==NULL)
	{
		die<char>("open file %s", argv[0]);
	}
	int offset=atoi(argv[2]);
	
	if(argv[3])
	{
		count=atoi(argv[3]);
	}
	else
	{
		 count=512;
	}

	int readLen;
	char *data=file_seek64_and_read(file, offset, count, &readLen);
	putChar( data, readLen);

	return 1;
}
void putChar( char *tmp, int size)
{
	for (int i=0; i<size ; i++)
	{
		putchar(tmp[i]);
	}
}
