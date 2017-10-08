#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
//#include <dirent.h>
//#include <fcntl.h>
//#include <locale.h>
//#include <stringprep.h>
//#include <sys/ioctl.h>
//#include <sys/types.h>

 #define DEFAULT_FONTPATH "/usr/X11R6/lib/X11/fonts/TrueType:/usr/X11R6/lib/X    11/fonts/truetype:/usr/X11R6/lib/X11/fonts/TTF:/usr/share/fonts/TrueType:/us    r/share/fonts/truetype:/usr/openwin/lib/X11/fonts/TrueType:/usr/X11R6/lib/X1    1/fonts/Type1:/usr/lib/X11/fonts/Type1:/usr/openwin/lib/X11/fonts/Type1"

int main()
{
	printf("%s", DEFAULT_FONTPATH);
}
