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
//#以R、G、B为轴建立空间直角坐标系，则RGB图的每个象素的颜色可以用该三维空间的一个点来表示，
//而Gray图的每个象素的颜色可以用直线R=G=B上的一个点来表示。于是rgb转gray图的本质就是寻找
//一个三维空间到一维空间的映射，最容易想到的就是射影（即过rgb空间的一个点向直线R=G=B做垂线），
//事实上Matlab也是这样做的，并且有Gray = 0.29900 * R + 0.58700 * G + 0.11400 * B.

//这里是JAVA 的一种方式。 
 int filterRGB (int x, int y, int rgb) 
{
    int red   = (rgb & 0xff0000) >>16;   
	int green = (rgb &   0xff00) >>  8;
    int blue  =  rgb &     0xff;        
	int gray  = (red + green + blue) / 3;
	return (0xff000000 | (gray << 16) | (gray <<  8) |  gray); } 
// End of class Color2GrayFilter definition
int main()
{
	return 0;
}
