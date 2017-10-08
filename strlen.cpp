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
	for(int i=0; i< argc; i++)
	{
		printf("%s-> %d\n", argv[i], strlen(argv[i]));
	}
	return 0;
}
