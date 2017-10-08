//########################################################################
//#include <dirent.h>
//#include <QzjUnit.hpp>
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
//#include <Baselib.hpp>
//#include <gtest/gtest.h>
//#include <unitlib.h>

#include <fstream>
#include <string> 
#include <sstream>
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h> 
using namespace std;

using namespace std;
int main(int argc, char *argv[])
{
	string str("main.cpp");
	cout<<str.c_str()<<endl;

	vector<string> vec_str;
	int i=0;
	for(i=0; i<=100; i++)
	{
		vec_str.push_back("linux");
	}

	assert(vec_str.size() == 101);

	vec_str.clear();

	assert(vec_str.size() == 0);
	vec_str.push_back("linux");
	assert(vec_str.size() == 1);


	return 0;
}
