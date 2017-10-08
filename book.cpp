#include <algorithm>
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
//########################################################################
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <gtest/gtest.h>
////#include <dirent.h>

using namespace std; 

template <typename T> class book {
private:
	string name;
	int 	sn;
	string 	path;
	public:
		book()
		{
			name="no name";
			sn=rand();
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
		os<<p.name<<" "<<p.sn<<" "<<p.path<<endl;;
		return os;
	}

};


using namespace std;
int main(int argc, char *argv[])
{
	book<char> test;
	cout<<test<<endl;;
	return 0;
}
