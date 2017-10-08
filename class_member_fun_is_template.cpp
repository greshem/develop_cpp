#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
#include <Baselib.hpp>
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
//2010_11_25 by greshem. 

//###################################################

 class Tools
{
public:
	template < typename  T > ostream&  print(ostream& os,const T& p)
	{
		os<<"Tools shift operator "<< p<<endl;
		return os;
	}

	template < typename  T > ostream&  print2(ostream& os, T p)
	{
		os<<"Tools shift operator "<< p<<endl;
		return os;
	}


};


using namespace std;

int main(int argc, char *argv[])
{

	MString<char> str("class_member_is_template.cpp");
	cout<<str.c_str()<<endl;
	Tools b;
	string a("qianqinn");
	b.print<string> (cout, a);
	b.print2<string> (cout, " #### wenwenwen");
	return 0;
}
