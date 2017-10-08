#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
#include <Baselib.hpp>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
//#include <dirent.h>
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
#include <gtest/gtest.h>
#include <valarray>
//2010_09_08 by greshem. 

template <class T>
void ValPrint(const valarray<T>& vOut)
{   
    size_t vsize = vOut.size();     //取数组元素的个数  
    for(size_t st=0; st<vsize; st++)
	{   
        cout.width(15);             //                  
        cout << vOut[st] << ' ';
	}
    cout << endl; 
}      
using namespace std;
int main(int argc, char *argv[])
{
	valarray<int> tmp(1, 100);
	valarray<int> tmp2(4, 100);
	valarray<int> tmp3=tmp+tmp2;
	ValPrint((tmp3));
	return 0;
}
