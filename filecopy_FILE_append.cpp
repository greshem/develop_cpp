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
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

using namespace std;
int main(int argc, char *argv[])
{
	char buffer[4096];
	
	if(argc < 2)
	{
	printf("Usage: %s in_file  in_file1 file2 file3     out_file \n", argv[0]);
	exit(0);
	}

	FILE* out=fopen(argv[argc-1], "w+");
	if(out== NULL)
	{
		die<char>("create  dest file error\n");		
	}

	for(int i=1;i< argc-1; i++)
	{
		FILE * fd=fopen(argv[i], "r");
		if(fd ==NULL)
		{
			die<char>("open file error\n");		
		}

		int ret=0;
		while( (ret=fread( buffer, 1, sizeof(buffer),fd))>0)
		{
			fwrite( buffer, 1, ret, out);	
		}
		fclose(fd);
	}
	fclose(out);
	//assert(filesize<char>(argv[1]) == filesize<char>(argv[2]));
	return 0;
}
