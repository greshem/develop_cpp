#include <unistd.h>
#include <stdexcept>
#include <iostream>
#include <Baselib.hpp>
#include <gtest/gtest.h>
#include <fstream>
//#include <dirent.h>
#include <string> 
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  

using namespace std;
template <typename T> string stringify(T const &t) 
{
	ostringstream os;
	os << t;
	return os.str();
}
int main()
{
	cout<<stringify(33)<<endl;
}

