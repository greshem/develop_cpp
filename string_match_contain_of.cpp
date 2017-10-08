#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
//#include <stringprep.h>


//P:\_xfile_2013_04\_misc\spice_src_build\chm\libcacard-0.1.2.chm

//
//  match if s1 is completely contained in s2
static int string_match(const char *s1, const char *s2)
{
    int len = strlen(s1);
    const char *start;

    for (start = strchr(s2, *s1); start; start = strchr(start+1, *s1)) 
	{
       	if (strncmp(start, s1, len) == 0) 
		{
			return 1;
       	}
    }
    return 0;
}

