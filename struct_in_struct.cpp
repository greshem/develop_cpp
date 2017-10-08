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
#include <map>
//2010_07_07 by qzj. 

using namespace std;

struct info
{
	int a;
	int b;
	int c;
	int e;
	//string name;

	struct INFO2 {
	int aa;
	int bb;
	int cc;
	int dd;
	} info2;

};
int main(int argc, char *argv[])
{



	struct info test[4096]={0,0,0,0,{11,22,33,44} };


	printf ("%d\n", test[0].a);
	printf ("%d\n", test[0].info2.aa);
	printf ("%d\n", test[0].info2.bb);
	printf ("%d\n", test[0].info2.cc);
	printf ("%d\n", test[0].info2.dd);


	return 0;
}
