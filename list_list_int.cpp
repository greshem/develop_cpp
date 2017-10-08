//主要是为了体现struct 的operator 操作符.  
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;
 struct Exist
{
	int Target;
	Exist( const int& t ):Target(t){};
	bool operator()( const int& s ) { return s == Target; }
}; 

main()
{
      list<int> list_int;
      list<int>::iterator it;
      int i;
      for(i=0; i<=10 ;i++)
      {
          list_int.push_back(i);
      }
      if( ( it = find_if(list_int.begin(), list_int.end(), Exist(8) )) != list_int.end()) 
      {
          cout<<"found it  "<<*it<<endl;
      }
      cout<<"current size "<<list_int.size()<<endl;
      list_int.erase(it);
      

      
      for(it = list_int.begin(); it!= list_int.end(); it++)
      {
             cout<<"<<"<<*it<<endl;
      }
      cout<<"current size "<<list_int.size();
      //cin >>i;
      return 0;
      
}
