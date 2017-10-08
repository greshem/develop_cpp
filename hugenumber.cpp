//########################################################################
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
#include <Baselib.hpp>
#include <gtest/gtest.h>
#include <fstream>
//#include <dirent.h>
#include <string> 
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include "hugenumber.hpp"
int main()
{
	hugenumber big;
	unsigned int a=0xFFFFFFFF;
	big=300;
	//for(int i=1; i<=700; i++)
	for(int i=1; i<=4; i++)
	{
		big.multiplyWith(big);
	}
	big.println();
}
