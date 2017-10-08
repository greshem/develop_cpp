#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
//#include <dirent.h>
#include <fstream>
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
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
	bool operator < (const SockInfo &other) const
	{
		if(nSerno< other.nSerno && nUserID < other.nUserID)
		{
		return 1;
		}
		return 0;
	}
	bool operator > ( const SockInfo &other)
	{
		if(nSerno> other.nSerno && nUserID > other.nUserID)
		{
		return 1;
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
	map< SOCKETINFO , int > mapSockInfo;
//	mapSockInfo.insert(make_pair(SOCKETINFO(33,44), 10));
	mapSockInfo.insert(sPair(SOCKETINFO(33,444), 442));
	mapSockInfo.insert(sPair(SOCKETINFO(337,444), 8888));
	mapSockInfo.insert(sPair(SOCKETINFO(333,444), 441));
	mapSockInfo.insert(sPair(SOCKETINFO(334,444), 443));
	mapSockInfo.insert(sPair(SOCKETINFO(336,444), 444));
	SOCKETINFO 	a(323,44);
	SOCKETINFO 	b(323,444);
	sPair c=sPair(SOCKETINFO(333,444), 44);
	if(a==b)
	{
		cout<<"succes"<<endl;
	}	
	cout<<"#############"<<endl;
	cout<<(*mapSockInfo.find(SOCKETINFO(337,444))).second<<endl;
	//cout<<(*mapSockInfo.find(SOCKETINFO(337,444))).first<<endl;
	cout<<b<<endl;
	
	return 0;
}
