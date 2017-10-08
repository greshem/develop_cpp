#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
//#include <boost/bind.hpp>

//using namespace boost;
using namespace std;

struct  Person
{
    ~Person();
    Person(const string& _name, int _age)
        : name(_name), age(_age)
    {}
    int age;
    string name;
    friend bool operator < ( Person & In1, Person & In2)
    {
  		 //if ( strncmp(In1,In2.m_StringPtr,max(strlen(In1),In2.m_StringBufSize)) > 0 )
		if ( In1.age < In2.age )
		{
			return(true);
		}
		else
		{
			return(false);
		}
                 
    }
};
Person::~Person()
{}


class tagSrvInfo 
{
public:
	unsigned long	ServiceID;	//服务器编号
	unsigned long	SrvAddr;	//服务器IP地址
	unsigned short	SrvPort;	//服务端口

	tagSrvInfo()
	{ ServiceID = 0l; SrvAddr = 0l; SrvPort = 0; }

	bool operator==( const tagSrvInfo& other ) const
	{ return (	ServiceID == other.ServiceID && 
				SrvAddr == other.SrvAddr &&
				SrvPort	== other.SrvPort );	}
};
class test
{
      public:
      test();
      ~test();
      public: 
              int a;
              int b;
};
test::test()
{
}
test::~test()
{
}

class  MAppInfoDLL22
{ 
public:
       MAppInfoDLL22();
       ~MAppInfoDLL22();
public:
  bool m_bStartupAppInfo;
  char *  m_pAppInfo_Instance;
  char *  m_pAppInfo_Release;
  char *  m_pAppInfo_GetDllVersion;
  char *  m_pAppInfo_IdleFunction;
  char *  m_pAppInfo_ProcUserRequest;
  char *  m_pAppInfo_GetDllStatus;
};

MAppInfoDLL22::MAppInfoDLL22()
//			:m_bStartupAppInfo(false),m_pAppInfo_Instance(NULL),m_pAppInfo_Release(NULL),
//			 m_pAppInfo_GetDllVersion(NULL),m_pAppInfo_IdleFunction(NULL),
//			 m_pAppInfo_ProcUserRequest(NULL),m_pAppInfo_GetDllStatus(NULL)
{
}

    
int main()
{
    list<Person> col;
    int j;
    list<Person>::iterator pos;

    col.push_back(Person("Tom", 10));
    col.push_back(Person("Jerry1", 12));
    col.push_back(Person("Jerry2", 12));
    col.push_back(Person("Jerry3", 15));
    col.push_back(Person("Jerry4", 16));
    col.push_back(Person("Jerry5", 17));
    col.push_back(Person("Jerry6", 18));
    col.push_back(Person("Jerry7", 122));
    col.push_back(Person("Mickey8", 9));

    Person eldest =
        *max_element(col.begin(), col.end() );//>=1.33
   
    cout << eldest.name;
//    cin  >> j;
}
