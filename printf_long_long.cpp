

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
int main(int argc, char *argv[])
{ 
	long long a=33333333;
	printf("%lld %lld %lld", a,a,a);
} 

