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
//#include <dirent.h>
#include <complex> 
using namespace std;
int main()
{
	complex<double> cda(33,44);
	cout<< cda<<endl;
	complex<double> b(23,14);
	complex<double> c(13,24);
	cout<<real(cda)<<endl;
	cout << "23 cos(cda) = " << cos(cda) << endl;
	cout << "29 norm(cda) = " << norm(cda) << endl;
	cout << "cda *b "<<cda*b<<endl;

}
