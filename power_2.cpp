#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <Baselib.hpp>
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
#include <gtest/gtest.h>
//2010_09_13 by greshem. 


using namespace std;
int main(int argc, char *argv[])
{
	unsigned long long a=1;

	for(int i=0; i<64; i++)
	{
		a=(1<<i);
		printf(" %d  | %llu\n",i,  a);
	}
	return 0;
}
