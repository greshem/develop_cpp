#include <stdlib.h>
//#include <MLmyUnit.hpp>
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
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif


#include <glob.h>
//glob_t  的主要的结构是
//  { 	__size_t gl_pathc;
//		char **gl_pathv;
//		.
//		.
//		.
//		.
//	}
//2010_07_13 by qzj. 
using namespace std;
int main(int argc, char *argv[])
{
    glob_t gl;
    int e;
	for(int j=0;j<=8;j++)
	{
		e=glob("*", 0, NULL, &gl);
		int count=gl.gl_pathc;
		for(int i=0;i<count;i++)
		{
		//	printf("%s\n",gl.gl_pathv[i]);
		} 
    
	
	globfree(&gl);
	}
	return 0;
}
