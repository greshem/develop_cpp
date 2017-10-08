#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stringprep.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
//########################################################################
//#2010_12_21_15:24:29 add by greshem
//#include <Baselib.hpp>


using namespace std;


//linux 下 有  ftrncate 函数. 这里用 fcntl 代替.  LINUX 系统调用里没有 F_FREESP 函数. 
int unx_ftruncate (int fd, unsigned int  size)
{
    struct flock flockd;
    flockd.l_type = 0;
    flockd.l_whence = SEEK_SET;
    flockd.l_start = size;
    flockd.l_len = 0;
	return 1;
  //  return (fcntl (fd, F_FREESP, &flockd));
}

int main(int argc, char *argv[])
{
	
	return 0;
}
