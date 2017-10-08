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
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//#include <gtest/gtest.h>
//2010_08_24 by qzj. 
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
};

using namespace std;
int main(int argc, char *argv[])
{

	string  str("class.cpp");
	cout<<str.c_str()<<endl;
	return 0;
}
