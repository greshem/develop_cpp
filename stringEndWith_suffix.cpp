
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

bool
StringEndsWith(const std::string &input, const std::string &end) 
{
    int len1 = input.length();
    int len2 = end.length();

    if (len2 >len1)
        return false;

    return (input.substr(len1-len2) == end);
}

int main()
{
	if(StringEndsWith("input.txt", "txt"))
	{
		cout<<"ok"<<endl;
	}
	else
	{
		cout<<"not ok "<<endl;
	}
}
