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
//2010_08_23 by qzj. 

template <typename T> class book {
};

using namespace std;
int main(int argc, char *argv[])
{
	MString<char> str("ifstream_append.cpp");
	//std::ifstream pswd("./passwd", std::ios::app); //���ַ�ʽ����д���κ�����. 	
	std::ofstream pswd("./passwd"); 	//���ַ�ʽ��������ļ���д���ݡ� 
	//std::ofstream pswd("./passwd", std::ios::app);	append ��ʽд�ļ��� 
	if( ! pswd.good())
	{		
		die<char>("create file error\n");
	}
	for(int i=0;i <=100; i++)
	{
		 pswd << i<<endl;;

		cout<< i;
	}	
	return 0;
}
