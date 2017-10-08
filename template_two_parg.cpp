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
//2010_08_11 by qzj. 

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
int main(int argc, char *argv[])
{
	book<char> one;	
	cout<<one.getName()<<endl;
	cout<<"float\t"<< one.getOther<float>()<<endl;
	cout<<"bool\t"<< one.getOther<bool>()<<endl;
	cout<<"int\t"<< one.getOther<int>()<<endl;
	//cout<<"string\t"<< one.getOther<string>()<<endl;
	
	return 0;
}
