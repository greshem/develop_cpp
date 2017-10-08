//########################################################################
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
//#include <Baselib.hpp>
//#include <gtest/gtest.h>
#include <string> 
#include <set> 
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


// determines the differences between the contents of two containers
// output is written to parameter 3
template<class container_type,class value_type>
void Container_Differences(const container_type &container1,const container_type &container2, container_type &result_grp) 
{
	container_type temp;
	typedef typename container_type::const_iterator IT;
	IT iter_pos_grp, iter_found_at;

//#2010_11_19_23:24:38 add by greshem
//原来的写法是	container_type::const_iterator  iter_pos_grp, iter_found_at;, 可以考虑一下错误的原因


	if(&container1 != &container2)
	{
		iter_pos_grp=container1.begin();
		while(iter_pos_grp!=container1.end())
		{
			iter_found_at=find(container2.begin(),container2.end(),(*iter_pos_grp));
			if(iter_found_at==container2.end())
				addElementToSet(temp,(*iter_pos_grp));
			++iter_pos_grp;
		}
		
		iter_pos_grp=container2.begin();
		while(iter_pos_grp!=container2.end())
		{
			iter_found_at=find(container1.begin(),container1.end(),(*iter_pos_grp));
			if(iter_found_at==container1.end())
				addElementToSet(temp,static_cast<value_type>((*iter_pos_grp)));
			++iter_pos_grp;
		}
	}
	temp.swap(result_grp);
}

// prints an element to screen
// used by for_each (that is called in main)
void printElement(const string &e){
	cout << e << endl;
}


int main(int argc, char* argv[])
{

	// make sure we've got the correct number of arguments...
	if(argc!=3)
	{
		
		cout << "compareFiles - copyright (c) Essam Ahmed 2000" << endl << endl;
		cout << "This program compares the conents of two files and prints" << endl 
			<< "the differences between the files to the screen" << endl << endl;
		cout << "Usage: compareFiles <file_name_1> <file_name_2>" << endl << endl;
		return 0;
	}

	// declare the containers that will be used throughout
	typedef set<string> stringSet;
	// you can easily change the type of container this app works with by
	// replacing the previous line with any one of these:
	//
	// typedef vector<string> stringSet;
	// typedef list<string> stringSet;

	stringSet s1, s2,s3;

	// read the contents of the first file into a set
	if(!populate_set_from_file(s1,argv[1])){
		cout << "There was a problem reading from " << argv[1] << endl 
			<< "Exiting..." << endl;
		return 1;}
		
	cout << "Contents of Set 1" << endl << endl;
//	for_each(s1.begin(),s1.end(),printElement);

	// read the contents of the second file into a set
	if(!populate_set_from_file(s2,argv[2])){
		cout << "There was a problem reading from " << argv[2] << endl 
			<< "Exiting..." << endl;
		return 1;}
	cout<<"##########################"<<endl;
	cout << endl << "Contents of Set 2" << endl << endl;
//	for_each(s2.begin(),s2.end(),printElement);
		
	// compare the sets, store the difference in s3
	Container_Differences< stringSet,string > (s1,s2,s3);

	// display the result...
	cout << endl << "Difference is:" << endl;
	for_each(s3.begin(),s3.end(),printElement);
	
	return 0;
}

