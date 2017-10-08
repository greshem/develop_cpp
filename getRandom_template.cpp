
#include <fstream>
#include <string> 
#include <sstream>
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;


template < typename T>  int  getRandoms(T list[], int count) 
{
	for (int i=0; i<count; i++)
	{
		list[i]=   T(random());
	}
	return 0;
}



int main(int argc, char *argv[])
{ 
	printf("this is main \n");
	float list[100];
	getRandoms<float>(list, 100);
} 
	
