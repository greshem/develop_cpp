#include <algorithm>
#include <fstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <libgen.h>
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
//#include <gtest/gtest.h>
//2010_08_25 by qzj. 


using namespace std;
int main(int argc, char *argv[])
{

	char tmp[1024]="/aa/bb/cc/dd/eff/ffgg";
	printf("%s\n", dirname(tmp));
	printf("%s\n", basename(tmp));
	printf("%s\n", tmp);
	return 0;
}
