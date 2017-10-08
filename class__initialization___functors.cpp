//演示: 构造类的时候, 里面再进行构造. 
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <string>
#include <iostream>
#define  WORD_CAPACITY 32 
using namespace std;
typedef struct person
{
        int age;
        string name;
        person(int _age, string const &_name):age(_age), name(_name) {} 
        person()
        {};
};

typedef struct book
    {
        int id;
        std::string author;
        std::string title;
        person man;
        book(int i, std::string const& a, std::string const& t, person const &_man)
            : id(i), author(a), title(t) ,man(_man) {id=id*2;}
        book()
        {};
        book(int i) :id(i)
        {};
        book(int i, std::string _title):id(i), title(_title){};
        
        int operator() ()
        {
            cout<<"####################################################"<<endl;
            cout<<"id ->" << id<<endl;
            cout<<"author ->" << author<<endl;
            cout<<"title ->"  << title<< endl;
            cout<<"person.age ->"<< man.age<<endl;
            cout<<"person.name ->"<<man.name<<endl;
            return 1;
        }
        int test(int i)
        {
            id=i;
        };
    };
    
main()
{     
      int i;
      vector<book> book_vec;
      vector<book>::iterator it;
      book tmp;
      for(i = 0; i <= 100; i++)
      {
            book_vec.push_back(book(i,"qanzhongjie", "summary",person(i, "qiznhongjie")));
      }
      for( it = book_vec.begin(); it != book_vec.end(); it++)
      {
      //(*book_vec.begin())();
        (*it)();
      }
      //cin >>i;
}
    
