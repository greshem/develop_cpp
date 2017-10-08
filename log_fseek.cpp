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
//2010_07_13 by qzj. 

using namespace std;
int log(FILE *fp, char *format, ...);
int main(int argc, char *argv[])
{
	FILE *out;
	
	out=fopen("test.log", "w");
	if(out==NULL)
	{
		printf ("create file error\n");
		exit(-1);
	}
	for(int i=0; i<=1000; i++)
	{
		log( out, "log log log log log %d\n", i);
	}	
}

//========================================================================
int log(FILE *fp, char *format, ...)
{	
	static char tmp[1024];
	memset(tmp,'\0', sizeof(tmp));
	va_list(marker);
	va_start(marker, format);
	vsprintf(tmp, format, marker);
	va_end(marker);
	fprintf(fp,"%s\n", tmp);
	if(ftell(fp)> 1024*1024*1)
	{
		printf("截断日志 当前偏移 %d", ftell(fp));		
		fseek(fp, 0,SEEK_SET);
	}
	return 1;
}
