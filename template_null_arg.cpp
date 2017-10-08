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
//2010_08_10 by qzj. 


using namespace std;
template < class T, T x>     T test()
{
	return x;
};

//template < typename T, T x >  
//#2010_08_10_14:53:56 add by qzj
//特化当什么都没有的时候， 是int 
/*template< > 1  test()
{
	int tmp=rand();
	return tmp;
}*/

int main(int argc, char *argv[])
{
	int a=test<int, 3>();
	cout<<a<<endl;	
	return 0;
}
