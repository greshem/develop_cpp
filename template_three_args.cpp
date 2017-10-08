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

template <typename T,  typename S> class book {
private:
	string name;
	int 	sn;
	string 	path;
	S other;
	public:
		book()
		{
			name="no name";
			sn=0;
			path="no path";
			other=S();
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
	S  getOther()
	{
		return  !S();
	}
};

using namespace std;
int main(int argc, char *argv[])
{
	book<void , float> test;
	cout<<test.getOther()<<endl;;	
	return 0;
}
