//������operator<<���ص�ʱ��,����Ϊ friend ostream& operator<<(ostream& os,const Type& t)��const���Էǳ���Ҫ.�����Ƕ�copy(,,ostream_iterator)����.������һ������:
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iterator>  
#include <set>
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
        friend ostream& operator << (ostream& os,const Person& p)
        {
                os<<p.firstname<<" "<<p.lastname;
				return os;
        }
private:
        string firstname ;
        string lastname ;
        friend class PersonSort;
};

class PersonSort
{  
public:
        bool operator()(const Person& p1,const Person& p2) const
        {
                return (p1.lastname<p2.lastname ||(p1.lastname==p2.lastname) && (p1.firstname <p1.firstname));
        }
};

int main()
{
        typedef set<Person,PersonSort> PersonSet;
        int i;
        PersonSet ps;
        ps.insert(Person("hongjian","chen"));
        ps.insert(Person("lizhong","li"));
        ps.insert(Person("xuan","liu"));
        ps.insert(Person("zhongjie", "qian"));
        copy(ps.begin(),ps.end(),ostream_iterator<Person>(cout,"\n"));
        copy(ps.begin(),ps.end(),ostream_iterator<Person>(cout,"||"));
//        cin >>i;

return 0;
}
