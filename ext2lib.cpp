//###################################################
//#include <dirent.h>
#include <Baselib.hpp> 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif

#include <ext2fs/ext2fs.h>
#include <fstream>
//#include <dirent.h>
#include <string> 
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include <QzjUnit.hpp>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  

int main()
{
	ext2_filsys fs;
	int ret;
	int use_superblock=0;
	int use_blocksize=0;
	int flags=EXT2_FLAG_JOURNAL_DEV_OK| EXT2_FLAG_SOFTSUPP_FEATURES;
	ret=ext2fs_open("/dev/sda1", flags, use_superblock, use_blocksize, unix_io_manager, &fs);
	if(ret)
	{
		die<char> ("file superblock error\n");
	}	
	cout<<fs->super->s_max_mnt_count<<endl;
}
