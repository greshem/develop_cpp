#include <stdlib.h>
//#include <QzjUnit.hpp>

#include <stdio.h>
#include <string.h>
#include <vector>
#include <unistd.h>
#include <iostream>
#include <string>
#include <algorithm>

#include <sys/time.h>

using namespace std;
int main(int argc, char *argv[])
{ 
	FILE  *f;
	if ( argc == 1)
	{
	//	die("Usage: %s file \n", argv[0]);
		f=stdin;
	}
	else if( argc==2 )
	{
		f=fopen(argv[1],"r");
		if (!f)
		{
			printf("open the file error \n");
			exit(-1);
		}

	}
	else
	{
		printf("Usage: %s [file] \n");
		exit(-1);
	}
	timeval tm;
	gettimeofday(&tm, NULL);
	srandom(tm.tv_sec + tm.tv_usec);
	vector<string> c;
	char buffer[256];
	char deque[256];

	while( fgets(buffer, sizeof(buffer), f))
	{
		sprintf(deque,"%s",buffer);
		c.push_back(deque);
	}
	
	random_shuffle(c.begin(),c.end());

	for (vector<string>::iterator iter=c.begin();iter!=c.end();iter++)
	{
		cout <<*iter;
	}


}
