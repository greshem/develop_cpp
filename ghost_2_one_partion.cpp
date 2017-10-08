#include <stdlib.h>
//#include <MLmyUnit.hpp>
//.#include <QzjUnit.hpp>
#include <Baselib.hpp> 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
//#include <dirent.h>
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
//2010_07_09 by qzj. 
using namespace std;

typedef struct partion 
{
    unsigned char boot;
    char chs_begin[3];
    char partion_type;
    char chs_end[3];
    int  lba_start;
    int  lba_end;
}PART;

struct MBR {
	char  asm_code[446];
	PART part[4];
	char magci[2];
} __attribute__((packed));
;
int main(int argc, char *argv[])
{
	FILE *fp, *out;
	struct MBR mbr;
	fp=fopen("/dev/sdb", "r");
	if(fp == NULL)
	{
		die<char>("open /dev/sdb error\n");
	}
	out=fopen("out.mbr", "w");
	
	int ret=	fread((char *)&mbr, sizeof(mbr), 1, fp);
	
	memset(mbr.part, '\0', 64);
	mbr.part[0].boot=0x80;
	mbr.part[0].partion_type=0x0c;	
	mbr.part[0].lba_start=64;
	mbr.part[0].lba_end=12097152;
	fseek(fp, 0, SEEK_SET);	
	int cur=ftell(fp);
	//	ret=fwrite(&mbr, sizeof(mbr), 1, fp);	
	ret=fwrite(&mbr, sizeof(mbr), 1, out);	
	printf("%d\n", ret);
	fclose(fp);
	fclose(out);
	return 0;
}
