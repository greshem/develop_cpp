#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <Baselib.hpp>
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
//2010_08_12 by qzj. 
using namespace std;;
	template <typename T>  class book;
//	 template <typename T> bool IsBigger (book<T> &lhs, book<T> &rhs);
	 template <typename T> bool IsBigger (book<T> &lhs , book<T> &rhs)
{
	//return lhs.getSn() < rhs.getSn();
	return lhs.sn< rhs.sn;
}
template <typename T>  bool  operator <  (book<T> &lhs, book<T> &rhs)
{
		return lhs.getSn() < rhs.getSn();
}
template <typename T> book<T> operator + (book<T> &lhs, book<T> &rhs)
{
		book<T> tmp(lhs.sn+rhs.sn);
		return tmp;
}


template <typename T> book<T> operator + (int sn, book<T> &rhs)
{
	book<T> tmp(sn);
	return (tmp+ rhs);
}

template <typename T> class book {
private:
	string name;
	int 	sn;
	string 	path;
	public:
		book()
		{
			name="no name";
			sn=0;
			path="no path";
		};
		book(int SN):sn(SN){};
	string getName()
	{
		return name;
	}
	int getSn()
	{
		return sn;
	}
	string getPath()
	{
		return path;
	}
	template <typename S> S  getOther()
	{
		return  !S();
	}
	friend bool IsBigger<T> (book<T> &lhs, book<T> &rhs);
	//这里可以写两个声明。 
	friend bool IsBigger<> (book<T> &lhs, book<T> &rhs);
	//friend bool IsBigger<T> (book<T> &lhs, book<T> &rhs);
	//这里不能声明成  friend bool IsBigger (book<T> &lhs, book<T> &rhs);
	//否则这个IsBigger 不是模板函数了。 

	friend bool  operator <  <T> (book<T> &lhs, book<T> &rhs);
	//friend bool  operator <   (book<T> &lhs, book<T> &rhs);
	//{
	//	return lhs.getSn() < rhs.getSn();
	//	}
	
	friend book<T> operator + <> (book<T> &lhs, book<T> &rhs);
	friend book<T> operator + <> (int num, book<T> &rhs);
	
};



using namespace std;
int main(int argc, char *argv[])
{
	book<vector<int >  > a(100);
	book<vector<int  > > b(200);
	if(a<b)
	{
		cout<<"yes"<<endl;
	}
	else
	{
		cout<<"panic"<<endl;
	}

	if(IsBigger(a,b))
	{
		cout<<"yes"<<endl;
	}
	else
	{
		cout<<"panic"<<endl;
	}
	book<vector<int> > c=333+b;
	cout<<c.getSn()<<endl;
	return 0;

}
