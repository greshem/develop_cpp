#include <iostream>
#include <string>
//########################################################################
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
//#include <dirent.h>
#include <unistd.h>
#include <locale.h>
#include <sys/stat.h>
//#include <sys/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <assert.h>
//#include <stringprep.h>
using namespace std;
main()
{     int i;
      char *test=(char*)malloc(16);
      char *test2=(char*)malloc(16);
  //    test=NULL;
    //  test2=NULL;
      //memset(test, 'a', 16);
      //memset(test2, 'a', 16);
      string a=string(test);
      string b=string(test2);
      
      cout<<a.size()<<endl;
      cout<<b.size()<<endl;
      if(a==b)
      {
              cout<<"success"<<endl;
      } 
      //cin >>i;
      
}
