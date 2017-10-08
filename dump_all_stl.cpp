//########################################################################
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
//#include <Baselib.hpp>
//#include <gtest/gtest.h>
#include <fstream>
#include <string> 
#include <iostream>
#include <map>
#include <list> 
#include <deque> 
#include <set> 
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
using namespace std;
template <class T> 
int dump_all( T &in )
{
	typedef typename T::iterator IT;
	IT it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		cout<<*it<<endl;
	}
	return 1;
}
int main()
{
	vector<string> test;
	test.push_back("tesat");	
	test.push_back("tesat");	
	test.push_back("tesat");	
	test.push_back("tesat");	
	test.push_back("tesat");	
	test.push_back("tesat");	
	test.push_back("----------");	
	dump_all(test);

	list<string> test2;
	test2.push_back("tesat");	
	test2.push_back("tesat");	
	test2.push_back("tesat");	
	test2.push_back("tesat");	
	test2.push_back("tesat");	
	test2.push_back("--------");	
	dump_all(test2);

	deque<string > test3;
	test3.push_back("tesat");	
	test3.push_back("tesat");	
	test3.push_back("tesat");	
	test3.push_back("tesat");	
	test3.push_back("tesat");	
	test3.push_back("---------");	
	dump_all(test3);

}
