//20100601
//########################################################################
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
//#include <dirent.h>
#include <unistd.h>
//#include <locale.h>
//#include <sys/stat.h>
//#include <sys/ioctl.h>
#include <errno.h>
//#include <fcntl.h>
#include <time.h>
#include <assert.h>
//#include <stringprep.h>
//########################################################################
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
#include <Baselib.hpp>
#include <gtest/gtest.h>
#include <fstream>
#include <string> 
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
using namespace std;
int   main()
{
	ifstream   infile( "a.txt ",ios::binary);
	///ofstream   outfile( "b.txt ",ios::binary|filebuf::sh_none);
	ofstream   outfile( "b.txt ",ios::binary);//|filebuf::sh_none);

	if(!infile)
	{
		cout << "can 't   open   " << "a.txt " <<endl;
		exit(0);
	}
	if(!outfile)
	{
		cout << "can 't   open   " << "b.txt " <<endl;
		exit(0);
	}
	char   ch;
	while(infile.get(ch))
	{
	  outfile.put(ch);
	}

	return   0;
} 
