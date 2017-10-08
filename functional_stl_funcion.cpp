#include <stdlib.h>
//20100608 qzj. 
//#include <MLmyUnit.hpp>
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
#include <functional>
using namespace std;
int main(int argc, char *argv[])
{
	// multiplies<int> mul;
	struct multiplies<int> mul;
	typedef  multiplies<int> int_mul;
	int_mul mul2;
	
	 divides<int> div;
	minus<int> minus;	
	plus<int> plus;
	modulus<int>  mod;
	equal_to<int> equal;
	
	not_equal_to<int> not_equal;
	greater<int> greater;
	less_equal<int> less_equal;
	logical_and<int> logical_and;
	logical_or<int> logical_or;
	logical_not<int> logical_not;
	
//	binary_negate<less_equal<int> > bb;;

	cout<<mul(33,44)<<endl;
	cout<<mul2(3,4)<<endl;
	cout<<div(33,3)<<endl;
	cout<<"minus(44,4)"<<minus(44,4)<<endl;
	cout<<"plus(3,3)"<<plus(3,3)<<endl;
	cout<<"mod(11,3)"<<mod(11,3)<<endl;
	cout<<"equal(3,4)"<<equal(3,4)<<endl;
	cout<<"not_equal(3,4)"<<not_equal(3,4)<<endl;
	cout<<"greater(5,3)"<<greater(5,3)<<endl;
	cout<<"less_equal(4,4)"<<less_equal(4,4)<<endl;
	return 0;
}
