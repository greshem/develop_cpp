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
//#��R��G��BΪ�Ὠ���ռ�ֱ������ϵ����RGBͼ��ÿ�����ص���ɫ�����ø���ά�ռ��һ��������ʾ��
//��Grayͼ��ÿ�����ص���ɫ������ֱ��R=G=B�ϵ�һ��������ʾ������rgbתgrayͼ�ı��ʾ���Ѱ��
//һ����ά�ռ䵽һά�ռ��ӳ�䣬�������뵽�ľ�����Ӱ������rgb�ռ��һ������ֱ��R=G=B�����ߣ���
//��ʵ��MatlabҲ���������ģ�������Gray = 0.29900 * R + 0.58700 * G + 0.11400 * B.

//������JAVA ��һ�ַ�ʽ�� 
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
