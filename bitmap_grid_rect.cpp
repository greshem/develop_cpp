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
#define WIDTH 640
#define LENGTH 480

//#2010_09_09_15:02:39 add by greshem
// 假如是 24 位的自己就是头部 54 + x*y*3 个字节。 

const unsigned short m_aryRGB[256][3] =  {{0,0,0} };
#pragma pack(1)


typedef struct tagBITMAP_FILE_HEADER 
{
	unsigned short		bhType;
	unsigned int 		bhSize;
	unsigned short		bhReserved1;
	unsigned short		bhReserved2;
	unsigned int		bhOffBits;
} BITMAP_FILE_HEADER;

typedef struct tagBITMAP_INFO_HEADER
{
	unsigned int	biSize;
	int 			biWidth;
	int 				biHeight;
	unsigned short      biPlanes;
	unsigned short      biBitCount;
	unsigned int biCompression;
	unsigned int biSizeImage;
	int 			biXPelsPerMeter;
	int 				biYPelsPerMeter;
	unsigned int biClrUsed;
	unsigned int biClrImportant;
} BITMAP_INFO_HEADER;

#ifdef WINDOWSCODE
#else
typedef struct tagRGBQUAD 
{
	unsigned char    rgbBlue;
	unsigned char    rgbGreen;
	unsigned char    rgbRed;
	unsigned char    rgbReserved;
} RGBQUAD;
#endif

typedef struct tagBITMAP_INFO 
{
    BITMAP_INFO_HEADER    bmiHeader;
    RGBQUAD             bmiColors[1];
} BITMAP_INFO;

#pragma pack()
//########################################################################
//
template <typename T> T *rang_data(int x, int y , int count)
{
 	T *data;
	data=(int *)malloc(x*y*sizeof(T));
	//memset(m_pBitmap, '1', 400*400);
	
	for(int i=0; i<=WIDTH*LENGTH; i++)
	{
		data[i]=rand();
    }
	return data;	
}

//########################################################################
//

int initBmpHeader(BITMAP_FILE_HEADER &header, int x ,int  y) 
{
	header.bhType=19778;
	header.bhSize=x*y*3 + 14 +40;	
	header.bhReserved1=0;
	header.bhReserved2=0;
	header.bhOffBits=54;
	return 1;
}
int initBmpInfo( BITMAP_INFO_HEADER &info, int x,int  y)

{
	info.biSize = 40; 
	info.biWidth=x;
	info.biHeight=y;
	info.biPlanes=1;
	info.biBitCount=24;
	info.biCompression=0;
	info.biSizeImage=x*y*3;
	info.biXPelsPerMeter=0;
	info.biYPelsPerMeter=0;
	info.biClrUsed=0;
	info.biClrImportant=0;
	return 1;
}

main()
{
   	//   SaveBitmap("test.bmp");
	int width=100, height=100;
	BITMAP_FILE_HEADER header;
	initBmpHeader(header, width , height);
	BITMAP_INFO_HEADER info;
	initBmpInfo(info, width, height);
	
	MFile<char> output;
	output.Create("output.bmp");
	int ret=output.Write((char *) &header, sizeof(header));
	assert(ret==14);
	
	ret=output.Write((char*) &info, sizeof(info));	
	assert(ret==40);	

	int color;
	for(int i=0; i<width; i++)
	{
		for(int j=0; j<height;  j++)
		{
			//color=rand();
			if((j%100==0) || (i%100==0))
			{
				color=0;
			}
			else
			{
				color=0xffffff;
			}
			color<<8;
			output.Write( (char *)&color, 3);
		}
	}	
	output.Close();
    return 0;
}
