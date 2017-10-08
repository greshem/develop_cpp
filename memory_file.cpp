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
#include <stringprep.h>
static char * get_file( int &log_len)
{
		
    char *str=NULL;
    struct stat st; 
    if(stat("/etc/passwd", &st)< 0)
    {   
       return NULL; 
    }   
    int fd; 
    fd=open("/etc/passwd", O_RDONLY);
    if(fd <0 )
    {   
        return NULL; 
    }   
    str=(char*)malloc(st.st_size);
    read(fd,str,st.st_size);
    close(fd);
	log_len=st.st_size;
    return str;
}

int main()
{
	int len; 
	char *ptr=get_file(len); 	
	printf("%s", ptr);
}
