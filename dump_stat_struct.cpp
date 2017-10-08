#include  <Baselib.hpp>
//#include "stat.txt"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif


int stat_dump(struct stat in )	
{
	cout<< "dev_t	st_dev		"<< in.st_dev<<endl;
	cout<< "ino_t	st_ino		"<< in.st_ino<<endl;
	cout<< "mode_t	st_mode		"<< in.st_mode<<endl;
	cout<< "nlink_t	st_nlink		"<< in.st_nlink<<endl;
	cout<< "uid_t	st_uid		"<< in.st_uid<<endl;
	cout<< "gid_t	st_gid		"<< in.st_gid<<endl;
	cout<< "dev_t	st_rdev		"<< in.st_rdev<<endl;
	cout<< "off_t	st_size		"<< in.st_size<<endl;
	cout<< "blksize_t	st_blksize		"<< in.st_blksize<<endl;
	cout<< "blkcnt_t	st_blocks		"<< in.st_blocks<<endl;
	cout<< "time_t	st_atime		"<< in.st_atime<<endl;
	cout<< "time_t	st_mtime		"<< in.st_mtime<<endl;
	cout<< "time_t	st_ctime		"<< in.st_ctime<<endl;
	return 1;
}
#include <gtest/gtest.h>
#include <fstream>
//#include <dirent.h>
#include <string> 
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <Baselib.hpp>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
using namespace std;
int main(int argc, char *argv[])
{
	
	struct stat in;
	
	if(argc != 2)
	{
		die<char>("Usage: %s /dev/ntfs_device", argv[1]);
	}
	
//	char *data= file_seek64_and_read<char>(file, 0, 512, &readLen);
	stat(argv[1], &in);
	//printf("%d ", ext2->s_inodes_count);

	stat_dump(in);
	
	return 0;
}
