#include <stdlib.h>
#include <iostream>
#include <string> 
#include <fstream>
#include <iterator>  
#include <vector> 
#include <iostream> 

#ifndef WINDOWSCODE
#include <unistd.h>
#endif

//2012_02_23 by greshem. 
//BUG_30m:  一开始 把 begin 默认 老是为0 导致 最后 分割之后的参数不是太容易传入
// 最后再添加一个参数之后 就变的简单多了. 
void mesh(char *input, int begin, int end);

using namespace std;
int main(int argc, char *argv[])
{
	char ascii[]={'a', 'b', 'c', 'd','e','f', 'g', 'h', 'i','j'};
	mesh(ascii, 0, sizeof(ascii));

	return 0;
}
void swap(char *input, int offset1, int offset2);
void print_array(char *input, int len)
{
	for(int i=0; i<len; i++)
	{
		printf("%c", input[i]);
	}
	printf("\n");
}

void mesh(char *input, int begin, int end)
{
	if(end < begin)
	{
		printf("错误  长度为小于0\n");
	}

	if(begin== (end-1))
	{
		print_array(input, end);
		return;
	}
	else
	{
		for(int k=begin; k<end; k++)
		{
		 	swap(input, begin, k);
			mesh(input, begin+1, end);
			swap(input, k,begin );
		}			
	}
}

void swap(char *input, int offset1, int offset2)
{
	char tmp=input[offset2];
	input[offset2]=	input[offset1];
	input[offset1]=tmp;
}

//打印数组 input 中 0 和 i 交换之后的数组.
void swap_0_n_and_print(char *input, int len,  int offset)
{
	for(int i=0; i<len;i++)
	{
		if(i==0) printf("%c", input[offset]);
		else if(i==offset) printf("%c", input[0]);
		else {printf("%c", input[i]);}
	}
}
void swap_and_print(char *input, int len)
{
	for(int i=0;i<len; i++)
	{
		swap_0_n_and_print(input, len , i);
	}	
}
