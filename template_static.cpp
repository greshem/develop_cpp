#include <stdlib.h>
//#include <unitlib.h>
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
//2011_03_31 by greshem. 

template < typename T> class X
{

	public:
		static T s;
		T b;
};

template<class T> T X<T>::s=NULL;
using namespace std;
int main(int argc, char *argv[])
{
	X<int> b;
	cout<<b.b<<endl;
	cout<<b.s<<endl;
}
