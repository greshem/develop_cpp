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
	vecInt.push_back(1);
	vecInt.push_back(2);
	vecInt.push_back(3);
	vecInt.push_back(4);
	vecInt.push_back(5);
	vecInt.push_back(6);
	vector<int>::iterator it_start, it_end;

	it_start=vecInt.begin();
	it_end=vecInt.end();


	vector<int> vecInt2(it_start+1, it_end-2);
	int ret=includes( vecInt2.begin(), vecInt2.end() , it_start, it_end);
	if(ret != 1)
	{
		cout<<"assert error"<<endl;
	}
	else
	{
		cout<<"includes ok"<<endl;
	}
	return 0;
}
