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


using namespace std;
int file_get_content(string file, string &out);

int main(int argc, char *argv[])
{
	
	string  str("file_get_content.cpp");
	string passwd("/etc/passwd");

	string output;
	
	file_get_content( passwd, output);
	cout<<output<<endl;
	return 0;
}


/****************************************************************************
* Description: 	
* @param :
* 		file: 输入的文件名  
* 		out: 传入的string 引用, 文件 append 的方式传入out. 	
* @return 	
* *************************************************************************/
int file_get_content(string file, string &out)
{
	fstream 	 in(file.c_str(), ios::in);
	string line;
	if(in.bad())
	{
		printf("file open error\n");
		return 0;
	}
	while ( std::getline(in, line, '\n') )
	{
		out+=line;
		out+="\n";
	}
	in.close();
	return 1;	
}

