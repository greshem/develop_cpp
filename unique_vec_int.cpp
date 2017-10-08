
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
#include <dirent.h>

using namespace std;

int main(int argc, char *argv[])
{
	vector<int> vec_int;
	vec_int.push_back(1);
	vec_int.push_back(1);
	vec_int.push_back(2);
	vec_int.push_back(3);
	
	vec_int.erase(unique(vec_int.begin(), vec_int.end()),  vec_int.end() );

	for(vector<int>::iterator it=vec_int.begin(); it!= vec_int.end(); it++)
	{
		cout<<*it<<"|";
	}
	cout<<endl;
}
