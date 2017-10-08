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
//2010_07_07 by qzj. 
using namespace std;
//typedef struct _mac 
typedef class _mac 
{
public:
	char a;
	char b;
	char c;
	char d;
	char e;
	char f;
	friend ostream &  operator << (ostream &in, const _mac  & mac)
	{
		//cout.unsetf(ios::dec);
		//cout.setf(ios::hex);
		//cout<<resetiosflags(ios::dec);
	//		in <<hex <<mac.a<<":"<<mac.b<<":"<<mac.c<<":"<<mac.d<<":"<<mac.e<<":"<<mac.f<<endl;
		in<<oct<<mac.a<<endl;
		//cout.setf(ios::hex);
		//cout.setf(ios::dec);
		return  in ;
	}
} MAC;
template< class T> T  MyRand()
{
	T tmp;
	return tmp;
}

template< > string  MyRand()
{
	string tmp=RandString<char> (10);
	return tmp;
}
template<> MAC MyRand()
{
	MAC tmp;
	tmp.a=rand()%254;
	tmp.b=rand()%254;
	tmp.c=rand()%254;
	tmp.d=rand()%254;
	tmp.e=rand()%254;
	tmp.f=rand()%254;
	return tmp;	
}
template<> int MyRand()
{
	int tmp=rand();
	return tmp;
}



using namespace std;
template<class T> int init( vector<T> &in)
{
	typedef typename vector<T>::iterator IT;
	IT it;
	for(it=in.begin(); it!=in.end(); it++)
	{
		*it=MyRand<T>();
	}
	
	return 1;
}
template< class T> int  dump(T &in)
{
	//typedef T::iterator it;
	typedef typename   T::iterator IT;
	IT it;
	
	for(it=in.begin(); it!= in.end(); it++)
	{
		cout<<*it<<endl;
	}
	return 1;
}
template <class T> int test(T in)
{
	cout<< in<<endl;
	return 1;
}
int main(int argc, char *argv[])
{
#ifdef WINDOWSCODE
	srand(100);
#else
	srandom(getpid());
#endif
//	vector<string> vecStr(100);
//	init(vecStr);		
//	dump<vector<string> > (vecStr);

//	vector<int> vecInt(10);
//	init(vecInt);
//	dump<vector<int> > (vecInt);

//	vector<MAC> vecMAC(100);
//	dump<vector<MAC> > (vecMAC);
	MAC tmp=MyRand<MAC>();
	cout<<tmp;
	return 0;
}
