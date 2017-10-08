#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#include <dirent.h>
#endif
#include <vector> 
#include <iostream> 
#include <algorithm>
using namespace std;
int Print(string &in)
{
	cout<<"/etc/"<<in<<endl;
	return 1;
}
int main(int argc, char *argv[])
{
	vector<string> vecStr;
	DIR *dirp;
	struct dirent *dp;
	if( (dirp=opendir("/etc")) ==NULL)
	{
		printf(" opendir etc error\n");
		return -1;
	}
	while(dp=readdir(dirp))
	{
		if(dp->d_type==DT_REG)
		{
			vecStr.push_back(dp->d_name);
		}
	}
	
	for_each(vecStr.begin(), vecStr.end(), Print);
	return 0;
}
