//#include <QzjUnit.hpp>
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
#include <string>
using namespace std;
class Person
{
public:

        Person(const string& firstname,const string& lastname)
        {
                this->firstname=firstname;
                this->lastname=lastname;
        }
  
       //���û��const,��ô�����copy()�ᱨ��һ�Ѵ���,����Ϊconst��һ����ϰ��
        friend ostream& operator <<(ostream& os,const Person& p)
        {
                os<<p.firstname<<" "<<p.lastname;
			return os;
        }
private:
        string firstname ;
        string lastname ;
        friend class PersonSort;
};
int main()
{
	Person a("aa", "bb");
}
