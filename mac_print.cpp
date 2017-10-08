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
//2010_07_15 换了一种方式 用 tmp[256]+ snprintf 的方式。 
using namespace std;
//typedef struct _mac 
//

template< class T> T  MyRand()
{
	T tmp;
	return tmp;
}

 class _mac 
{
public:
	int a;
	int  b;
	int c;
	int  d;
	int e;
	int  f;
	friend ostream & operator << (ostream &in, const _mac  & mac)
	{
		char tmp[256];
		memset(tmp, '\0', sizeof(tmp));
#ifdef WINDOWSCODE
		_snprintf(tmp, 256 ,  "%2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x", mac.a, mac.b,mac.c, mac.d, mac.e, mac.f );
#else

		snprintf(tmp, 256 ,  "%2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x", mac.a, mac.b,mac.c, mac.d, mac.e, mac.f );
#endif
		//in <<mac.a<<":"<<mac.b<<":"<<mac.c<<":"<<mac.d<<":"<<mac.e<<":"<<mac.f<<endl;
		in << string(tmp);
		return  in ;
	}
} ;

template<> _mac MyRand()
{
	_mac tmp;
	tmp.a=rand()%254;
	tmp.b=rand()%254;
	tmp.c=rand()%254;
	tmp.d=rand()%254;
	tmp.e=rand()%254;
	tmp.f=rand()%254;
	return tmp;	
}
int main()
{
	_mac tmp;
	tmp=MyRand<_mac> ();
	cout<<tmp;
}
