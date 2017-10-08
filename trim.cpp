#include <algorithm>
#include <fstream>
//#include <gtest/gtest.h>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <vector> 
using namespace std;



//Description: trim left string 
string ltrim(string const &str) 
{
	for (unsigned i = 0; i < str.size(); i++)
	{
		if (!isspace(str[i]))
		{
			return str.substr(i);
		}
	}
	return "";
}

//Description: trim right string 
string rtrim(string const &str) 
{
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (!isspace(str[i]))
		{	
			return str.substr(0, i + 1);
		}
	}
	return "";
}

string trim(string const &str) 
{
	return rtrim(ltrim(str));
}


using namespace std;
int main(int argc, char *argv[])
{

	string space("		bbbbbb 		");
	string space2("		bbbbbb 		\n\n\n\n");
	cout<<trim(space)<<"|"<<endl;
	cout<<trim(space2)<<"|"<<endl;
	cout<<space.size()<<endl;
	cout<<space2.size()<<endl;
	cout<<space2.length()<<endl;
	return 0;
}

