#include <stdlib.h>
//#include <MLmyUnit.hpp>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
//2010_07_09 by qzj. 
int main(int argc, char *argv[])
{
	printf("%s\n", "long_double.c");
	long double a=11111111.1;
	long double b=a*a;
	printf("%lf\n", b);
	return 0;
}
