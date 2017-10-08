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
//2010_08_23 by qzj. 

using namespace std;

template <typename T> class book ;

template <typename T> class book 
{
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
		template <typename S> S  getOther();
};

template < typename T>   template <typename G>  G book<T>::getOther()
{
	return G();
}


using namespace std;
int main(int argc, char *argv[])
{
	string  str("template_two_args.cpp");
	cout<<str.c_str()<<endl;
	cout<<"template_two_args.cpp"<<endl;
	return 0;
}
