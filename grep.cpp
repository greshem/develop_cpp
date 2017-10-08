//########################################################################
//#include <dirent.h>
//#include <QzjUnit.hpp>
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
//#include <Baselib.hpp>
//#include <gtest/gtest.h>
//#include <unitlib.h>
#include <fstream>
#include <string> 
#include <sstream>
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
using namespace std;


using namespace std;

int grep(string pattern, vector<string> &in ,  vector<string>& out  )
{
	out.clear();
	vector<string>::iterator it;
	for(it = in.begin(); it!= in.end(); it++)
	{
		if(strstr((*it).c_str(), pattern.c_str()))
		{
			out.push_back(*it);
		}
	}
	
	return out.size();
}
void test0();
void test();
void empty();



int main(int argc, char *argv[])
{
	test();
	test0();
	empty();
	return 0;
}
//功能测试.
void test0()
{
	vector<string> haystack;
	haystack.push_back("/root/aa");
	haystack.push_back("/root/aa");
	haystack.push_back("/root/aa");
	haystack.push_back("/root/aa"); 
	haystack.push_back("/var/www/html");
	haystack.push_back("/var/www/html");
	haystack.push_back("/var/www/html");
	
	vector<string> tmp;
	grep("root", haystack,  tmp);
	assert(tmp.size()== 4);

}
//参数为空的测试.
void test()
{
	vector<string> haystack;
	vector<string> tmp;
	haystack.push_back("/root/aa");
	haystack.push_back("/root/aa");
	haystack.push_back("/root/aa");
	haystack.push_back("/root/aa"); 
	haystack.push_back("/var/www/html");
	haystack.push_back("/var/www/html");
	haystack.push_back("/var/www/html");
	
	grep("", haystack,  tmp);
	//strstr 第二个参数为空 就返回为 找到了.
	//assert(tmp.size()==0);
	assert(tmp.size()==haystack.size());

	grep("/", haystack, tmp);
	assert(tmp.size()== haystack.size());
}
//参数为空的情况的测试.
void empty()
{
	vector<string> haystack;
	vector<string> tmp;
	grep("any_pattern", haystack, tmp);
	assert(tmp.size()==0);
	grep( "2_any_pattern", haystack,  tmp);
	assert(tmp.size()==0);
}
