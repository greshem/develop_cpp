
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
//2011_05_09 by greshem. 


using namespace std;
typedef struct  _info
{
	int a;
	int b;
}info;
int set2(int &fd)
//int set2(int fd)
{
		fd=2;
	return 1;
}

int set(int& fd)
//int set(int fd)
{
	set2(fd);
	return 1;
}
int main(int argc, char *argv[])
{
	info array[100]={{0}};
	set2(array[0].a);		
	printf("%d\n", array[0].a);
	return 1;
}


