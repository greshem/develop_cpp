#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <locale.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <assert.h>
//.bss是不占用.exe文件空间的，其内容由操作系统初始化（清零）
//而.data却需要占用，其内容由程序初始化

//int ar[300000] = {1, 2, 3, 4, 5, 6 }; //.data  1M大小.
//int ar[300000] = {0 }; 				//.data  8k大小
//int ar[300000] = {0,0,0,0,0 }; 		//.data  8k大小
//int ar[300000] = {0,0,0,0,0 ,1}; 		//.data  1m大小
//int ar[300000] = {1 }; 				//.data  1M大小
//int ar[300000] ;					  	//.bss   8k大小
int main()
{
	//int ar[300000] = {0,0,0,0,0 ,1}; 		//.data  8k大小
	//static int ar[300000] = {0,0,0,0,0 ,0}; 		//.data  8k大小
	static int ar[300000] = {0,0,0,0,0 ,1}; 		//.data  1m大小
	ar[0]=100;	
	return 1;
}
//########################################################################
//两种定义方式的区别
//1. 二进制程序开始地方的offset, 文件已经不一样了
//2. 文件系统 

//.data 
// There are 35 section headers, starting at offset 0x125a08:  
//.bss
// There are 35 section headers, starting at offset 0xa54:
// .data方式. 
// [24] .data             PROGBITS        080496e0 0006e0 124fa0 00  WA  0   0 32
// [25] .bss              NOBITS          0816e680 125680 000008 00  WA  0   0  4
//
// .bss 方式.
// [24] .data             PROGBITS        080496c8 0006c8 000004 00  WA  0   0  4
// [25] .bss              NOBITS          080496e0 0006cc 124fa0 00  WA  0   0 32
