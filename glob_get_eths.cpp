#include <iostream> 
#include <map>
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif

#include <glob.h>
#include <gtest/gtest.h>
#include <fstream>
#include <string> 
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
//2010_07_13 by qzj. 
//#2010_08_20_15:36:17 add by qzj
using namespace std;
int  glob_sys_eths(string in,  vector<string> &out);

int main(int argc, char *argv[])
{
  	vector<string> vecStr; 
	glob_sys_eths("*", vecStr);
	copy(vecStr.begin(), vecStr.end(), ostream_iterator<string>(cout, "\n"));

	return 0;
}
int  glob_sys_eths(string in,  vector<string> &out)
{
	
	glob_t gl;
    int ret;
	ret=glob("/sys/class/net/eth*", 0, NULL, &gl);
	int count=gl.gl_pathc;
	for(int i=0;i<count;i++)
	{
		out.push_back( gl.gl_pathv[i] );
	} 
	globfree(&gl);
	return  count;

}
//###############################################################################
//glob_t  的主要的结构是
//  { 	__size_t gl_pathc;
//		char **gl_pathv;
//		.
//		.
//		.
//		.
//	}

