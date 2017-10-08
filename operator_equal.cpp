#include <fstream>
#include <string> 
#include <sstream>
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h> 
using namespace std;
class Index{
private:
	int x;
	int y;
	int z;

public:
	Index(int a, int b, int c):x(a),y(b),z(c){};
	friend  bool operator   == (const Index &a , const Index &b) ;
	bool operator == (int a);
};

bool operator == (const Index &a , const Index &b) 
{
	if( a.x == b.x && a.y==b.y && a.z == b.z)
	{
		return true;
	}
	return false;
}

bool Index::operator ==  (int a)
{
	if( x == a )
	{
		return true;
	}
	return false;

}

int main()
{
	Index a(1,2,3);
	Index b(1,2,3);
	assert(a==b);
	assert(a==1);
	//assert
}
