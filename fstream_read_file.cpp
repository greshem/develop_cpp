#include <stdlib.h>
//#include <MLmyUnit.hpp>
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
using namespace std;
int main(int argc, char *argv[])
{
	string str;
	if(argv[1] ==NULL)
	{
		cout<<"Usage:"<<argv[0]<<"  file"<<endl;
		exit(0);
	}
	cout<<"istream_read.cpp"<<endl;
	fstream in(argv[1], ios::in);
	//两者还是有有区别的. 
	//if( in.bad())
	//if(!in.is_open())
	//{
	//	cout<<"file open error"<<endl;
//	}
	while(in >> str)
	{
	cout<<str<<endl;
	}
	return 0;
}
