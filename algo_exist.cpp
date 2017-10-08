#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
 struct Exist
{
	string Target;
	Exist( const string& t ):Target(t){};
	bool operator()( const string& s ) { return s == Target; }
}; 

main()
{     int i;
      string test="qianqian";
      Exist a("qianqian");
      if(a(test))
      {
                 printf(" equal\n");       
      }
      else
      {
          printf("not equal\n");
      }
     // cin >> i;
}
