#include <stdlib.h>
//#include <MLmyUnit.hpp>
//20100706  reinterpret_cast 强制转换的时候， 还是不能把离开的比较远的类型强制转化.
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
int main(int argc, char *argv[])
{
	MString <char> str("reinterpret_cast.cpp");
	float b=33333;
	//void* c=reinterpret_cast<void*> (str) <<endl;
	int* c=reinterpret_cast<int*> (4444) ;
	cout<<static_cast<int> (b) <<endl;
	//cout<<static_cast<int> (str) <<endl;
	//int d=(int)(*c);
	//cout<<d;
	return 0;
}
