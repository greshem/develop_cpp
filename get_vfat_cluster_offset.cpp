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
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//#include <gtest/gtest.h>
//2010_08_26 by greshem. 

template <typename T> class book {
};

using namespace std;
int main(int argc, char *argv[])
{

	
	MFile<char> sdb1;
	if(sdb1.Open("/dev/sdb1")!=1)
	{
		die<char>("open /dev/sdb1 error");		
	}
	
	char sectorPerCluster;
	sdb1.Seek(0x0D, SEEK_SET);	
	sdb1.Read(&sectorPerCluster, 1);
	cout<< "一簇的大小是"<< (int)(sectorPerCluster)<<"个扇区"<<endl;	

	short reverse_sector;
	int fatLen;	
	sdb1.Seek(0x0E, SEEK_SET);	
	sdb1.Read((char*)&reverse_sector, sizeof(short));
	cout<<"保留扇区数是 "<< reverse_sector<<"个扇区"<<endl;

	sdb1.Seek(0x24, SEEK_SET);
	sdb1.Read((char *) &fatLen, 4);
		
	cout<<"一个fat 大小是 "<< fatLen<<"个扇区"<<endl;

	cout<<"数据区偏移是 "<<(reverse_sector+2*fatLen)*512<<endl;
	return 0;
}
