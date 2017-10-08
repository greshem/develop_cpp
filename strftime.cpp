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
#include <time.h>
#include <vector> 
//#include <Baselib.hpp> 
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//2010_07_16 by qzj. 

using namespace std;
int main(int argc, char *argv[])
{
	char buffer[1024];
	time_t t;
	t=time(NULL);
	strftime(buffer, sizeof(buffer), "%Y_%m_%d_%T", localtime(&t));
	printf("%s", buffer);
	return 0;
}
