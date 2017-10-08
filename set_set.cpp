#pragma warning(disable:4786)
//########################################################################
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
//#include <dirent.h>
#include <unistd.h>
//#include <locale.h>
//#include <sys/stat.h>
//#include <sys/ioctl.h>
#include <errno.h>
//#include <fcntl.h>
#include <time.h>
#include <assert.h>
//#include <stringprep.h>
#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
#include <map> 
using namespace std;
typedef pair< int, string >  INT_STR_PAIR;

struct mulit_and_print
{
	int sum ;
	void operator  ()  (int in)
	{
		printf("%d\n", in);
		sum+=in;
	}
	void operator  ()  (const string &in)
	{
         printf("%s %s\n", in.c_str(), in.c_str());
    }
    
    void operator ()  (INT_STR_PAIR in)
    {
         printf("%d->%s\n", in.first, in.second.c_str());
    }
};
int main()
{
      char buf[256];
//      int ret;
      pair<int, string> tmp_pair;
      set<string> info;
     // vector< pair<int, string> > info;
      set<string>::iterator set_it;
     // vector<string>::iterator it;
      int i;
      for(i=0; i<=100; i++)
      {
         sprintf(buf, "%d", i);
         //tmp_pair =  make_pair(i, string(buf));
         info.insert(string(buf));
         //info.push_back(tmp_pair );
      }
     //for_each(info.begin(), info.end(), mulit_and_print() );
//      random_shuffle(info.begin(), info.end());
      for_each(info.begin(), info.end(), mulit_and_print() );
  //   sort(info.begin(), info.end());
     cout<<"size  "<<info.size()<<endl;
     //cout<< "info[10]  "<<" first "<< info[10].first<< " second "<<info[10].second<<endl;
 //    cout<< info[10]<<endl;
     //cin >> i;
	return 0;
}
