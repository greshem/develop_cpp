//###################################################
#include <fstream>
//#include <dirent.h>
#include <string> 
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
#include <Baselib.hpp>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
using namespace std;
template <typename T, bool isClonable>   class Traits
{
};

template <typename T>   class Traits<T,true>
{
public:
	void clone(T* pObj)
	{
		cout << "before cloning Clonable type" << endl;
		//pObj->clone();
		cout << "after cloning Clonable type" << endl;
	}
};

template <typename T > class Traits<T, false>
{
public:
	void clone(T* pObj)
	{
		cout << "cloning non Clonable type" << endl;
	}
};
int main()
{
	int a=11;
//	Traits<int, true> tmp;
	Traits<int, true> test;
	Traits<int, false> test2;
	test.clone( &a);
	test2.clone(&a);
	return 0;
};

