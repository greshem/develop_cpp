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
//###################################################
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <gtest/gtest.h>
//2010_11_26 by greshem. 
//class BookPrint;
using namespace std;

class book {
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
	friend ostream& operator <<(ostream& os,const book & p)
	{
		os<<p.name<<" "<<p.sn<<" "<<p.path<<endl;;
		return os;
	}
	//qzj 
	friend class BookPrint;
	friend class BookPrint2;//, 不是友元就不能访问类的内部了. 
};

class  BookPrint{
public:		
	int printWithMemFun (book &in )
	{
		cout<<in.getName()<<endl;
		cout<<in.getSn()<<endl;
		cout<<in.getPath()<<endl;	
		return 1;
	}
		
	int print (book &in)
	{
		cout<<in.name<<endl;;
		cout<<in.sn<<endl;
		cout<<in.path<<endl;
		return 1;
	}
};

class  BookPrint2
{
public:		
	int printWithMemFun (book &in )
	{
		cout<<in.getName()<<endl;
		cout<<in.getSn()<<endl;
		cout<<in.getPath()<<endl;	
		return 1;
	}
		
	int print (book &in)
	{
		cout<<in.name<<endl;;
		cout<<in.sn<<endl;
		cout<<in.path<<endl;
		return 1;
	}
};


using namespace std;
int main(int argc, char *argv[])
{

	//MString<char> str("book_friend_class.cpp");
	string  str("book_friend_class.cpp");
	
	book  a;
	BookPrint print;
	BookPrint2  print2;

	print.print(a);
	print2.print(a);

	cout<<str.c_str()<<endl;
	return 0;
}
