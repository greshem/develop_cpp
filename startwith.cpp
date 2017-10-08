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
using namespace std;

//if shortString length is zero, error 
bool startWith(string longString, string shortString)
{
	if(shortString.length() == 0)
	{
		return 0;
	}
    return longString.find(shortString) == 0;
}

int test_unit(string long_str,  string short_str);
int main(int argc, char *argv[])
{
	test_unit("cd /home", "cd");
	test_unit("cd /home", "cd ");
	test_unit("cd      /home", "cd ");
	test_unit("echo      /home", "echo");
	test_unit("clr      /home", "clr");
	test_unit("clr", "clr");
	test_unit("a", "a");
	test_unit("aa", "aa");
	test_unit("aaa", "aaa");
	test_unit("aaaa", "aaaa");


	//ERROR: 
	test_unit("clr", "");
	test_unit("", "bbb");

	return 0;
}
int test_unit(string long_str,  string short_str)
{
	if(startWith(long_str, short_str))
	{
		printf("OK: %s start with %s \n", long_str.c_str(), short_str.c_str());
	}
	else
	{
		printf("NOT_OK: %s no start with %s \n", long_str.c_str(), short_str.c_str());
	}
	return 0;
}
