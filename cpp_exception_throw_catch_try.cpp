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
//#include <dirent.h>
//#include <gtest/gtest.h>

class IniFileError2: public std::exception
{
public:
  IniFileError2(): m_msg("Unspecified IniFile Error"){}

  IniFileError2(const char* msg): m_msg(msg){}

  const char* what() const throw()
  {
    return m_msg;
  }

private:
  const char* m_msg;
};



//###############################################################################
using namespace std;
int main(int argc, char *argv[])
{
	
	string errStr;
	IniFileError2 iniErr;
	try 
	{
		throw IniFileError2("Å×³öÒì³£ÁË");
	}
	catch ( IniFileError2 &in)
	{
		cout<<"aaaaaaa"<<endl;
	}
	
	return 0;
}
