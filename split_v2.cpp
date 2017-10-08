//########################################################################
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
#include <Baselib.hpp>
//

#include <gtest/gtest.h>
#include <fstream>
#include <string> 
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
using namespace std;

//========================================================================
//ģ���ػ�, ����������  /root/trunk/Baselib/dump.cpp
template <> void dump(vector<string> & in)
{
	typedef vector<string>::iterator IT;
	IT it;
	for(it=in.begin(); it!=in.end(); it++)
	{
		cout<< *it <<"|"<<endl;
	}
}
/****************************************************************************
* Description	: һ��Ѵ�shell_exec ִ�з��ص��ַ������зָ�. 
* @param 	
*		stringlist ���, 
*		soruce 		Ҫ���ָ�ľ���.	
*		separator 	�ָ����.
* @return, 	
****************************************************************************/
template<typename T>  void split(T & stringlist,const string& source,const string& separator=string("\n") )
{
	int start = 0;
	//fixme, unsigned int �������ѭ�� , why?  
	//unsigned int end = source.find_first_of(separator);
	int end = source.find_first_of(separator);
	while(end != string::npos)
	{
		stringlist.push_back(source.substr(start,end-start));
		start = end +1;
		end = source.find(separator,start);
	}
	//���һ���ǿ��� ��Ҫ����.
	//stringlist.push_back(source.substr(start,source.length()-start));
}

using namespace std;
int main(int argc, char *argv[])
{
	vector<string> vecStr;
	//string ret=
	string result=shell_exec<char>(string("seq 1 100"));
	//cout<< result;
	split<vector<string> > (vecStr, result, "\n");
	dump<>(vecStr);
}
