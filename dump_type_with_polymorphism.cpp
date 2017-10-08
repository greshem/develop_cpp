//########################################################################
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
//#include <Baselib.hpp>
//#include <gtest/gtest.h>
//
// 2011_03_30_13:45:13   星期三   add by greshem
// 这个版本把 << 符号 写在程序的 内部了. 
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
	friend ostream & operator << (ostream &out , const struct _inner &in)
	{
		out<<"a "<<in.a<<"\t |b"<< in.b;
		return  out;
	}
}inner;

template <typename  T>  int dump_type( T &in)
{
	cout << in<<endl;
	return 1;
	
}; 

class Dump{
	public:
		static int Dumper(int &in)
		{
		cout<<"int "<<in<<endl;
			return 1;
		}	
		static int Dumper(char * &in)
		{
			cout<<"char "<<in<<endl;
			return 1;
		}
		static int Dumper(inner &in)
		{
			cout<<"a "<<in.a<<"\t |b"<< in.b<<endl;
			return 1;
		}
};
//把下面的所有的偏特化的版本都去掉了. 
// 
// template<>  int dump_type(int &in)
// {
// 	cout<<"int "<<in<<endl;
// 	return 1;
// };
// 
// template<>  int dump_type(char* &in)
// {
// 	cout<<"char *"<<in <<endl;
// 	return 1;
// }
// 
// 	
// template<>  int dump_type(inner &in)
// {
// 	cout <<"a "<<in.a<<"\t |b"<< in.b<<endl;
// 	return 1;
// }

int main(int argc, char *argv[])
{
	int a=100;
	inner b={100, 200};
	Dump::Dumper(a);
	Dump::Dumper(b);
	return 0;
}
