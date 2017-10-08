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
//#include <dirent.h>
//#include <gtest/gtest.h>
//2010_09_10 by greshem. 


using namespace std;
int main(int argc, char *argv[])
{
	
	if(argc != 2)
	{
		die<char>("Usage: %s length \n", argv[0]);
	}
	
	unsigned	int length=atoi( argv[1]);

	MString<char> filename;
	filename.FormatString("%d", length);
	filename+=".nothing";

	MFile<char> output;
	output.Create(filename);	

	//一行带上换行符有1024个字节。 
	int line_len=132;
	int line_count=length/line_len;
	
	MString<char> fill;
	int i=0;
	for(i=0; i<line_count; i++)
	{
		fill.FormatString("%d", i);
		MString <char> tmp( fill.c_str(), line_len-1);
		tmp+="\n";
		output.Write(tmp.c_str(), line_len);		
	}

	//尾行填充
	if( (length%line_len) !=0)
	{
		fill.FormatString("%d", i);
		MString<char> last(fill.c_str(), length%line_len-1);
		last+="\n";
		output.Write(last.c_str(), length%line_len);
	}
	output.Close();
	assert(length== filesize<char>(filename.c_str()));
	return 0;
}
