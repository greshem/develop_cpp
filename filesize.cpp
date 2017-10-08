#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdarg.h>

#include "die.cpp"

using namespace std;
long long  filesize (string file);

using namespace std;
int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		die("Usage: %s file", argv[0]);
	}

	cout<<filesize(argv[1])<<endl;
	return 0;
}



long long  filesize (string file)
{
	struct stat st;
	long long ret=stat(file.c_str(), &st);
	if(ret ==-1)
	{
		cout<<file<<" stat error"<<endl;
		return -1;
	}
#ifdef WINDOWSCODE
	 return st.st_size ;         
#else
	switch (st.st_mode & S_IFMT)
	{
		//block device
		case S_IFBLK: return st.st_size ;         
			break;
		//char device
		case S_IFCHR:  return st.st_size  ;    
			break;
		//dirrectory
		case S_IFDIR:  return st.st_size  ;            
			break;
		//FIFO/pipe
		case S_IFIFO:  return st.st_size  ;            
			break;
		//symlink
		case S_IFLNK:  return st.st_size  ;            
			break;
		// regular file 
		case S_IFREG:  return st.st_size  ;            
			break;
		//socket
		case S_IFSOCK: return st.st_size  ;            
			break;
		default:       return -1;
			break;
	}
#endif
}


