#include <algorithm>
#include <boost/array.hpp>
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
//###################################################
//###################################################
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>

using namespace std;
int main(int argc, char *argv[])
{
	typedef boost::array<float, 22> Array;
	boost::array<float, 44> test;

	//Array a={{1,1,1,1,1,1,1}};
	Array a;
	//cout<<a.size()<<endl;
	copy(a.begin(), a.end(), ostream_iterator<float>(cout, "\n"));	
	cout<<"#################################################"<<endl;
	copy(test.begin(), test.end(), ostream_iterator<float>(cout, "\n"));	
return 0;
}
