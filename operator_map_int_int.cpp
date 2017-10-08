#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
////#include <dirent.h>
#include <fstream>
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
//以双整数作为主键的时候需要主机， <  好的含义 
using namespace std;
typedef struct SockInfo
{
	int nSerno;
	int nUserID;
	SockInfo(int x, int y):nSerno(x),nUserID(y){};
	bool operator <=(const SockInfo &other)
	{
		if(nSerno<= other.nSerno && nUserID <= other.nUserID)
		{
		return 1;
		}
		return 0;
	}
	/*20091208 另外一种写法,  插入到MAP的时候会出现很多数据不能出现的情况。  
    bool operator < (const SockInfo &other) const
    {
         if( nSerno < other.nSerno && nUserID && other.nUserID )
         {
             return 1;
         }
         return 0;
    } 
	
    */ 
	bool operator < (const SockInfo &other) const
	{
		if(nSerno< other.nSerno )
		{
		return 1;
		}
		if( nSerno==other.nSerno) 
		{
			return nUserID<other.nUserID?1:0;
		}
		return 0;
	}
	bool operator > ( const SockInfo &other)
	{
		if(nSerno> other.nSerno )//&& nUserID > other.nUserID)
		{
		return 1;
		}
		
		if(nSerno==other.nSerno)
		{
			return nUserID>other.nUserID?1:0;
		}
		return 0;
	}
	bool operator == ( const SockInfo &other) const
	{
		if(nSerno== other.nSerno && nUserID == other.nUserID)
		{
		return 1;
		}
		return 0;
	}
	bool operator != ( const SockInfo &other)
	{
		if(nSerno!= other.nSerno && nUserID != other.nUserID)
		{
		return 1;
		}
		return 0;
	}
	friend  ostream  & operator  << (ostream &os ,  const SockInfo &other)
	{
		os<< "nSerno -> "<< other.nSerno<< "; nUserID -> "<< other.nUserID<<endl;
		return os;
	}
}SOCKETINFO;

int main(int argc, char *argv[])
{
	cout<<"map_sockinfo.cpp"<<endl;
	typedef pair<SOCKETINFO , int> sPair;
	SOCKETINFO 	a(323,44);
	SOCKETINFO 	b(323,444);
	map< SOCKETINFO , int > mapSockInfo;
	map< SOCKETINFO , int >::iterator  it;
	for(int i=0;i<=100;i++)
	{
		//mapSockInfo.insert(make_pair(SOCKETINFO(i,100), 10));
	}
	mapSockInfo.insert(make_pair(SOCKETINFO(33,444), 442));
	mapSockInfo.insert(make_pair(SOCKETINFO(33,4444), 8888));
	mapSockInfo.insert(sPair(SOCKETINFO(333,444), 441));
	mapSockInfo.insert(sPair(SOCKETINFO(334,444), 443));
	mapSockInfo.insert(sPair(SOCKETINFO(336,444), 444));
	mapSockInfo.insert(make_pair(a, 111));
	mapSockInfo.insert(make_pair(b, 111));
	mapSockInfo[a]=33333;

	sPair c=sPair(SOCKETINFO(333,444), 44);
	if(a==b)
	{
		cout<<"succes"<<endl;
	}	
	cout<<"#############"<<endl;
	cout<<" size "<<mapSockInfo.size()<<endl;
	//cout<<(*mapSockInfo.find(SOCKETINFO(337,444))).second<<endl;
	cout<<(*mapSockInfo.find(SOCKETINFO(337,444))).first<<endl;
	//cout<<(*mapSockInfo.begin()).first<<endl;
	//cout<<b<<endl;
	

	
	return 0;
}
