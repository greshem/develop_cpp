#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
//#include <dirent.h>
#include <fstream>
#include <vector> 
#include <iostream> 
#include <algorithm>
using namespace std;
int Print(int i)
{
	cout<<i<<"\t";
	return 1;
}
int main(int argc, char *argv[])
{
	int a[]={0,1,3,4,5,6,7,8,9};
	vector<int> vecInt(a,a+9);
	vector<int>::iterator it;
	for_each(vecInt.begin(), vecInt.end(),Print);
	cout<<endl;
	for(it=vecInt.begin(); it!= vecInt.end(); it++)
	{
		if(*it==5)
		{
			vecInt.erase(it);
		}
	}
	for_each(vecInt.begin(), vecInt.end(),Print);
	cout<<endl;
	cout<<vecInt.size()<<endl;

	return 0;
}
