
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
int main(int argc, char *argv[])
{
	ostream ostr;
	istringstream istr;
	string tmp;
//	ostr.str(tmp);	
	
	ostr<<"bbbb"<<"|";
	ostr<<"bbbb"<<"|";
	ostr<<"bbbb"<<"|";
	ostr<<"bbbb"<<"|";
	ostr<<"bbbb"<<"|";

	ostr<<"bbbb"<<"|";

    istr>>tmp;
	//ostr >> tmp;
	cout<<tmp;
}
