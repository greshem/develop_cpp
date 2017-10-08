
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

//========================================================================
//|--------------|-----length-------|---------------------------|end_sector
//0            start_sector       start+length


long long  filesize (string file);
int main(int argc, char *argv[])
{ 
	if(argc != 4)
	{
		printf("Usage: %s input_file   start_sector   length  \n", argv[0]  );
		exit(-1);
	}
	char *input_file=argv[1];
	unsigned long long size= filesize(input_file);
	unsigned long long end_sector= (long long) (size/512);
	int 	start_sector=atoi(argv[2]);
	int 	length= atoi(argv[3]);


	printf("dd if=%s  of=output_file_stage1  bs=512 count=%d   skip=%d  \n", input_file  ,start_sector      , 0);
	printf("dd if=%s  of=output_file_stage2  bs=512 count=%d   skip=%d \n" , input_file  ,length 			, start_sector	  );
	printf("dd if=%s  of=output_file_stage3  bs=512 count=%lld skip=%lld \n" , input_file  ,(unsigned long long)(end_sector - start_sector - length), (unsigned long long)start_sector+ length  );
} 

//printf("%lld %lld %lld", a,a,a);

//  blockdev --help |grep get 实现相同的功能. 
long long filesize(string file);
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

