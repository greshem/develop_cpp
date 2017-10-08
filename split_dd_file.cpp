#include <algorithm>
#include <fstream>
#include <gtest/gtest.h>
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
//2010_08_26 by qzj. 
//可以用 split -a 4 -b 4096 -d test.img block. 实现同样的效果。 

using namespace std;
#define BLOCK 4096
int main(int argc, char *argv[])
{
	char buffer[BLOCK]	;
	if(argc!=2)
	{
		die<char>("Usage: %s file ", argv[0]);
	}		
	MFile<char> image;
	if(image.Open(argv[1]) != 1)
	{
		die<char>("open file error");
	}

	int ret;
	int i=0;
	MString<char> seq;
	while( (ret=image.Read(buffer, BLOCK ))  == BLOCK)
	{
			seq.FormatString("block.%4.4d", i);	
			cout<<seq.c_str()<<endl;
			MFile<char> block;
			block.Create(seq);
			if(block.Write(buffer, BLOCK)== ret)
			{
			}
			else
			{
				cout<< seq.c_str()<<"写入失败"<<endl;
			}
			block.Close();	
	
			i++;
	}
	if(ret > 0)
	{	
		cout<<"last frame "<<i<< "size => "<<ret<<endl;	
	}
	return 0;
}
