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
//#include <stringprep.h>
//========================================================================
int  _write_to_bin_file(char *filename,  char *data, int data_len)
{
    int out=open(filename, O_CREAT|O_RDWR, S_IRWXU);
    if(out< 0)
    {
        printf("open 501_bin error\n");
        return 0;
    }
    write(out, data, data_len);
    close(out);
    return 1;
}

int main()
{
	int test=1024;
	_write_to_bin_file("/tmp/a.out", (char*)&test, sizeof(int));
}
