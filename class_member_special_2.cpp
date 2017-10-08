//########################################################################
// 2011_03_31_17:16:47   ÐÇÆÚËÄ   add by greshem
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
//class template partial specialization

// primary template
template<class T, class I> class A {
//void f();
};

template<class T> class A<T,int> {
//void f();
void g();
//void h();
};
// member of class template partial specialization
template<class T1> void A<T1,int>::g() { cout <<"gtest "<<endl;}


using namespace std;
int main(int argc, char *argv[])
{
}
