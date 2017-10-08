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
//BUG_30m:  һ��ʼ �� begin Ĭ�� ����Ϊ0 ���� ��� �ָ�֮��Ĳ�������̫���״���
// ��������һ������֮�� �ͱ�ļ򵥶���. 
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
		printf("����  ����ΪС��0\n");
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

//��ӡ���� input �� 0 �� i ����֮�������.
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
