#include <algorithm>
#include <error.h>
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
int main(int argc, char *argv[])
{
	for(int i=0; i<=512; i++)
	{
		printf("%d -> %s\n", i,  strerror(i));
	}
	return 0;
}
