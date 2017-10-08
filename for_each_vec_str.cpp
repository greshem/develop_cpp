//########################################################################
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
//#include <Baselib.hpp>
#include <gtest/gtest.h>
#include <fstream>
#include <string> 
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>

using namespace std;
template <typename T> class print
{
	public:
	int operator () (T &in)
	{
		cout<< in<<endl;
		return 1;
	}
};

//print_fun
int main(int argc, char *argv[])
{
	vector<string> vecStr;
	vecStr.push_back("test1");
	vecStr.push_back("test2");
	vecStr.push_back("test3");
	vecStr.push_back("test4");
	vecStr.push_back("test5");
	//========================================================================
	//ok.
	print<string>  a;	
	for_each(vecStr.begin(), vecStr.end(), a );

	//========================================================================
	//注意区别.  这里都是错误的. 
	//for_each(vecStr.begin(), vecStr.end(), print<string>  );
	//for_each(vecStr.begin(), vecStr.end(), print<string>);

}

