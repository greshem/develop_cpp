#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
#include <Baselib.hpp> 
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
//2010_07_15 by qzj. 
using namespace std;
int main(int argc, char *argv[])
{
	
	FILE *fp	;
	int  i=0;
//	while(1)
	
	for(int i=0;i<=2;i++)
	{
		MString<char>  file;
		file=RandString<char> (10).c_str();
		file+=".abcde";
		fp=fopen(file.c_str(), "w");
		if(fp ==NULL)
		{
			break;
			printf("�����ļ�  %s �����ļ��� , �ۼƴ����ļ�����Ϊ %d", file.c_str(), i);
			warn<char> (" �ļ����ܴ����� %d\n", i);
		}	
		else
		{
			fprintf(fp, "%s\n", file.c_str());
			i++;
		}
	}
	return 0;
}
