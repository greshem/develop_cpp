#include <stdlib.h>
//#include <MLmyUnit.hpp>
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
using namespace std;
int main(int argc, char *argv[])
{
	cout<<"fstream_save.cpp"<<endl;
	if(argv[1]==NULL)
	{
		cout<<"Usage: "<<argv[0]<<"\tout_file"<<endl;
		exit(0);
	}
	std::fstream fs;
	fs.open(argv[1], std::fstream::out);
	if(!fs.is_open())
	{
		cout<<"open file error"<<endl;
		exit(-1);
	//throw ("open file error\n");
	}
	for(int i=0; i<=100; i++)
	{
		fs<<i<<endl;
	}

	return 0;
}
