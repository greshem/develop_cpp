#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <unistd.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{ 
if ( argc != 2)
{
printf("Usage: %s file \n", argv[0]);
exit(-1);
}
 vector<string> c;
 FILE  *f;
 char buffer[256];
 char deque[256];
f=fopen(argv[1],"r");
// printf("file is %d",f);
if (!f)
{
	printf("open the file error \n");
	exit(-3);
}

while( fgets(buffer,256,f))
{
 sprintf(deque,"%s",buffer);
c.push_back(deque);
}
//c.partial_sort();
random_shuffle(c.begin(),c.end());
for (vector<string>::iterator iter=c.begin();iter!=c.end();iter++)
cout <<*iter;


// while(strchr(buffer,'\n') ==NULL);
}
