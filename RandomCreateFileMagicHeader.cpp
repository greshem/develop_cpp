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
//2010_07_22 by qzj. 

//�� file  �����ݿ�����α�����ݣ�"/usr/share/misc/magic" , �ļ��� 
using namespace std;
int main(int argc, char *argv[])
{
	long pcxMagic=987654321;
	FILE *fp=fopen("file.pcx", "w") ;
	if(fp==NULL)
	{
		die<char> ("create file error\n");
	}
	fwrite(&pcxMagic , sizeof(long), 1 , fp);
	fclose(fp);
	return 0;
}
