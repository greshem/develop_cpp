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
#include <math.h>
//2010_08_25 by qzj. 

template <typename T> class vec
{
	T x, y, z;
	

public:
	vec():x(0),y(0),z(0){};
	vec(T a, T b ,T c):x(a),y(b),z(c){};
	void Dump()
	{
		cout<<"x "<<x<<endl;
		cout<<"y "<<y<<endl;;
		cout<<"z "<<z<<endl;;
	}
	vec &  operator =(const vec  &  other)
	{
		x=other.x;
		y=other.y;
		z=other.z;
		return (*this);
	}
	
	template   < typename G> vec &  operator * ( G scalar)
	{
		x=scalar*x;
		y=scalar*y;
		z=scalar*z;
		return (*this);
	}
	//叉乘
	vec CrossProduct(vec &a, vec &b)
	{
		vec ret;
		ret.x=((a.x*b.z)-(a.z*b.y));
		ret.y=((a.z*b.x) -(a.x*b.z));
		ret.z=((a.x*b.y)-(a.y*b.x));
		return ret;
	}
	//length
	T Magintude()
	{
		return sqrt((x*x)+(y*y)+(z*z));
	}
	float Length()
	{
		return sqrt((x*x)+(y*y)+(z*z));
	}

	vec unitVec( vec &in)
	{
		vec ret=in;
		T len=ret.Magintude();		
		ret.x=ret.x/len;
		ret.y=ret.y/len;
		ret.z=ret.z/len;	
		return ret;
	}

	bool operator ==  ( vec &other)
	{
		if(x==other.x && y==other.y && z==other.z)
		{
			return true;
		}	
		else
		{
			return false;
		}
	}
	//点乘
	vec DotProduct(vec a, vec b)
	{
		vec ret;
		ret.x=a.x*b.x;
		ret.y=a.y*b.y;
		ret.z=a.z*b.z;
		return ret;
	}	
	float InnerAngle( vec a, vec b)
	{
		float dp=DotProduct(a, b);
		float lena=a.Length();
		float lenb=b.Length();
		return acos(dp/(lena*lenb));
	}
	bool operator - (vec &other)
	{
		x=x-other.x;
		y=y-other.y;
		z=z-other.z;
		return (*this);
	}
	
	//#determines the direction angles of a vector
	vec DirAngles( vec &in)
	{
		vec unit= unitVec(  &in);
		vec ret(acos(unit.x), acos(unit.y), acos(unit.z));	
	}
	//PlaneUnitNormal(vec a, vec b , vec c)
	//UnitVectorPoints 连个点之前的方向的单元
	//sub TriAreaPoints 返回3 个点之间定义的三角形的面积。
	//
	//sub TripleProduct
//#returns vector triple product, which is a scalar calculated using the determinant of the orthogonal




};


using namespace std;
int main(int argc, char *argv[])
{
	vec<int> a(1,2,3);
	vec<int> b(a);
	a.Dump();

	b=b*2;
	b.Dump();
	if(a==b)
	{
		cout<<"Is equal"<<endl;
	}	
	else
	{
		cout<<"not equal"<<endl;
	}
	return 0;
}
