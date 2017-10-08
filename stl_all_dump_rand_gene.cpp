#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
#include <Baselib.hpp> 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
//#include <dirent.h>
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
//2010_07_07 by qzj. 
template< class T> T  MyRand()
{
	T tmp;
	return tmp;
}

//template< class string > T MyRand()
//20100714.
//模板特例化不是上面这种方式进行特例化的。 
template<  > string  MyRand()

{
	string tmp=RandString<char> (10);
	return tmp;
}

using namespace std;
template<class T> int init(T &in)
{
	typedef typename T::iterator IT;
	IT it;
	for(it=in.begin(); it!=in.end(); it++)
	{
		*it=MyRand<T>();
	}
	return 1;
}

namespace stl_all_dump_rand_gene
{
	template< class T> int  dump(T &in)
	{
		//typedef T::iterator it;
		typedef typename   T::iterator IT;
		IT it;
	
		for(it=in.begin(); it!= in.end(); it++)
		{
			cout<<*it<<endl;
		}
		return 1;
	}
}

template <class T> int test(T in)
{
	cout<< in<<endl;
	return 1;
}
int main(int argc, char *argv[])
{
	using stl_all_dump_rand_gene::dump;

	vector<string> vecStr;
//	int vecStr;
	for(int i=0; i<=100; i++)
	{
		vecStr.push_back("qqq");
	}
	vector<int> vecInt;
	
	for(int i=0; i<=100; i++)
	{
		vecInt.push_back(i);
	}

	dump<vector<string> > (vecStr);
	dump<vector<int> > (vecInt);
//	dump<int>(vecStr);
//	test<int>(3333);
	return 0;
}
