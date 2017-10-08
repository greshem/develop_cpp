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
//2010_08_23 by qzj. 

template <typename T> class book {
};

using namespace std;
int main(int argc, char *argv[])
{
	string file;
	file_get_content<char>("/etc/passwd", file);	
	cout<<file;
	return 0;
}
