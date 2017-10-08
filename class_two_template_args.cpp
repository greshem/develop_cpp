//########################################################################
// 2011_03_31_17:16:43   星期四   add by greshem
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
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

template <typename T1, typename T2> class test3
{
public:
	int operator () ();
	void go(){};
};

template<typename T1, typename T2> int test3< T1, T2>::operator()()
{
	cout<<"====="<<endl;
	return 1;
}
//偏特化第二个参数为 int 
//template <typename T1, int> class test3{ 这里写错了.  //ERROR
template <typename T1> class test3<T1,int> {
public:
	int operator () ();
	void go();
};
template<typename T1> void test3<T1, int>::go ()
{
	cout<<"other , int"<<endl;
	return 1;
}

template<class T> int test3<T, int>::operator ()()
{
	cout<<"other , int"<<endl;
	return 1;
}



//template<int,int> int test3<int, int> ::operator ()() //ERROR
template<> int test3<int, int> ::operator ()()
{
	cout<<"int , int"<<endl;
	return 1;
}

//template<typename T,int> int test3<T, int> ::operator ()()



using namespace std;
int main(int argc, char *argv[])
{
	test3<int , int> func;
	func();
	return 1;
}
