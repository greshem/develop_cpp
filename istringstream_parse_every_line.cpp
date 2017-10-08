#include <stdlib.h>
#include <fstream> 
#include <iostream> 


#include <gtest/gtest.h>
#include <fstream>
#include <string> 
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

int line_to_vec_string(string &in, vector<string> &vec_str)
{
	istringstream istr(in);
	string tmp;
	while(istr>>tmp)
	{
		vec_str.push_back(tmp);	
	}	
	return 1;
}

int dump(vector<string> &vec_str)
{
	vector<string>::iterator it;
	for(it=vec_str.begin(); it!= vec_str.end(); it++)
	{
		cout<<*it<<"|";
	}
	cout<<endl;
	return 1;
}

int main(int argc, char *argv[])
{
	//没有这样的调用的方式。 
	//fstream file(string(argv[1]),ios::in);
	if(argc != 2)
	{
		cout<<"Usage: "<<argv[0]<<" input file \n";
		return -1;
	}	
	fstream file(argv[1],ios::in);
	if(file.bad())
	{
		cout<<"file open error"<<endl;;
		exit(-1);
	}
	string line;
	vector<string> vec_str;	

	while(std::getline(file,line, '\n' ))
    {
		vec_str.clear();
		line_to_vec_string(line, vec_str);		
		dump(vec_str);
	}
}
