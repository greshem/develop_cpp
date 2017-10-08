#include <algorithm>
#include <dirent.h>
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
//#include <gtest/gtest.h>
//2010_11_10 by greshem. 


using namespace std;
int main(int argc, char *argv[])
{
	string sys="qianzhongjie.sys";
	string name=str_replace<char>(".sys", "", sys);
	cout<<name<<endl;
	return 0;
}
