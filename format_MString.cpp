#include <algorithm>
#include <fstream>
#include <gtest/gtest.h>
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
//2010_08_23 by qzj. 

template <typename T> class book {
};

using namespace std;
int main(int argc, char *argv[])
{

	MString<char> str("format_string.cpp");
	for(int i=0; i<=100; i++)
	{
	
		str.FormatString("line %d %d %d\n", i , 2 ,3);
		file_put_content<char>("test.dat", str.c_str(), 1);
	}
	return 0;
}
