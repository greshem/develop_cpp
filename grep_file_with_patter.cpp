//2012_04_01_10:12:52   星期日   add by greshem
//用   file_to_vector_string.cpp  grep.cpp 两个函数整理出来的, 主要供 sdcv 使用的
#include <algorithm>
#include <fstream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <vector> 

using namespace std;
int file_to_vector_string(string filename, vector<string> &out)
{
	//构造函数是 (char * , iso::in) 的参数. 
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

int grep(string pattern, vector<string> &in   )
{
	vector<string>::iterator it;
	for(it = in.begin(); it!= in.end(); it++)
	{
		if(strstr((*it).c_str(), pattern.c_str()))
		{
			//out.push_back(*it);
			cout<<*it<<endl;	
		}
	}
	return 1;
}

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		cout<<"Usage: "<<string(argv[0])<<" input_file matterh "<<endl;
		exit(1);
	}
	if( argv[1] ==NULL)
	{
		cout<<"Usage:"<<argv[0]<<" file"<<endl;
		exit(1);
	}

	string pattern(argv[2]);
	vector<string> vecStr;
	file_to_vector_string(string(argv[1]), vecStr);
	//grep (vecStr,  pattern);
	grep (pattern, vecStr);

	return 0;
}
