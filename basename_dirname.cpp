#include <algorithm>
#include <dirent.h>
#include <fstream>
#include <gtest/gtest.h>
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
//2010_10_09 by greshem. 


using namespace std;
int main(int argc, char *argv[])
{
	
	for(int i=0; i<=100; i++)
	{
		//cout<<RandString<char>(10);
		//cout<<RandPath<char>(10)<<endl;
		MString<char>  tmp =RandFilePath<char>(10).c_str();
		cout<<tmp << "\t -> "<< tmp.dirname() << "-> \t"<<tmp.basename()<<endl;
	}
	return 0;
}
