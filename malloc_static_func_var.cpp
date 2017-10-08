
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
//2011_04_21 by greshem. 

//########################################################################
int free_after_10_package(int i)
{
	static int  *data=NULL;
	//ÐÂµÄ°ü. 
	if(i%10==0)
	{
		data=(int *)malloc(1024*sizeof(int));
		data[i%10]=i;
	}
	else if( i%10 == 9)
	{
		data[i%10]=i;
		free(data);
	}		
	else
	{
		data[i%10]=i;
	}
	return i;
}

//########################################################################
using namespace std;
int main(int argc, char *argv[])
{
	for(int i=0; i<=10240;i++)
	{
		free_after_10_package(i);	
	}
}
