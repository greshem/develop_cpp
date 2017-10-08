#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include <iostream>


using namespace std;
main()
{     
      int i;
      list<string>::iterator it;
      list<string> list_str;
      list_str.push_front("qianlong1");
      list_str.push_front("qianlong2");
      list_str.push_front("qianlong3");
      list_str.push_front("qianlong4");
      list_str.push_front("qianlong5");
      list_str.push_front("qianlong6");
      list_str.push_front("qianlong7");
      list_str.push_front("qianlong8");
      
  /*    for(it=list_str.begin();  it!= list_str.end(); it++)
      {
        if(*it == "qianlong2" || *it=="qianlong3" || *it=="qianlong4" )
        {
               list_str.erase(it);
               it--;
        }

      }
      
      for(it=list_str.begin();  it!= list_str.end(); it++)
      {
        cout<<*it<<endl;
      }*/
 //     list_str.erase(list_str.begin(), list_str.end());
      
      
      cout<< list_str.size()<<endl;
     // cin >> i;
     return 0;
}
