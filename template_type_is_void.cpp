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
template <typename T>
struct is_void
{
	enum {
		_M_type=0
		};
};

template <>	struct is_void<void>
{
	enum {
		_M_type=1
		};

};
int main(int argc, char *argv[])
{
	/*struct  __is_pod<string> b;
	if( a )
	{
		cout<<"string is not pod"<<endl;
	}*/
	is_void<void> a;
	if(a._M_type)
	{
		cout<<"is void"<<endl;
	}
	else
	{
		cout<<"not void"<<endl;
	}
	
	return 0;
}
