#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
#include <vector> 
#include <iostream> 
using namespace std;


string  stringFromFile(string fileName)
{	
    char *str;
	struct stat st;
	if(stat(fileName.c_str(),&st)< 0)
    {
       return "";
    }
	int fd;
	fd=open(fileName.c_str(), O_RDONLY);
	if(fd <0 )
	{	
		return "";
	}
	str=(char*)malloc(st.st_size+1);
	read(fd,str,st.st_size);
	str[st.st_size+1]='\0';

	string retStr(str);
	free(str);
	return retStr;
	
}
int main(int argc, char *argv[])
{	
	if(argc<2)
	{
		printf("Usage %s file\n", argv[0]);
		exit(0);
	}
	string str;
	char *tmp=NULL;
	int  file_len=0;
//	unsigned long long max_number;
//	long long min_number;
//	long long count;
	int i=0;
	str=stringFromFile(argv[1]);
	if(str.size()<=0)
	{
		printf("file read error \n");
		exit(-2);
	}
	cout<<str;
		
}
