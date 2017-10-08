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
#include <gtest/gtest.h>

//#2010_12_22_12:48:22 add by greshem
typedef unsigned int uint;
//2010_09_25 by greshem. 
typedef  void ( * LPFN_srand)(unsigned int seed);
typedef  int ( * LPFN_rand)();

using namespace std;
int main(int argc, char *argv[])
{

	LPFN_srand mysrand=srand;
	LPFN_rand  myrand=rand;
	mysrand(getpid());
//	while(1)
	for(int i=0; i<=100; i++)
	{	
	cout<< myrand()<<endl;
	}
	return 0;
}
