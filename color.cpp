#include "term_color.hpp"
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
//2010_08_24 by qzj. 


using namespace std;
int main(int argc, char *argv[])
{
	Term b;
	string red("red");
	for(int i=0; i<=100; i++)
	{
		b.red(cout)<<red<<endl;
		b.green(cout)<<i<<endl;
		b.yellow(cout)<<i<<endl;
		b.blue(cout)<<i<<endl;
		b.bold(cout)<<i<<endl;
		
	}
	return 0;
}
