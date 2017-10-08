#include <stdlib.h>
//#include <Baselib.hpp> 
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <string>
#include <iostream>
#define  WORD_CAPACITY 32 
using namespace std;
int  die(char *input_str);
int main(int argc, char *argv[])
{
	FILE *fp;
	if(argc != 2)
	{
		die("Usage: %s file line");
	}
	char buf[1024];
	int i=0;
	fp = fopen("wc.cpp", "r");
	if(fp == NULL)
	{
		printf("open file error\n");
		exit(-1);
	}
	while(fgets(buf, sizeof(buf), fp))
	{
		i++;
		if(argv[1])
		{
			if(i == atoi(argv[1]))
			{
			printf("%s\n", buf);
			}
		 
		}
	}
	printf(" line %d\n", i);
	//cin >> i;
}
int  die(char *input_str)
{
	printf("%s", input_str);
	exit(-1);
}
