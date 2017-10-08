#include <algorithm>
#include <dirent.h>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <vector> 

using namespace std;
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>

// check  ret hardisk have as least  [[size]]  byte free space . 
// ret 是传入的磁盘的fd 好， 
// size 要求的磁盘大小
extern void check_free_space(int* ret, unsigned long long size)
{


    unsigned long long dest_size;
    struct statvfs stvfs;
    struct stat st ;
    //int debug = 1;

    if (fstatvfs(*ret, &stvfs) == -1) 
	{
        printf("WARNING: Unknown free space on the destination: %s\n",
        strerror(errno));
        return;
    }
    /* if file is a FIFO there is no point in checking the size */
    if (!fstat(*ret, &st)) 
	{
        if (S_ISFIFO(st.st_mode))
            return;
    } else 
	{
        printf("WARNING: Couldn't get file info because of the following error: %s\n",
        strerror(errno));
    }

    dest_size = (unsigned long long)stvfs.f_frsize * stvfs.f_bfree;
    if (!dest_size)
	{
            dest_size = (unsigned long long)stvfs.f_bsize * stvfs.f_bfree;
	}

    if (dest_size < size)
	{
			//程序die. 
            //log_mesg(0, 1, 1, debug, "Destination doesn't have enough free space: %llu MB < %llu MB\n", print_size(dest_size, MBYTE), print_size(size, MBYTE));
            cout<<"error size is small"<<endl;
	}
//            log_mesg(0, 1, 1, debug, "Destination doesn't have enough free space: %llu MB < %llu MB\n", dest_size, size);
}
int main()
{
	int fd=open("/dev/sdb1", O_RDONLY);
	if(fd == -1)
	{
		printf("open sda1 faile , is devicd exist \n");	
		return -1;
	}
	int size=1024*1024*1024;
	check_free_space(&fd, size);
	
}
