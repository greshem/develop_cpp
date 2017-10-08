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
//#include <gtest/gtest.h>
////#include <dirent.h>
//2010_08_25 by qzj. 


using namespace std;
int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s number", argv[0]);
		exit(-1);
	}
		
	long long  number=atol(argv[1]);
	cout<<number<<endl;
	cout<<"################"<<endl;
	int i=0;
	while( (number=(number>>1)) )
	{
		//cout<<number<<endl;
		i++;
	}
	number=	(number+1)<<(i+1);
	
	cout<<number	<<endl;
	return 0;
}
