#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char  * stringFromFile(char *fileName)
{	
    char *str;
	struct stat st;
	if(stat(fileName, &st)< 0)
    {
       return "";
    }
	int fd;
	fd=open(fileName, O_RDONLY);
	if(fd <0 )
	{	
		return "";
	}
	str=(char*)malloc(st.st_size+1);
	read(fd,str,st.st_size);
	str[st.st_size+1]='\0';
	close(fd);
	return str;
	
}
int main(int argc, char *argv[])
{	
	if(argc!= 3)
	{
		printf("Usage %s filesrv  filepattern\n", argv[0]);
		exit(0);
	}
	char *src;
	src=stringFromFile(argv[1]);

	char * pattern=stringFromFile(argv[2]);

	if( strstr(src, pattern) )
	{
		printf("pattern\n");
	}
		
}
