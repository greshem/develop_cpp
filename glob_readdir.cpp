//########################################################################
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
#include <Baselib.hpp>
#include <gtest/gtest.h>
#include <fstream>

#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif

//#include <dirent.h>
#include <string> 
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  

int Glob(string in, vector<string> &vecStr)
{
    DIR *dirp;
    struct dirent *dp;
    if( (dirp=opendir(in.c_str())) ==NULL)
    {   
        printf(" opendir etc error\n");
        return 1; 
    }   
    while(dp=readdir(dirp))
    {   
        if(dp->d_type==DT_REG)
        {   
            vecStr.push_back(in+"/"+string(dp->d_name));
        }   
    }   
    return 1;
}

using namespace std;
int main(int argc, char *argv[])
{
	vector<string> files;
	Glob("/etc/", files);
	copy(files.begin(), files.end(), ostream_iterator<string>(cout, "\n"));
	return 0;
}
