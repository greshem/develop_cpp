//########################################################################
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
//#include <dirent.h>
#include <unistd.h>
#include <locale.h>
#include <sys/stat.h>
//#include <sys/ioctl.h>
#include <errno.h>
//#include <fcntl.h>
#include <time.h>
#include <assert.h>
//#include <stringprep.h>
 #define max(a, b) ((a>b)?(a):(b))
 #define min(a, b) ((a<b)?(a):(b))

int main ()
{
	int r,g,b;
	int  max_rgb=max(r , max(g, b));
	int  min_rgb =min(r, min(g, b));
	int range=(max_rgb-min_rgb);
	return 0;	
	
}
