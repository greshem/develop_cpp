#include <algorithm>
#include <fstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <vector> 
#include <assert.h>
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//#include <gtest/gtest.h>
//2010_08_26 by greshem. 


struct sShortDirEntry {
        char DIR_Name[11];              // Short name
        char DIR_Atrr;                // File attributes
        char DIR_NTRes;               // Reserved for NT
        char DIR_CrtTimeTenth;        // Time of creation in ms
        unsigned short DIR_CrtTime;          // Time of creation
        unsigned short DIR_CrtDate;          // Date of creation
        unsigned short DIR_LstAccDate;       // Last access date
        unsigned short DIR_FstClusHI;        // Hiword of first cluster
        unsigned short DIR_WrtTime;          // Time of last write
        unsigned short DIR_WrtDate;          // Date of last write
        unsigned short DIR_FstClusLO;        // Loword of first cluster
        int  DIR_FileSize;         // file size in bytes
} __attribute__((packed));

using namespace std;
int main(int argc, char *argv[])
{
	assert(sizeof(sShortDirEntry)==32);

	MFile<char> dirEntryCluter;
	if( ! 	dirEntryCluter.Open("cluster1_dir_entry"))
	{
		printf("open file error");
	}
	
	struct sShortDirEntry entry;
	while( dirEntryCluter.Read((char *) &entry, sizeof(entry)) == sizeof(entry) )	
	{
		printf("##############################\n");
		printf("Name %s\n", entry.DIR_Name);
		printf("cluster %d\n", (entry.DIR_FstClusHI<<16)|entry.DIR_FstClusLO);
		printf("size %d\n", entry.DIR_FileSize);

	}
	return 0;
}
