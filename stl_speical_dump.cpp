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

template< > string  MyRand()
{
	string tmp=RandString<char> (10);
	return tmp;
}
template<> int MyRand()
{
	int tmp=rand();
	return tmp;
}



using namespace std;
template<class T> int init( vector<T> &in)
{
	typedef typename vector<T>::iterator IT;
	IT it;
	for(it=in.begin(); it!=in.end(); it++)
	{
		*it=MyRand<T>();
	}
	
	return 1;
}

namespace stl_special_dump
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
	using stl_special_dump::dump;

	vector<string> vecStr(100);
	vector<int> vecInt(10);
//	int vecStr;
	//for(int i=0; i<=100; i++)
	//{
	//	vecStr.push_back("qqq");
//	}
	init(vecStr);		
	init(vecInt);

	
	//for(int i=0; i<=100; i++)
//	{
//		vecInt.push_back(i);
//	}

	dump<vector<string> > (vecStr);
	cout<<"###########################"<<endl;
	dump<vector<int> > (vecInt);
//	test<int>(3333);
	return 0;
}
