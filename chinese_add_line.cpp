//#include <Baselib>
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

//#2010_09_06_17:16:10 add by greshem
//#include <Baselib.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//#include <gtest/gtest.h>
//2010_08_26 by qzj. 

//char <0 ���������ˡ� , ���Լ����ڵ��÷���ͬ�ˣ� ���ư�ϲ���� unsigned char 
template <typename T> class book {
};

using namespace std;
int main(int argc, char *argv[])
{

	if(argc != 2)
	{
		die<char>("Usage: %s zh.file", argv[0]);
	}
	int LastIsZh=0;
	MFile<char> file;
	file.Open(argv[1]);
	char a;

	//char <0 ���������ˡ� 
	while(	file.Read((char *) &a, 1))
	{
		if(LastIsZh && a >0)
		{
			putchar('\n');
		}	

		if(a < 0)
		{
			LastIsZh=1;
		}
		else
		{
			LastIsZh=0;
		}
		
		putchar(a);	
		//printf("%d\n", a);
	}
	return 0;
}
