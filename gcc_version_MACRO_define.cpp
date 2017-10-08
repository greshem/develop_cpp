

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
#define GCC_VERSION (__GNUC__ * 10000 \
+ __GNUC_MINOR__ * 100 \
+ __GNUC_PATCHLEVEL__)

int main()
{

#if GCC_VERSION >= 3400
	printf("GCC version,BBBB  %d\n", GCC_VERSION );
#elif GCC_VERSION < 3400
	printf("GCC version %d\n", GCC_VERSION );
#endif
  

}
