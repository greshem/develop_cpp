
#include <gtest/gtest.h>
#include <fstream>
#include <string> 
#include <sstream>
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
using namespace std;
int function1()
{
	static int i=0;
	i++;
	cout<<i<<endl;
}
int main()
{
	for(int i=0; i<=100; i++)
	{
		function1();
	}
}
