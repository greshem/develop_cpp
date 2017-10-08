#include <iostream>
#include <iterator>
#include <vector>
#include <string> 
#include <stdlib.h> 
#include <algorithm>
// 
using namespace std;
typedef struct my_info{
       int age;
       string name;
       my_info(int _age, const string &in):
                   age(_age), name(in){};

       
        friend ostream& operator <<(ostream& os,const my_info& p)
        {
                os<<p.age<<" "<<p.name;
                return os;
        }
        friend bool operator >  (const my_info &info1, const my_info &info2)
        {
              return  (info1.age> info2.age)? true:false;
        }
        
        friend bool operator < (const my_info &info1, const my_info &info2)
        {
              return  (info1.age < info2.age)? true:false;
        }
        
        /*bool operator < (const my_info &info) const
        {
            // return age < info.age;
            return name < info.name;
        }*/
       friend bool operator ==(const my_info &info1, const my_info &info2)
        {
             return  (info1.age == info2.age)? true:false;
            //return info1.name == info2.name;
        }
        /*
        friend bool operator !=(const my_info &info1, const my_info &info2)
        {
               (info1.age != info2.age)? true:false;
        }*/
    /*    int operator () ()
        {
                 cout<<this<<endl;
        }*/
};
bool less_second(const my_info &info1, const my_info &info2)
{
     return info1.age < info2.age;
}
int my_print( struct my_info &in)
{
    cout<<in<<endl;
    return 1;
}

int main()
{
      vector< my_info> info_vec;
      int i;
      
 /*     my_info info(3,"name_333");
      my_info info2(4, "name_4444");
      my_info a = my_info(4,"name_44444");*/
      for(i = 1; i <= 200; i++)
      {
            info_vec.push_back(my_info(rand()%i%100,"aaaaaaa"));
      }
      
      //for_each(info_vec.begin(), info_vec.end(), my_print );
      sort(info_vec.begin(), info_vec.end());
      
      //重新调用一下, 才能真正的起到作用.  
      info_vec.erase(unique(info_vec.begin(), info_vec.end()), info_vec.end());
      
      for_each(info_vec.begin(), info_vec.end(), my_print );
      
      //cin >> i;
}
