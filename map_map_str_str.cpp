#include <iostream> 
#include <iterator> 
#include <map> 
#include <string> 
#include <stdlib.h>
#include <stdio.h> 
using namespace std;
int main(int argc, char *argv[]) 
{
	map < string, string > map_str;
	map_str.insert(make_pair("aaaa", "bbbb"));
	map_str.insert(make_pair("aaaa", "bbbb"));
	map_str["wenwen"] = "qianqian";
	map < string, string >::iterator it;
	for (it = map_str.begin(); it != map_str.end(); it++)
		
	{
		cout << (*it).first <<"||||"<< (*it).second << endl;
	}
	//getchar();
	return 0;
}


