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
//2011_06_17 by greshem. 
//内存的读取一般是 纳秒级别的. 
//下面的代码一般都是内存寄存器的操作 在intel 上. 所以平均一次操作是 2.6 纳秒.  

#define NANO_SEC_PER_SECOND 1000000000
int main(int argc, char *argv[])
{
	int i=0;
	int x;
	int y;
	int z;
	//		i++;
	int j=0;
	for(j=0;j< NANO_SEC_PER_SECOND ; j++)
	{
		i++;
		//x++;
		//y++;
		//z++;
	}		
}
