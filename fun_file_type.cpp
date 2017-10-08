#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
//########################################################################
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <locale.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <assert.h>
#include <stringprep.h>
using namespace std;
template <class T> struct print
{
         int operator () (T &in)
         {
           cout<<in<<endl;
           return 1;
         }
};

main()
{     
      int i=0;
      char buf[16];
      list<string> list_str;
      
      for(i = 0;i <= 100; i++)
      {
            sprintf(buf, "%d%d", i, i);
            list_str.push_back(buf);
      }
      for_each(list_str.begin(), list_str.end(), print<string>() );
//      cout<<list_str[10];
        list_str.sort();
    //  sort(list_str.begin(), list_str.end());
      //cin >>i;
      
}
