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
//.bss�ǲ�ռ��.exe�ļ��ռ�ģ��������ɲ���ϵͳ��ʼ�������㣩
//��.dataȴ��Ҫռ�ã��������ɳ����ʼ��

//int ar[300000] = {1, 2, 3, 4, 5, 6 }; //.data  1M��С.
//int ar[300000] = {0 }; 				//.data  8k��С
//int ar[300000] = {0,0,0,0,0 }; 		//.data  8k��С
//int ar[300000] = {0,0,0,0,0 ,1}; 		//.data  1m��С
//int ar[300000] = {1 }; 				//.data  1M��С
//int ar[300000] ;					  	//.bss   8k��С
int main()
{
	//int ar[300000] = {0,0,0,0,0 ,1}; 		//.data  8k��С
	//static int ar[300000] = {0,0,0,0,0 ,0}; 		//.data  8k��С
	static int ar[300000] = {0,0,0,0,0 ,1}; 		//.data  1m��С
	ar[0]=100;	
	return 1;
}
//########################################################################
//���ֶ��巽ʽ������
//1. �����Ƴ���ʼ�ط���offset, �ļ��Ѿ���һ����
//2. �ļ�ϵͳ 

//.data 
// There are 35 section headers, starting at offset 0x125a08:  
//.bss
// There are 35 section headers, starting at offset 0xa54:
// .data��ʽ. 
// [24] .data             PROGBITS        080496e0 0006e0 124fa0 00  WA  0   0 32
// [25] .bss              NOBITS          0816e680 125680 000008 00  WA  0   0  4
//
// .bss ��ʽ.
// [24] .data             PROGBITS        080496c8 0006c8 000004 00  WA  0   0  4
// [25] .bss              NOBITS          080496e0 0006cc 124fa0 00  WA  0   0 32
