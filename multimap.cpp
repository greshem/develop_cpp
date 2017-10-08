#include <algorithm>
#include <dirent.h>
#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <vector> 
//########################################################################
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>

using namespace std;
int main(int argc, char *argv[])
{
	multimap<int , string> mmap;
	mmap.insert(pair<int, string>(1, "tst2"));
	mmap.insert(pair<int, string>(1, "tst22"));
	mmap.insert(pair<int, string>(1, "tst234"));
	mmap.insert(pair<int, string>(1, "tst24"));
	mmap.insert(pair<int, string>(1, "tst24"));

	mmap.insert(pair<int, string>(2, "tst24"));
	mmap.insert(pair<int, string>(2, "tst24"));
	mmap.insert(pair<int, string>(2, "tst24"));
	mmap.insert(pair<int, string>(2, "tst24"));
	mmap.insert(pair<int, string>(2, "tst24"));
	mmap.insert(pair<int, string>(2, "tst24"));
	mmap.insert(pair<int, string>(2, "tst24"));
	mmap.insert(pair<int, string>(2, "tst24"));
	mmap.insert(pair<int, string>(2, "tst24"));
	
	multimap<int, string>::iterator it;
	it=mmap.find(2);
	if(it != mmap.end())
	{
	}	

	//multimap<int, string>::iterator it;
	for(it=mmap.begin(); it != mmap.end(); it++)
	{
		cout<< (*it).first<<"|"<<(*it).second<<endl;
	}

	cout<<"count all of  2 Is "<<mmap.count(2)<<endl;
}

