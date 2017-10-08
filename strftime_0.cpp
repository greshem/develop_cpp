#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <time.h>
#include <map>

//2010_07_16 by qzj. 
using namespace std;
int main(int argc, char *argv[])
{
	char buffer[1024];
	time_t t;
	t=time(NULL);
	strftime(buffer, sizeof(buffer), "%Y_%m_%d_%T", localtime(&t));
	printf("%s", buffer);
	return 0;
}
