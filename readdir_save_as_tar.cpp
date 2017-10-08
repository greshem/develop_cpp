//########################################################################
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
#include <Baselib.hpp>

#include <gtest/gtest.h>

#include <fstream>
#include <string> 
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
int find(char *in, vector<string> &out)
{
	//printf("##### %s\n", in);
	string pwd(in);
	static char cwd[1024];
	DIR *dirp;
	struct dirent *dp;
	if((dirp=opendir(pwd.c_str() ) )==NULL)
	{
		printf("opendir error\n");
		return -1;
	}
	chdir(pwd.c_str());
	getcwd(cwd, 1024);

	while((dp=readdir(dirp)))
	{
		if(dp->d_type==DT_DIR)
		{
			if(strcmp(dp->d_name, ".")==0)			
			{
				continue;
			}
			if(strcmp(dp->d_name,"..") == 0)
			{
				continue;
			}

			//printf("%s/%s", cwd, dp->d_name);
			 char    path[1024];
			memset(path, '\0', 1024);
			sprintf(path, "%s/%s", pwd.c_str(), dp->d_name);
			find(path, out );
		}
		else//(dp->d_type==DT_FILE)
		{
			//printf("%s/%s\n",cwd, dp->d_name);
			char file[1024];
			sprintf(file, "%s/%s", pwd.c_str(), dp->d_name);
			out.push_back(file);
		}
	}
	closedir(dirp);
return 0;
}

int copy_append(MFile<char> dest, MFile<char> src)
{
//	dest	
}
int main()
{
	vector<string> names;
	find("/etc/", names);
//	copy(names.begin(), names.end(),  ostream_iterator<string>(cout, "\n"));
//
	
}
