
//########################################################################
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
//#include <Baselib.hpp>
//#include <gtest/gtest.h>
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
typedef struct  _inner {
	int a;
	int b;
}inner;


//========================================================================
//定义部分. 
template <typename T, typename RET_TYPE >  int dump_type( T &in)
{
	cout<<" ######## not match "<<endl;
	return 1;
}; 


//========================================================================
//实现部分. 
template<>  int dump_type<char, int> (char &in)
{
	cout<<"char , int "<<in<<endl;
	return 1;
};

template<>  int dump_type<char*, short> (char* &in)
{
	cout<<"char *, short "<<in <<endl;
	return 1;
}

	
template<>  int dump_type<inner, int >(inner &in)
{
	cout <<"a "<<in.a<<"\t |b"<< in.b<<endl;
	return 1;
}


//########################################################################
//下面是部分特化， 函数模板的部分的特化是不支持的. 
// template<typename RET_TYPE>  int dump_type<int, RET_TYPE> (int &in)
// {
// 	cout<<"int "<<in<<endl;
// 	return 1;
// };
// 
// template<typename RET_TYPE >  int dump_type<char*, RET_TYPE> (char* &in)
// {
// 	cout<<"char *"<<in <<endl;
// 	return 1;
// }
// 
// 	
// template<typename RET_TYPE >  int dump_type<inner, RET_TYPE>(inner &in)
// {
// 	cout <<"a "<<in.a<<"\t |b"<< in.b<<endl;
// 	return 1;
// }

int main(int argc, char *argv[])
{
	int a=100;
	inner b={100, 200};
	dump_type<int,void>(a);
	dump_type<inner,int>(b);
	return 0;
}
