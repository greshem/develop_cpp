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
	cout<< "һ�صĴ�С��"<< (int)(sectorPerCluster)<<"������"<<endl;	

	short reverse_sector;
	int fatLen;	
	sdb1.Seek(0x0E, SEEK_SET);	
	sdb1.Read((char*)&reverse_sector, sizeof(short));
	cout<<"������������ "<< reverse_sector<<"������"<<endl;

	sdb1.Seek(0x24, SEEK_SET);
	sdb1.Read((char *) &fatLen, 4);
		
	cout<<"һ��fat ��С�� "<< fatLen<<"������"<<endl;

	cout<<"������ƫ���� "<<(reverse_sector+2*fatLen)*512<<endl;
	return 0;
}
