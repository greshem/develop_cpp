//########################################################################
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
#include <Baselib.hpp>
#include <gtest/gtest.h>
#include <fstream>
#include <string> 
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include <dirent.h>
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
        }
private:
        string firstname ;
        string lastname ;
        friend class PersonSort;
};
int main()
{
	return 0;
}
