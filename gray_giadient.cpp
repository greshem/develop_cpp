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

//#2010_09_21_16:24:46 add by greshem
//制作背景， 算法上比较清楚的 灰色渐变的， 算法。 
// 默认都是从 白的变成黑的容易理解。 

int levels=20;
float get_gray_level(int i)
{
	
	//就是 rgb(gray_star, gray_start, gray_start)
	int gray_start=255;
	int gray_end=100;
	//int levels=20;

	if(i >= levels)
	{
		i=levels;
	}

	float delta= (gray_start - gray_end)/levels;
	
	return gray_start -delta*i;
}

int main()
{


	
	int pixel_len=20;
	if(pixel_len < levels)
	{
		printf("pixel_len < levels\n");
		exit(-1);
	}
	float pixel_delta=pixel_len/levels;
	
	for(int i=0; i<=pixel_len; i++)
	{
		int gray=get_gray_level( int(i/pixel_delta));
		printf(" %d -> gray %d\n", i,  gray);
	}
}
