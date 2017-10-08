
//########################################################################
//#include <dirent.h>
//#include <QzjUnit.hpp>
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
//#include <Baselib.hpp>
//#include <gtest/gtest.h>
//#include <unitlib.h>
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
#include <sys/time.h>

using namespace std;

int file_to_vector_string(string filename, vector<string> &out)
{
	//fstream file(filename.c_str() , ios::in);
	fstream file(filename.c_str() , ios::in);
	if(! file)
	{
		cout<<"file open file error"<<endl;
	}
	string line;
	while(std::getline(file, line, '\n'))
	{
		out.push_back(line);
	}
	return 1;
}

int init_random()
{
	timeval tm;
	gettimeofday(&tm, NULL);
	srandom(tm.tv_sec + tm.tv_usec);
}
int main(int argc, char *argv[])
{ 
	vector<string> vec_str;
	if( argc!=2 )
	{
		printf("Usage: %s [file] \n", argv[0] );
		exit(-1);
	}
	else
	{
		file_to_vector_string(argv[1], vec_str);	
	}
	init_random();


	random_shuffle(vec_str.begin(),vec_str.end());

	for (vector<string>::iterator iter=vec_str.begin();iter!=vec_str.end();iter++)
	{
		cout <<*iter<<endl;;
	}
}
