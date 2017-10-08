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
//#include <gtest/gtest.h>
//2010_09_17 by greshem. 

// break  30 if i==100; 
// break 31 
// 可是我想查看一部分的循环， 如何呢？ 看了一部分的循环， 我看烦了， 想直接跳出循环。 

int main2(int argc, char *argv[]);

using namespace std;
int main(int argc, char *argv[])
{
	int j=0;

	main2(argc, argv);
	for(int i=0; i<=100; i++)
	{
		j+=i;	
	}
	cout<<j<<endl;
	cout<<j+1<<endl;
	//cout<<str.c_str()<<endl;
	return 0;
}
int main2(int argc, char *argv[])
{
	int j=0;
	for(int i=0; i<=100; i++)
	{
		j+=i;	
	}
	cout<<j<<endl;
	cout<<j+1<<endl;
	//cout<<str.c_str()<<endl;
	return 0;
}
