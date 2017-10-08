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
int rgb2hsv(int r, int g, int b, int *h, int *s, int *v)
{
	int  max_rgb=max(r , max(g, b));
	int  min_rgb =min(r, min(g, b));
	int range=(max_rgb-min_rgb);
	if(r==max_rgb) *h=(g-b)/range;
	if(g==max_rgb) *h= 2+(b-r)/range;
	if(b==max_rgb) *h= 4+(r-g)/range;
	
	*h=*h*60;
	if(*h<0)
	{
		h=h+360;
	}
	*v=max_rgb;	
	*s=range/max_rgb;
	return 1;	
}
int main()
{
	printf("%d", max(1, max(2, 3)));
	printf("%d", min(1, min(2, 3)));
	int h,s,v;
		h=s=v=0;
	rgb2hsv(255, 0, 0,  &h, &s, &v);
	printf("%d %d %d\n", h, s , v);
}
