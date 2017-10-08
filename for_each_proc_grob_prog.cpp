#include <iostream> 
#include <map>
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif

#include <glob.h>
#include <gtest/gtest.h>
#include <fstream>
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
using namespace std;
int  glob_stl(string in,  vector<string> &out);
vector<string>  get_pids();



//替换.
string str_replace( const string & pattern, const string &replacement, const string & strIn) 
{
    string out=strIn;
    string::size_type pos=0;
    string::size_type srclen=pattern.size();
    string::size_type dstlen=replacement.size();
    while( (pos=out.find(pattern, pos)) != string::npos)
    {   
        out.replace(pos, srclen, replacement);
        pos += dstlen;
    }       
    return out;
}


//########################################################################
//是否是数值.
bool test_is_number(const char buff[], int len)
{
    for(int i=0; i<len; i++)
    {   
        if(buff[i]<'0'||buff[i]>'9')
        {   
                return false;
        }   
        else
        {   
            return true;
        }   
    }   
    return true;
}
bool test_is_number(string string)
{
	return test_is_number(string.c_str(), string.size());
}

//获取pid 的 vector<string> 
vector<string>  get_pids()
{
	vector<string> vec_pids;
	vector<string> all;
	glob_stl("/proc/*", all);
	struct stat st;
	for(vector<string>::iterator it=all.begin(); it != all.end(); it++)
	{
		if( stat((*it).c_str(), &st)==0)
		{
			if( (st.st_mode & S_IFMT) == S_IFDIR)
			{
				string tmp=str_replace("/proc/", "", (*it));
				if(test_is_number(tmp))
				{	
					vec_pids.push_back(tmp);
				}
			}
		}
	}

	return vec_pids;
}
//	
int  glob_stl(string pattern,  vector<string> &out)
{
	
	glob_t gl;
    int ret;
	ret=glob(pattern.c_str(), 0, NULL, &gl);
	int count=gl.gl_pathc;
	for(int i=0;i<count;i++)
	{
		out.push_back( gl.gl_pathv[i] );
	} 
	globfree(&gl);
	return  count;

}
//###############################################################################
//glob_t  的主要的结构是 可以参看 /root/develop_cpp/glob.cpp 目录 



int main(int argc, char *argv[])
{
	int loop_count=1024;
	for(int i=0; i<=loop_count; i++)
	{
		vector<string> vecStr=get_pids() ;
		//cout<< "总数"<<vecStr.size()<<endl;
	}
	//copy(vecStr.begin(), vecStr.end(), ostream_iterator<string>(cout, "\n"));
	return 0;
}

