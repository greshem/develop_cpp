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
using namespace std;


string  ucfirst(string const &str);
using namespace std;
int main(int argc, char *argv[])
{

	string test="china, worick, avring , edcation ";
	string tmp=ucfirst (test);
	cout<<tmp<<endl;
	return 0;
}

/****************************************************************************
* Description: words 每个word 的首字母大写	
* @param 	
* @return 	
* *************************************************************************/
string  ucfirst(string const &str)
{
	string out;
	bool newword=true;
	for(string::const_iterator i =str.begin(); i!= str.end(); i++)
	{
		if(newword && isalpha(*i))
		{
			out+=toupper(*i);
			newword=false;
		}
		else
		{
			if(isspace(*i) || ispunct(*i))
			{
				newword=true;
			}
			out+=*i;
		}
	}
	return out;
}

