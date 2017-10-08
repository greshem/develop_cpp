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
//#2010_09_02_17:11:15 add by greshem, 注意对字符的打印一定要用 unsigned char 否则不会得到 00-ff 的字符的。 
//#2010_09_02_17:32:21 add by greshem, 对于不同的结构生成不同的随机 结构。 用来处理qianlong 的协议， 最好了。 
//##2010_09_02_19:17:27 add by greshem, 该写成hexdump 的工具了。 
using namespace std;
//typedef struct _mac 
//

template< class T> T  MyRand()
{
	T tmp=T();
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
#endif
		//in <<mac.a<<":"<<mac.b<<":"<<mac.c<<":"<<mac.d<<":"<<mac.e<<":"<<mac.f<<endl;
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

typedef  struct buf16{
		unsigned char data[16];
		buf16()
		{
			memset(data, '\0', 16);
		}
		buf16(char *in)
		{
			memcpy(data, in, 16);
		}
		} BUF16;
template  <>  BUF16 MyRand()
{
	BUF16 tmp;
	for(int i=0; i<=16; i++)
	{
		tmp.data[i]=rand();	
	}
	
	return tmp;
}

int char2HexStr(int offset,  BUF16 &in)
{
	unsigned char low;
    unsigned char high;
	char *space=" ";
	int size=16;
    //char num2hex[16]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd' ,'e' , 'f'};
	printf("%8.8X   ", offset);
    for(int i=0; i<size;i++)
    {   
        low=in.data[i]%16;  
        high=(in.data[i]-low)/16;
       // low+='0';
        //high+='0';
		// write(1, num2hex+high, 1); 
		// write(1, num2hex+low , 1); 
		// write(1, space, 2);
		printf("%x", high);
		printf("%x", low);
		printf("%s", space);
	}   
	printf("\t\t");
    for(int i=0; i<size;i++)
	{
		if(in.data[i]>='0' && in.data[i]<'z')
		{
			putchar(in.data[i]);
		}
		else
		{
			putchar('.');
		}
	}	
	putchar('\n');
	return 1;
}

template <> int MyRand()
{
	return rand();
}
int main(int argc, char *argv[])
{
	timeval tv;
	gettimeofday(&tv, NULL); 
	srand(tv.tv_usec);
	//############################################################################### 
	// mac tmp;
	// tmp=MyRand<_mac> ();
	// cout<<tmp<<endl;;
	// cout<<MyRand<string>() <<endl;
	// cout<<MyRand<int>() <<endl;
	//没有特列化
	//cout<<MyRand<float>() <<endl;
	//cout<<MyRand<unsigned int>() <<endl;
	///###############################################################################/
	
	if(argv[1] ==NULL)
	{
		die<char>(" %s file", argv[0]);
	}	
	MFile<char> in;
	if((in.Open(argv[1])) !=1 )
	{
		die<char>("open file %s error", argv[1]);
	}
	char tmp[16];
		
	int ret=0;
	int offset=0;
	while((ret=in.Read(tmp, 16)) >0)
	{
		offset+=ret;
		BUF16 buf16(tmp);
		char2HexStr(offset,   buf16);
	}
}
