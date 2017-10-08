
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

template <typename  T>  int dump_type( T &in)
{
	return 1;
}; 


template<>  int dump_type(int &in)
{
	cout<<"int "<<in<<endl;
	return 1;
};

template<>  int dump_type(char* &in)
{
	cout<<"char *"<<in <<endl;
	return 1;
}

	
template<>  int dump_type(inner &in)
{
	cout <<"a "<<in.a<<"\t |b"<< in.b<<endl;
	return 1;
}

int main(int argc, char *argv[])
{
	int a=100;
	inner b={100, 200};
	dump_type<>(a);
	dump_type<>(b);
	return 0;
}
