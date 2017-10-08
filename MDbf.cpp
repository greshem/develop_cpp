//###################################################
//#include <gtest/gtest.h>
#include <fstream>
//#include <dirent.h>
#include <string> 
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <Baselib.hpp>
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include "MDbfFile.hpp"

using namespace std;
int main(int argc, char *argv[])
{
	
	cout<<"sizeof(Dbfhead )"<< sizeof(tagDbfHead)<<endl;
	cout<<"sizeof(field)"<< sizeof(tagDbfField)<<endl;
	if(argc != 2)
	{
		die<char>("Usage: %s file.dbf\n", argv[0]);
	}	
	MMemoryDbfFile dbf;
	if(	dbf.Open(argv[1]) != 1)
	{
		die<char>("open  file error\n");
	}
	dbf.First();
	char buffer[256];
	int count=dbf.GetFieldCount();	
	while(dbf.Next())
	{	
		for(int i=0; i<count;i++)
		{
			dbf.ReadString((unsigned short) i,(char *) buffer, (unsigned short)sizeof(buffer));
			printf("%s|", buffer); 
		}
		printf("\n");
	}


	return 0;
}
