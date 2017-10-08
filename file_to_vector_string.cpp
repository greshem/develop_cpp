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
int main(int argc, char *argv[])
{
	if( argv[1] ==NULL)
	{
		cout<<"Usage:"<<argv[0]<<" file"<<endl;
		exit(0);
	}
	vector<string> vecStr;
	file_to_vector_string(string(argv[1]), vecStr);
    cout<<"size:"<<vecStr.size();
    //copy(vecStr.begin(), vecStr.end(), ostream_iterator<string>(cout,"\n"));
	return 0;
}
