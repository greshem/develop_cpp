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
	if( argv[1] ==NULL)
	{
		cout<<"Usage:"<<argv[0]<<" file"<<endl;
		exit(0);
	}
	vector<string> vecStr;
	cout<<"vector_file_str.cpp"<<endl;
	fstream file(argv[1], ios::in);
	string line;
	while(std::getline(file, line, '\n'))
	{
		//cout<<line<<endl;
		vecStr.push_back(line);
	}

	copy(vecStr.begin(), vecStr.end(), ostream_iterator<string>(cout,"\n"));
	return 1;
}
