#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
#include <Baselib.hpp> 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
//#include <dirent.h>
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
//2010_07_07 by qzj. 
using namespace std;
struct info
	{
	int a;
	int b;
	int c;
	int e;
	string name;
	};
int main(int argc, char *argv[])
{
	//struct info test[300]={{111,222,333,444,"qianqian"}};
	//struct info test[300]={1111}; warning  you should {{}} is much better. 
	//struct info test[300]={{111,222,333,444,"qianqian"}};
	
	//only [0] init
	//struct info test[300]={{111,222,333,444,"qianqian"},};
	

//	struct info test[300]={111,222,333,444,"qianqian"};


	struct info test[300]={0,0,0,0,"qianqian"};


	MString<char>  str("struct_init.cpp");
	cout<<str.c_str()<<endl;
	cout<<"struct_init.cpp"<<endl;
	cout<<test[0].a<<endl;
	cout<<test[100].name<<endl;
	return 0;
}
