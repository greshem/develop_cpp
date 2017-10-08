#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
//#include <dirent.h>
#include <fstream>
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map> 
using namespace std;
int Print(map< int, string>::iterator in)
{
	cout<<(*in).first<<"\t"<< (*in).second<<endl;
	return 1;
}
int IsExist(int i, map<int, string> &data);
int main(int argc, char *argv[])
{
	map< int, string> str_int_map;
	map< int, string>::iterator it;

	for(int i=0;i <= 100; i++)
	{
		str_int_map.insert(pair<int, string>(i, string("qianlong")));
	}
	
	for(int i=0; i<=110; i++)
	{
	IsExist(i, str_int_map);
	}
//	for_each(str_int_map.begin(), str_int_map.end(), Print);
	for(it=str_int_map.begin(); it!= str_int_map.end(); it++)
	{
		//Print(it);
	}

	cout<<"map.cpp"<<endl;
	return 0;
}
int IsExist(int i, map<int, string> &data)
{
	if(data.find(i)==data.end())
	{
		cout<<i<<"²»´æÔÚ"<<endl;
	}
	else
	{	
		cout<<i<<"´æÔÚ"<<endl;
	}
	return 0;
}
