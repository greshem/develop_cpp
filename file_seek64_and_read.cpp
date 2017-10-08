//###################################################
#include <gtest/gtest.h>
#include <fstream>
//#include <dirent.h>
#include <string> 
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <Baselib.hpp>
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  

char *file_seek64_and_read(FILE * file, int offset, int count, int * readLen)
{
	char *buffer;
	int ret;
	buffer=(char *)malloc(count);
	memset(buffer, '\0', count);
	lseek64(fileno(file), 0, SEEK_END);
	long long  length=lseek64(fileno(file), 0, SEEK_CUR);

	//�����offset �����ļ��ĳ��ȡ� 
	if( offset > length)
	{
		warn<char>(" offset is larger than fileSize %d", length);
		return NULL;
	}

	//���ļ�ĩβ��ʱ��, ��ȡ���ֽڻ�< count. 	
	if(length -offset < count)
	{
		fseek(file, offset, SEEK_SET);
		//д��  fread(tmp, sizeof(tmp), 1 , file)���� ��ȡ�˼����ṹ
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

int main()
{
	return 0;
}
