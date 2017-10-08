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
//#include <gtest/gtest.h>
//2010_08_24 by qzj. 

using namespace std;
int main(int argc, char *argv[])
{

	string str("test__TEMPLATE__");
	cout<<str_replace<char> ("__TEMPLATE__", "198308190917", str)<<endl;;
	return 0;
}
