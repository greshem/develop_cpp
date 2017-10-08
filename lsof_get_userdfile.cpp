
#include <glob.h>
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
     #include <unistd.h>

using namespace std;

using namespace std;
int  glob_2_vector_string(string in,  vector<string> &out); 

vector<string> get_pid_fd_links(int pid);
int LsofGetFile(int pid, vector<string> & lsof_list);

int main(int argc, char *argv[])
{
	vector<string> list;
	LsofGetFile(30300 , list);
	cout<<"Count "<<list.size();
	copy(list.begin(),list.end(),ostream_iterator<string>(cout,"\n"));
	return 0;
}

int  glob_2_vector_string(string in,  vector<string> &out)
{
	
	glob_t gl;
    int ret;
	ret=glob(in.c_str(), 0, NULL, &gl);
	int count=gl.gl_pathc;
	for(int i=0;i<count;i++)
	{
		//printf("##%s\n", gl.gl_pathv[i] );
		out.push_back( gl.gl_pathv[i] );
	} 
	globfree(&gl);
	return  count;
}


vector<string> get_pid_fd_links(int pid)
{
	char buffer[1024];
	vector<string> filelist;
	snprintf(buffer, sizeof(buffer), "/proc/%d/fd/*", pid);
	printf("pattern:%s\n", buffer);

	glob_2_vector_string(buffer, filelist);	
	return filelist;
}

int LsofGetFile(int pid, vector<string> & lsof_list)
{
	char file_path[1024]={0};
	vector<string> fds=get_pid_fd_links(pid);
	for(vector<string>::iterator it=fds.begin(); it != fds.end(); it++)
	{
		memset(file_path, '\0', sizeof(file_path));
		readlink((*it).c_str(), file_path, sizeof(file_path));	
		printf("###%s\n", file_path);
		lsof_list.push_back(file_path);
	}
	return 1;	
}
