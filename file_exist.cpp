//########################################################################
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <locale.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <assert.h>
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
using namespace std;


bool file_exist(string FileName) 
{
	//if ( _access(FileName.c_str(),0) == -1 ) //access in windows 
	if ( access(FileName.c_str(),0) == -1 )
	{
		return(false);
	}
	return(true);
}

int main()
{
	if(file_exist("/etc/passwd"))
	{
		printf("exists \n");
	}
}
