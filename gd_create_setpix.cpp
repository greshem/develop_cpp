#ifdef WINDOWSCODE
//#error "gd not  support widnows now "
#include <gd/gd.h>
#pragma comment(lib,"bgd_a.lib")//����ʱ����comctl32.lib����������չ�ؼ��Ľӿ�
#pragma comment(lib,"bgd.lib")
#pragma comment(lib,"webpng.lib")
#pragma comment(lib,"gdtest.lib")
#else
#include <gd.h>
#endif


#include <stdlib.h>
#include <Baselib.hpp>
#include <gtest/gtest.h>
#include <fstream>
//#include <dirent.h>
#include <string> 
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
//#2010_08_25_17:32:39 add by qzj
int main()
{
	unlink("test.jpg");
	int color=gdTrueColor(200, 200,200);
	gdImagePtr im=0;
	//������ gdImageCreate ���õĻ�����ɱ���ȫ�ڵ������
	//im=gdImageCreate (100, 100);
	im=gdImageCreateTrueColor (100, 100);

	int gray=gdImageColorAllocate(im , 200, 200, 200);
	gdImageFill(im , 50, 50, color);
	
	for(int i=0 ;i<100;i++)
	{
		for(int j=0; j<100;  j++)
		{
			gdImageSetPixel(im, i, j, rand());
		}
	}
	FILE *out=fopen("test.jpg", "wb");
	gdImageJpeg(im, out, -1);	
}
