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
//模板特化, 拷贝来自于  /root/trunk/Baselib/dump.cpp
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
* Description	: 一般把从shell_exec 执行返回的字符串进行分割. 
* @param 	
*		stringlist 输出, 
*		soruce 		要被分割的句子.	
*		separator 	分割符号.
* @return, 	
****************************************************************************/
template<typename T>  void split(T & stringlist,const string& source,const string& separator=string("\n") )
{
	int start = 0;
	//fixme, unsigned int 会造成死循环 , why?  
	//unsigned int end = source.find_first_of(separator);
	int end = source.find_first_of(separator);
	while(end != string::npos)
	{
		stringlist.push_back(source.substr(start,end-start));
		start = end +1;
		end = source.find(separator,start);
	}
	//最后一行是空行 不要加入.
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
