#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
struct Exist
{
	string Target;
	Exist( const string& t ):Target(t){};
	bool operator()( const string& s ) { return s == Target; }
}; 
struct Data
{
       int a;
       int b;
       Data(int x, int y): a(x), b(y){}
       
       bool operator () (const Data& other) { return a== other.a && b== other.b ;}
       void operator () (int x, int b) { a=a++;b=b++;}
};
main()
{
      string a="qianqian";
      list<string> list_str;
      list <Data> list_data;
      
      Data tmp(1,2),tmp2(2,3);
 //     Data tmp(1,20);
        tmp(1,20);
        for (int i=0; i<=30; i++)
        { 
            tmp(1,i);
            list_data.push_front(tmp);
      }
 //     list_data.push_front(tmp(1,4));
    //  list_data.push_front(tmp(1,2));  
     // list_data.push_front(tmp(1,3));  
     // list_data.push_front(tmp(1,4));  
     // list_data.push_front(tmp(1,5));
      //list_data.push_front(tmp(1,6));  
      //list_data.push_front(tmp(1,7));  
      
      list<Data>::iterator  it;
      cout << "size "<< list_data.size()<<endl;
      
     // find_if(list_str.begin(), list_str.end(), Exist("qianl) );
      if(   (it=find_if(list_data.begin(), list_data.end(), Data(tmp)) )!= list_data.end()  )
      {
               cout <<"find success\n"<<endl;
      }
      else
      {
          cout <<"find failure "<<tmp2.b<<"\n"<<endl;
      }
    //while(1)
	// {
	// cin >> a;
	//cout << a<<endl;
	//}
      
      return 0;
}
