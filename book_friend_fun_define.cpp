#include <algorithm>
#include <dirent.h>
#include <fstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <vector> 
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <gtest/gtest.h>
//2010_11_25 by greshem. 
using namespace std;

//###################################################
template <typename T> class book {
private:
	string name;
	int 	sn;
	string 	path;
	public:
		book()
		{
			name="no name";
			sn=0;
			path="no path";
		};
	string getName()
	{
		return name;
	}
	int getSn()
	{
		return sn;
	}
	string getPath()
	{
		return path;
	}
	template <typename S> S  getOther()
	{
		return  !S();
	}
	
	friend ostream& operator <<(ostream& os,const book<T>& p)
	{
		os<<"--------------------------"<<endl;
		os<<"name:\t"<< p.name<<"\n sn:\t"<<p.sn<<"\npath:\t"<<p.path<<endl;;
		return os;
	}

	friend book<T> operator +   (book<T> &a, book<T> &b)
	{
		return  add(a, b);
	}

	friend book<T>  add (book<T> &a, book<T> &b)
	{
		book<T> test;
		test.sn=a.sn+b.sn+1;
	
		test.path=a.path;
		test.path+="|";
		test.path+=b.path;
	
		test.name=a.name;
		test.name+="|";
		test.name+=b.name;
		return test;
	}

};

	

using namespace std;
int main(int argc, char *argv[])
{

	string  str("book_friend_fun.cpp");
	cout<<str.c_str()<<endl;
	book<char> test, test1;
	book<char> result;
	cout<<test<<endl;
	cout<<test1<<endl;
	cout<<test+test1<<endl;	
	//cout<< result<<endl;
	return 0;
}
