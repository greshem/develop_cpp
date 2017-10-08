#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/aio.h>
#include <iostream>
using namespace std;
const int  BUFFSIZE = 1024*1024*10;
int main(int argc,char *argv[])
{
    int fdin,fdout;
    void *src,*dst;
    size_t pagesize;
    struct stat statbuf;
    if(argc != 3)
    {
        printf("usage : %s <fromfile> <tofile>\n",argv[0]);
        return 1;
    }
    if((fdin = open(argv[1],O_RDONLY)) == -1)
    {
        printf("can't open file %s\n",argv[1]);
        return 1;
    }
    if((fdout = open(argv[2],O_RDWR,0644)) == -1)
    {
        printf("can't create file %s\n",argv[2]);
        return 1;
    }
    assert(fstat(fdin,&statbuf) == 0);
    printf("filein size = %ld\n",statbuf.st_size);
    size_t len = 0;
    //#char buff[1024*1024]={0};
    while( 1)
    {
        char *pbuff =(char*) malloc(BUFFSIZE + 1);
 
		len = read(fdin,pbuff,BUFFSIZE);
        if (len <=0) break;
        if (len >BUFFSIZE) break;
	 	aiocb myaiocb;
		//cout << "read size:"<<len <<endl;
		memset(&myaiocb,0x00,sizeof(aiocb));
		myaiocb.aio_buf  = pbuff;
		myaiocb.aio_nbytes = len;
		myaiocb.aio_fildes = fdout;

		aio_write(&myaiocb);
    }

    close(fdin);
    close(fdout);
    return 0;
}

