#include <list>
#include <iostream>
#include <algorithm>
 typedef struct info   {
       int age;
       int money;
        friend bool operator < (info & info1, info & info2)
       {
              if(info1.age > info2.age)
              {
                           return true;
              }
              else 
              {
                           return false;
              }
       };
} info2;
using namespace std;
main()
{     
      info tmp;
      list<info> list_int;
      list<info >::iterator it;
      int i;
      for (i=0; i<=100; i++)
      {
          tmp.age=i;
          tmp.money=i;
          list_int.push_front(tmp);
        //  list_int.push_back(i);
      }
      
      list_int.reverse(); 
  
       list_int.sort();
       
       it=list_int.begin();
      // it2;
    //  random_shuffle(list_int.begin(), list_int.end());
       
       // cout << *list_int[2]<<endl;
     for(it=list_int.begin(); it!= list_int.end(); it++)
      {
         cout<<"age  "<< (*it).age<<"| money  "<<(*it).money<<endl;
      }
      //cin >> i;
}
