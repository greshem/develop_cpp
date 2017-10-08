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
  
       //如果没有const,那么下面的copy()会报告一堆错误,重载为const是一个好习惯
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
