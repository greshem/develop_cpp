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
//2010_07_13 by qzj. 
using namespace std;
int main(int argc, char *argv[])
{
	//for( int i=0; i<=(sizeof(sys_errlist)/sizeof(sys_errlist[0]));i++)
	for( int i=0; i<=255 ;i++)
	{
		if(sys_errlist[i] != NULL)
		{ 
			printf("%d, %s\n", i, sys_errlist[i]); 
		}
	}
	return 0;
}
