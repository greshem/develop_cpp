#include <iostream> 
#include <string> 
#include <vector> 
#include <iterator> 
#include <algorithm>
using namespace std;
typedef struct info {
       int age;
       string name;
		info()
		{
			age=int();
			name="noname";
		}
       info(int age, string name):age(age),name(name){};
       
       friend ostream & operator << (ostream &os, const info &in)
       {
              os<<in.age<<"||"<<in.name<<endl;
              return os;
       }
       info operator = (const info &in)
       {    
            info tmp;
                tmp.age=in.age;
                tmp.name=in.name;
                return tmp;
       }
       };
       
int main()
{
      vector<info> vec_info;
      for(int i=0; i<=100; i++)
      {
      vec_info.push_back(info(i,"w2enwen"));
      }
      copy(vec_info.begin(), vec_info.end(), ostream_iterator<info>(cout,"\n"));
      cout<<vec_info[0]<<endl;
      
}
