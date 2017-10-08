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
//#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <assert.h>
//#include <stringprep.h>

//#2010_09_21_16:24:46 add by greshem
//制作背景， 算法上比较清楚的 灰色渐变的， 算法。 
// 默认都是从 白的变成黑的容易理解。 
// 封装成了类， 更容易使用了。 
class pixel_gray
{
public:
	int levels;
	int gray_start;
	int gray_end;
	int reverse; //默认按照从白到黑的顺序输出， 从黑到白的输出也是需要的。 


public:
	pixel_gray()
	{
	levels=10;
	gray_start=245;
	gray_end=100;
	reverse=0;
	}
private:
	float get_gray_level(int i)
	{
		
		//就是 rgb(gray_star, gray_start, gray_start)
		//int levels=20;
		float ret;
		if(i >= levels)
		{
			i=levels;
		}

		float delta= (gray_start - gray_end)/levels;
		if(reverse)
		{
			ret=gray_end+delta*i;	
		}	
		else
		{
		ret=gray_start -delta*i;
		}
		return ret;
	}
public:
	int dump_line_gray(int pixel_len)
	{


		
		//int pixel_len=20;
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
	
	int dump_pixel_in_range(int start_x, int end_x, int pixel)
	{
		if(pixel > end_x)
		{
			pixel=end_x;
		}
		if(pixel < start_x)
		{
			pixel=start_x;
		}

		
		float delta=abs((end_x -start_x)/levels);
		int gray=get_gray_level( abs(pixel-start_x)/delta);
		return gray;
	}
};
int main()
{
	
	pixel_gray gray;
	//gray.dump_line_gray(100);
	printf("%d\n", gray.dump_pixel_in_range(0, 20, 0));
	printf("%d\n", gray.dump_pixel_in_range(0, 100, 0));
	printf("%d\n", gray.dump_pixel_in_range(0, 30, 0));

	printf("%d\n", gray.dump_pixel_in_range(0, 100, 100));
}
