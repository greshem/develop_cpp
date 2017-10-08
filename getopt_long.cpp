#include <algorithm>
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <vector> 
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//#include <gtest/gtest.h>
//2010_09_06 by greshem. 


using namespace std;
void usage()
{
 printf("Usage : %s [OPTION]...\n\n", "wenshuna");
 printf("  -d, --delay      delay between receive and send data in seconds. default:%i\n", 23333);
 printf("  -h, --help       print this screen\n");
 printf("  -p, --port       defines server port. default:%i\n", 45);
 printf("  -v, --version    output version information\n");
 exit(0);

}
static struct option long_options[]={
	{"delay", 1, 0, 'd'},
	{"help", 0, 0,'h'},
	{"port", 1, 0, 'p'},
	{"version", 0, 0, 'v'}
};
int main(int argc, char *argv[])
{
	
	if(argc ==1)
	{
		usage();
	}
	int c, option_index;
	while ((c=getopt_long(argc, argv, "d:p:v?h", long_options, &option_index)) != -1)
	{
		switch((char)c) 
		{
			case 'd':
				printf("option --delay with value '%s'\n", optarg);
				break;
			case 'p':
				printf("option --port with value %s\n", optarg);
				break;
			case 'v':
				printf("version is 1.11111\n");
				break;
			case '?':
			case 'h':
				printf("help info \n");
				printf("help info \n");
				printf("help info \n");
				exit(0);
				break;
		}
	}
	return 0;
}
