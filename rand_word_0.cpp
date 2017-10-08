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
#include <time.h>
#include <vector> 
//########################################################################
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//#include <gtest/gtest.h>

using namespace std;
int main(int argc, char *argv[])
{
	timeval tv;
	gettimeofday(&tv, NULL);
#ifdef WINDOWSCODE
	srand(100);
#else
	srandom(tv.tv_sec+tv.tv_usec);
#endif
	
//	while(1)
	for(int i=0;i<=100; i++)
	{
		//srandom(tv.tv_sec+tv.tv_usec);
		string tmp=RandWord<char>();
		cout<<tmp<<endl;
	}
	return 0;
}
