#include <algorithm>
#include <fstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <vector> 
#include <unistd.h>

using namespace std;

//fixme, unsigned int dos  , why?  
//unsigned int end = source.find_first_of(separator);
void split(vector<string>  & stringlist,const string& source,const string& separator=string("\n") )
{
	int start = 0;
	int end = source.find_first_of(separator);
	while(end != string::npos)
	{
		stringlist.push_back(source.substr(start,end-start));
		start = end +1;
		end = source.find(separator,start);
	}
	//last 
	stringlist.push_back(source.substr(start,source.length()-start));
}


template <class T> 
int dump_all( T &in )
{
	typedef typename T::iterator IT;
	IT it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		cout<<*it<<endl;
	}
	return 1;
}

bool file_exist(string FileName) 
{
	//if ( _access(FileName.c_str(),0) == -1 ) //access in windows 
	if ( access(FileName.c_str(),0) == -1 )
	{
		return(false);
	}
	
	return(true);
}

void print_env_PATH()
{
	vector<string>  output;
	char *path=getenv("PATH");
	string path_env(path);
	split(output, path_env, ":");
	dump_all (output);
}

string where_is(string elf_name)
{
	string ret_str;
	vector<string>  vec_PATH;
	char *path=getenv("PATH");
	string path_env(path);
	split(vec_PATH, path_env, ":");


 	vector<string>::iterator it;
	for(it=vec_PATH.begin(); it!= vec_PATH.end(); it++)
	{
		string abs_path=(*it);//+"/"+elf_name;
		abs_path+="/";
		abs_path+=elf_name;
		if(file_exist(abs_path))
		{
			ret_str=abs_path;
		}
	}
	
	return ret_str;
}


//bug_20m:  while  return 4G 's string  
string bug_return_big_string()
{
}
string return_zero_string()
{
	return string ("");
}

void string_length()
{

	string ls_path=bug_return_big_string();

	cout<<"END"<<endl;
	cout<<"length="<<ls_path.length()<<endl;
	cout<<"length="<<ls_path.size()<<endl;

	string null_str="";
	cout<<"length="<<null_str.size()<<endl;
	cout<<"length="<<null_str.length()<<endl;
}

int main()
{
	string ls_path=where_is("ls");	
	cout<<ls_path<<endl;
}

