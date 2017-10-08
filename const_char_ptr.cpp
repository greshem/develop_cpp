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

//2012_11_15 by greshem. 

using namespace std;

typedef struct _ClientInfo
{
	int a;
	int b;
	int c;
	int e;
}ClientInfo;
void dump(ClientInfo const *input);
void dump2(ClientInfo const &input);

int main(int argc, char *argv[])
{
		
	ClientInfo info[]={
	{1,2,3,4},
	{2,2,3,4},
	{3,2,3,4},
	{4,2,3,4},
	{5,2,3,4},
	{6,2,3,4},
	{7,2,3,4},
	};

	dump(info+1);

	dump2(*(info+0));

	const ClientInfo *input= info+3;	
	//ClientInfo *input= info+3;	
	input->a++;
	int a= input->b;
	return 0;
}

void read_client_info_array( ClientInfo *input)
{

}

void dump(const ClientInfo *input)
{
	printf("a=%d,", input->a);
	printf("b=%d,", input->b);
	printf("c=%d,", input->c);
	printf("d=%d\n", input->e);
	//input->e=100;
	input++;
}

void dump2(ClientInfo const &input)
{
	printf("a=%d,", input.a);
	printf("b=%d,", input.b);
	printf("c=%d,", input.c);
	printf("d=%d\n", input.e);
	//input.e=100;
	//input++;
}
