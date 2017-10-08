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
//2010_08_12 by qzj. 

typedef struct dummy {} DUMMY;

using namespace std;
int main(int argc, char *argv[])
{
	vector<vector<int> > vec;
	MString<vector<int> > str("null_type.cpp");
	MString<DUMMY>  test;
	cout<<str.c_str()<<endl;
	cout<<"null_type.cpp"<<endl;
	return 0;
}
