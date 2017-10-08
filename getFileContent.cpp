
//#2010_11_19_ add by greshem
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

// generic form of addElementToSet for containers like set and list
template<class C,class V >
void addElementToSet(C &c, const V &v)
{
	c.insert(v);
}

// specialized version for vector
template<> void addElementToSet<vector<string>,string>(vector<string> &c, const string &v)
{
	c.push_back(v);
}

// read a file into the specified container
// depends on addElementToSet, STL file stream, and STL getline algorithm
template<class T>
bool populate_set_from_file(T &s1,const char *file_name)
{
	ifstream file_in;
	string line_from_file;

	file_in.open(file_name);
	if(file_in.fail()){
		cout << "Error opening file [" << file_name << "] - please check file name" << endl;
		return false;
	}
	try{	
		getline(file_in,line_from_file);
		while(file_in.good())
		{
			addElementToSet(s1,line_from_file);
			getline(file_in,line_from_file);
		}
	}
	catch(bad_alloc &e)
	{	
		cout << "Error - Caught Exception: " << e.what() << endl;
		throw e;
		return false;
	}

	file_in.close();
	return true;
}

//template <class T>
template < typename T> int  dump_all( T &in)
{
	typedef typename T::iterator IT;
	for(IT it=in.begin(); it!= in.end(); it++)
	{
		cout<< *it<< endl;
	}
	return 1;
}

int main()
{
	vector<string> contain;
	populate_set_from_file< vector<string> > (	contain, "/etc/passwd");
	dump_all(contain);
}
