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
//########################################################################
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//#include <gtest/gtest.h>


using namespace std;
long long power_2(long long in);
int main(int argc, char *argv[])
{
	
	if(argc!=2)
	{
		die<char>("usage: %s  number", argv[0]);
	}
	long long len=power_2(atoll(argv[1]));
	MFile<char> disk;
	disk.Create("test.img");
	disk.SetFileLength(len);	
	disk.Close();
	return 0;
}

long long power_2(long long in)
{
	int i=0;
	while( (in =(in>>1)) )
	{
		//cout<<number<<endl;
		i++;
	}
	in=	(in+1)<<(i+1);
	return in;
}

