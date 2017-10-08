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
#include <vector> 
//#include <Baselib.hpp> 
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//2010_07_15 by qzj. 

using namespace std;
static void * __stdcall work (void *in)
{
	//while(1)
	for(int i=0;i<=2;i++)
	{
		printf("i am thread \n");
#ifdef WINDOWSCODE
		Sleep(1000);
#else
		sleep(1);
#endif
	}
}
int main(int argc, char *argv[])
{
	
	MThread <char> thread;
	thread.StartThread("test1", work, NULL);
	thread.StartThread("test1", work, NULL);
	
	FILE *fp	;
	int  i=0;
//	while(1)
	for(int i=0;i<=2;i++)
	{
		MString<char> file;
		file=RandString<char>(10).c_str();
		file+=".abcef";
		fp=fopen(file.c_str(), "w");
		if(fp ==NULL)
		{
			printf("创建文件 %s 不能文件了 , 累计创建文件个数为 %d", file.c_str(), i);
			printf(" 文件不能创建了 \n");
			exit(-1);
		}	
		else
		{
			fprintf(fp, "%s\n", file.c_str());
			i++;
		}
	}
	return 0;
}
