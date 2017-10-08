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
//########################################################################
template <typename T1, typename T2> class test3
{
public:
	int operator () ();
	
};
template<typename T1, typename T2> int test3< T1, T2>::operator()()
{
	cout<<"====="<<endl;
	return 1;
}

//template<int,int> int test3<int, int> ::operator ()()
template<> int test3<int, int> ::operator ()()
{
	cout<<"int , int"<<endl;
	return 1;
}

using namespace std;
int main(int argc, char *argv[])
{
	test3<int, int>  func;
	func();
	return 1;
}
