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

//#include <arpa/inet.h>
//#include <netdb.h>
//#include <netinet/in.h>
//#include <sys/socket.h>
//#include <unistd.h>
//#include <sys/types.h>

//2010_07_07 by qzj. 
//2010_07_15 换了一种方式 用 tmp[256]+ snprintf 的方式。 
//#2010_09_02_17:11:15 add by greshem, 注意对字符的打印一定要用 unsigned char 否则不会得到 00-ff 的字符的。 
//#2010_09_02_17:32:21 add by greshem, 对于不同的结构生成不同的随机 结构。 用来处理qianlong 的协议， 最好了。 
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
	unsigned char a;
	unsigned char b;
	unsigned char c;
	unsigned char d;
	unsigned char e;
	unsigned char f;
	friend ostream & operator << (ostream &in, const _mac  & mac)
	{
		char tmp[256];
		memset(tmp, '\0', sizeof(tmp));
#ifdef WINDOWSCODE
		_snprintf(tmp, 256 ,  "%2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x", mac.a, mac.b,mac.c, mac.d, mac.e, mac.f );
#else

		snprintf(tmp, 256 ,  "%2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x", mac.a, mac.b,mac.c, mac.d, mac.e, mac.f );
		//in <<mac.a<<":"<<mac.b<<":"<<mac.c<<":"<<mac.d<<":"<<mac.e<<":"<<mac.f<<endl;
#endif
		in << string(tmp);
		return  in ;
	}
} ;


template<> _mac MyRand()
{
	_mac tmp;
	tmp.a=rand();
	tmp.b=rand();
	tmp.c=rand();
	tmp.d=rand();
	tmp.e=rand();
	tmp.f=rand();
	return tmp;	
}

template  <> string MyRand()
{
	return RandString<char>(10);
}

template <> int MyRand()
{
	return rand();
}
int main()
{
	timeval tv;
	gettimeofday(&tv, NULL); 
	srand(tv.tv_usec);
	_mac tmp;
	tmp=MyRand<_mac> ();
	cout<<tmp<<endl;;

	cout<<MyRand<string>() <<endl;

	cout<<MyRand<int>() <<endl;
	cout<<MyRand<float>() <<endl;
}
