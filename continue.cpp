#include <stdlib.h>
#include <unitlib.h>
//#include <QzjUnit.hpp>
//#include <Baselib.hpp>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
#include <dirent.h>
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
#include <gtest/gtest.h>
//2011_02_25 by greshem. 


using namespace std;
int main(int argc, char *argv[])
{
	if(argc != 1)
    {
        printf("Usage: %s file_list \n", argv[0]);
        exit(-1);
    }
    printf("%s\n", "continue.cpp");
	int i=0;
	for (i=0; i<=100; i++)
	{
		if(i%2)
		{
			continue;
		}
		else
		{
			printf("%d do some things\n", i);
		}
	}
	return 0;
}
