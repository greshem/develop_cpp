
// 	string s("hello, world");
//     string head("hello");
//     string tail("ld");
//     bool startwith = s.compare(0, head.size(), head) == 0;
//     cout << boolalpha << startwith << endl;
//     bool endwith = s.compare(s.size() - tail.size(), tail.size(), tail) == 0;
//     cout << boolalpha << endwith << endl;

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
int endwith(const  string &  long_str,  const  string &  tail) 
{
	if(tail.length() == 0)
	{
		return 0;
	}	
	bool endwith = long_str.compare(long_str.size() - tail.size(), tail.size(), tail) == 0;
	return endwith;
}

void test_unit(string long_str,  string tail );
using namespace std;
int main()
{
	test_unit("file.exe", "exe");
	test_unit("file.exe &", "&");
	test_unit("file.exe &  ", "&");
	test_unit("file.exe", "dll");
	test_unit("file.exe", "");
	test_unit("/var/www/html/", "/");
}

void test_unit(string long_str,  string tail )
{
	if(endwith(long_str, tail)	)
	{
		printf("OK:  |%s| endwith |%s| \n",  long_str.c_str(),  tail.c_str());
	}
	else
	{
		printf("NOT_OK:  |%s| not endwith |%s| \n",  long_str.c_str(),  tail.c_str());
	}

}
