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
#include <typeinfo>
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

using namespace std;
template <typename T, long long  i> void f()
{
	//int a=33;
	cout<<"\t" << typeid(T).name() << " print "<<i <<"times"<<endl;
	//i*i;
}
int main(int argc, char *argv[])
{
	f<int, 1000>();
	f<float, 1000>();
	f<vector<string> , 100>();
	return 0;
}
