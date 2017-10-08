#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
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
#include <gtest/gtest.h>
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif

#include <pcap.h>
//2010_09_20 by greshem. 


using namespace std;
int main(int argc, char *argv[])
{

	if(argc != 2)
	{
		die<char>("Usage: %s file.cap\n", argv[0]);
	}
	char buffer[65536];
	memset(buffer,'\0', sizeof(buffer));
	MString<char> filename(argv[1]);
	MFile<char> pcap;
	if( pcap.Open(filename) != 1)
	{
		die<char>("open file error\n");
	}
	struct pcap_pkthdr pkg_header;
	pcap_file_header header;
	assert(sizeof(header)==24);
	pcap.Read((char *) &header, 24);
	
	int ret=0;	
	while( (ret=pcap.Read((char*) &pkg_header, sizeof(pcap_pkthdr)) ) > 0)
	{
		cout<<"len ->"<<pkg_header.len<<endl;
		memset(buffer,'\0', sizeof(buffer));
		pcap.Read((char *)buffer, pkg_header.len);
		if(pkg_header.len> 100)
		{
		//	printf("%s", buffer+54);
		}
		//pcap.Seek(pkg_header.len, SEEK_CUR);
	}
		
	
	return 0;
}
