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

using namespace std;
int main(int argc, char *argv[])
{
	MString <char> str("sizeof_long.cpp");
	cout<<"sizeof_long= "<<sizeof(long)<<endl;
	cout<<"sizeof_long_long= "<<sizeof(long long )<<endl;
	cout<<"sizeof_int= "<<sizeof( int  )<<endl;
	cout<<"sizeof_char= "<<sizeof( char  )<<endl;
	cout<<"sizeof_float= "<<sizeof( float   )<<endl;
	cout<<"sizeof_double= "<<sizeof( double   )<<endl;
	cout<<"sizeof_long_double= "<<sizeof( long double   )<<endl;
	return 0;
}
