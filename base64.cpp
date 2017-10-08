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
#include "base64.hpp"
	// is_base64
   	// base64_encode
   	// base64_decode

int main(int argc, char*argv[])
{
	string str("wenshuna");
	string code=base64_encode((const unsigned char *)str.c_str(), str.size() );	
	cout<<code<<endl;
}
