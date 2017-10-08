#define _LARGEFILE64_SOURCE

#ifndef _REENTRANT
#define _REENTRANT
#endif
#include <pthread.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <signal.h>
#include <sys/fcntl.h>
#include <sys/ioctl.h>
#include <linux/fs.h>

#define BLOCKSIZE 512

int main()
{
	int retval=0;
	unsigned long long numbytes;
	unsigned long long ull;
	unsigned long ul;
	int fd = open("/dev/sda", O_RDONLY | O_LARGEFILE);

	
#ifdef BLKGETSIZE64
	
	retval = ioctl(fd, BLKGETSIZE64, &ull);
	numbytes = (unsigned long long)ull;
#else
	retval = ioctl(fd, BLKGETSIZE, &ul);
	numbytes = (unsigned long long)ul;
#endif


	unsigned long long numblocks = ((unsigned long long)numbytes)/(unsigned long long)BLOCKSIZE;
	printf("Benchmarking %s [%llu blocks, %llu bytes, %llu GB, %llu MB, %llu GiB, %llu MiB]\n",
			"/dev/sda" , numblocks, numbytes, numbytes/(1024uLL*1024uLL*1024uLL), numbytes / (1024uLL*1024uLL), numbytes/(1000uLL*1000uLL*1000uLL), numbytes / (1000uLL*1000uLL));
		//printf("[%d logical sector size, %d physical sector size]\n", physical_sector_size, physical_sector_size);


}


