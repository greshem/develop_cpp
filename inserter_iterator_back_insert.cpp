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
//2010_11_25 by greshem. 


using namespace std;
int main(int argc, char *argv[])
{
	vector<int> vecInt;
	int i=0;
	for(i=1; i<=10000;i++)
	{
		vecInt.push_back(i);
	}
	vector<int>::iterator it_start, it_end;

	it_start=vecInt.begin();
	it_end=vecInt.end();


	vector<int> vecInt2(it_start+5, it_end);
	for(int j=0; j<=1000;j++)
	{
		vecInt2.push_back(++i);
	}
	
	vector<int> result;


	//set_union
	//set_intersection (vecInt.begin(), vecInt.end(), vecInt2.begin(), vecInt2.end(), result.begin());
	//swap(result);
	//result.swap();
	//获取 第一中独特的东西
	//set_difference  (vecInt.begin(), vecInt.end(), vecInt2.begin(), vecInt2.end(), result.begin());
	//获取 第二中独特的东西
	set_difference  (vecInt2.begin(), vecInt2.end(), vecInt.begin(), vecInt.end(),   inserter(result, result.begin() ) );
	//set_difference  (vecInt2.begin(), vecInt2.end(), vecInt.begin(), vecInt.end(),   back_inserter(result) );
	//back_inserter
	//inserter(sc,sc.begin()))
	//dump_all<vector<int> > (result);	
	return 0;
}
