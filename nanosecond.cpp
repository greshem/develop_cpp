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
//�ڴ�Ķ�ȡһ���� ���뼶���. 
//����Ĵ���һ�㶼���ڴ�Ĵ����Ĳ��� ��intel ��. ����ƽ��һ�β����� 2.6 ����.  

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
