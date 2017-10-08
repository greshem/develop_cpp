#include <stdlib.h>
//#include <unitlib.h>
//#include <QzjUnit.hpp>
//#include <Baselib.hpp>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
#include <dirent.h>
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
#include <gtest/gtest.h>
//2011_03_31 by greshem. 

using namespace std;
using namespace std;
//########################################################################
// 一个参数的 模板特化
template<typename T1 > int test2()
{
	T1 b;
	return 1;
}

template <int> int test2()
{
	return 1;
}
//########################################################################
// 两个参数的模板特化, 函数.  
template<typename T1, typename T2 > int test()
{
	cout<<"this is a"<<endl;
	return 1;
}

template <typename T1, int> int test()
{
	cout<<"this is b "<<endl;
	return 1;
}

template <int, int> int test()
{
	cout<<"int, int "<<endl;
	return 1;
}

//########################################################################
// 两个参数的模板特化, 类的() 操作符. 
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

//########################################################################
//偏特化第二个参数为 int, 错误 一定把他 这个类先声明出来.  
//

//template < typename T1, int> class test3<T1, int> { //ERROR 
template < typename T1> class test3<T1, int> {
public:
	int operator () ();
	void go();
};

template<class T> int test3<T, int>::operator ()()
{
	cout<<"other , int"<<endl;
	return 1;
}

template<typename T1> void test3<T1, int>::go ()
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

//########################################################################
int main(int argc, char *argv[])
{
//	test<int, int>();
	test3<int, int> func;;
	func();
}
