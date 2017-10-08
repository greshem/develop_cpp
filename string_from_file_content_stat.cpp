#include <algorithm>
#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <locale.h>
#include <map>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <vector> 

using namespace std;

/****************************************************************************
* Description	
* @param 	
* @return 	
* @notice:  ascii file 
* *************************************************************************/
char  * stringFromFile (char *fileName)
{	
    char *str;
	struct stat st;
	if(stat(fileName, &st)< 0)
    {
       return NULL;
    }
	int fd;
	fd=open(fileName, O_RDONLY);
	if(fd <0 )
	{	
		return NULL;
	}
	str=(char*)malloc(st.st_size+1);
	read(fd,str,st.st_size);
	//str[st.st_size+1]='\0';
	str[st.st_size]='\0';
	close(fd);
	return str;
	
}


using namespace std;
int main(int argc, char *argv[])
{
	
	string str=stringFromFile("/etc/passwd");
	cout<<str.c_str()<<endl;
	
	return 0;
}
