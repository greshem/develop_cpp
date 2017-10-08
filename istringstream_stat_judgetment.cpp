//########################################################################
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
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
int main()
{
	//istringstream iss("a b c ");
	istringstream iss("a b c d ");
	string a;
	string b;
	string c;
	string d;

		
	if(!( iss >> a))
	{
		cout<<"a not ok "<<endl;
	}

	if(!( iss >> b))
	{
		cout<<"b not ok "<<endl;
	}

	if(!( iss >> c))
	{
		cout<<"c not ok "<<endl;
	}

	if(!( iss >> d))
	{
		cout<<"d not ok "<<endl;
	}


}
