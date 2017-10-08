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
#define BLOCK_SIZE 4096
//2010_06_29 by qzj. 
//tmp 根据需要进行分配 20100708.qzj
using namespace std;
void putChar( char *tmp, int size);

int main(int argc, char *argv[])
{
	FILE *file;
	//char tmp[512];
	unsigned int count;
	if(argc <= 2)
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
		 count=BLOCK_SIZE;
	}

	int readLen;
	char *data=file_seek64_and_read<char>(file, offset, count, &readLen);
	putChar( data, readLen);

	return 1;
}

void putChar( char *tmp, int size)
{
	for (int i=0; i<size ; i++)
	{
		//putchar(tmp[i]);
		write(1, tmp+i, 1);
	}
}
