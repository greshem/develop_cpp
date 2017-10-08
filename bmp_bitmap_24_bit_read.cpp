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
	unsigned long		bhSize;
	unsigned short		bhReserved1;
	unsigned short		bhReserved2;
	unsigned long		bhOffBits;
} BITMAP_FILE_HEADER;

typedef struct tagBITMAP_INFO_HEADER
{
	unsigned long		biSize;
	long				biWidth;
	long				biHeight;
	unsigned short      biPlanes;
	unsigned short      biBitCount;
	unsigned long		biCompression;
	unsigned long		biSizeImage;
	long				biXPelsPerMeter;
	long				biYPelsPerMeter;
	unsigned long		biClrUsed;
	unsigned long		biClrImportant;
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
int DumpBitmap(const char *lpszFileName)
{
	BITMAP_FILE_HEADER bmpHead;
	BITMAP_INFO_HEADER bmpInfo;
	
	MFile<char> bmp;
	if(bmp.Open(lpszFileName) !=1 )
	{
		die<char>("open file error\n");
	}
	bmp.Read((char*)&bmpHead, sizeof(BITMAP_FILE_HEADER));	
	bmp.Read((char*)&bmpInfo, sizeof(BITMAP_INFO_HEADER));

	printf("sizeof(head) %d\n", sizeof(bmpHead));
	printf("sizeof(info) %d\n", sizeof(bmpInfo));
	printf("########################################################################\n");
	// unsigned short		bhType;
	// unsigned long		bhSize;
	// unsigned short		bhReserved1;
	// unsigned short		bhReserved2;
	// unsigned long		bhOffBits;

	printf("header type -> %d\n", bmpHead.bhType);
	printf("header size -> %d\n", bmpHead.bhSize);
	printf("hbReserved1-> %d\n",  bmpHead.bhReserved1);
	printf("hbReserved2-> %d\n",  bmpHead.bhReserved2);
	printf("bhOffBists-> %d\n",   bmpHead.bhOffBits);

assert(bmpHead.bhSize == filesize<char>(lpszFileName)) ;

	printf("########################################################################\n");
	//########################################################################
	// unsigned long		biSize;
	// long				biWidth;
	// long				biHeight;
	// unsigned short      biPlanes;
	// unsigned short      biBitCount;
	// unsigned long		biCompression;
	// unsigned long		biSizeImage;
	// long				biXPelsPerMeter;
	// long				biYPelsPerMeter;
	// unsigned long		biClrUsed;
	// unsigned long		biClrImportant;

	printf("biSize-> %d\n", bmpInfo.biSize);
	printf("width -> %d\n", bmpInfo.biWidth);
	printf("height-> %d\n", bmpInfo.biHeight);
	printf("biPlanes-> %d\n", bmpInfo.biPlanes);
	printf("biBitCount-> %d\n", bmpInfo.biBitCount);
	printf("biCompression-> %d\n", bmpInfo.biCompression);
	printf("sizeImage-> %d\n", bmpInfo.biSizeImage);
	printf("biXPelsPerMeter-> %d\n", bmpInfo.biXPelsPerMeter);
	printf("biYPelsPerMeter-> %d\n", bmpInfo.biYPelsPerMeter);
	printf("biClrUsed-> %d\n", bmpInfo.biClrUsed);
	printf("biClrImportant-> %d\n", bmpInfo.biClrImportant);
	int tmp=0;
	for(int i=0; i< bmpInfo.biWidth; i++)
	{
		for(int j=0; j<bmpInfo.biHeight; j++)
		{
			tmp=0;
			bmp.Read((char *)&tmp, 3);
	//		if( tmp != (256*256*256-1))
			{
	//			cout<<tmp<<endl;;
			}
		}
	}
	return 1;
}
#if 0
	//bmpHead.bfOffBits = 1078;
	bmpHead.bfSize = bmpHead.bfOffBits + cx*cy*4;
	BITMAP_INFO bmpInfo;
	memset(&bmpInfo, 0, sizeof(BITMAP_INFO));
	bmpInfo.bmiHeader.biSize = sizeof(BITMAP_INFO_HEADER);
	bmpInfo.bmiHeader.biWidth = cx;
	bmpInfo.bmiHeader.biHeight = cy;
	bmpInfo.bmiHeader.biPlanes = 1;
	bmpInfo.bmiHeader.biBitCount = 24;
//	bmpInfo.bmiHeader.biBitCount = 32;
	bmpInfo.bmiHeader.biCompression = 0;
	bmpInfo.bmiHeader.biSizeImage = cx*cy;
	bmpInfo.bmiHeader.biXPelsPerMeter = 0;
	bmpInfo.bmiHeader.biYPelsPerMeter = 0;
	bmpInfo.bmiHeader.biClrUsed = 0;
	bmpInfo.bmiHeader.biClrImportant = 0;
	RGBQUAD aryRGB[256];
	memset(aryRGB, 0, sizeof(RGBQUAD)*256);
	int i;
	for(i = 0; i < 256; i++)
	{
		aryRGB[i].rgbRed = m_aryRGB[i][0];
		aryRGB[i].rgbGreen = m_aryRGB[i][1];
		aryRGB[i].rgbBlue = m_aryRGB[i][2];
	}
	if(!fwrite(&bmpHead, sizeof(BITMAP_FILE_HEADER), 1, fp))
	{
		fclose(fp);
		return false;
	}
	if(!fwrite(&bmpInfo.bmiHeader, sizeof(BITMAP_INFO_HEADER), 1, fp))
	{
		fclose(fp);
		return false;
	}
	if(!fwrite(aryRGB, sizeof(RGBQUAD)*256, 1, fp))
	{
		fclose(fp);
		return false;
	}
	for(i = 0; i < cy; i++)
	{
		if(!fwrite(m_pBitmap+cx*(cy-i-1), cx * 4, 1, fp))
		{
			fclose(fp);
			return false;
		}
	}
	fclose(fp);
	return true;
}
#endif
int main(int argc, char*argv[] )
{
   //   SaveBitmap("test.bmp");
   	//cout<<"test"<<endl;
   	if(argc  !=2 )
	{	
		printf("Usage: %s file.bmp\n", argv[0]);
		exit(0);
	}

	DumpBitmap(argv[1]);

 return 0;
}
