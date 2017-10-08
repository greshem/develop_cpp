#ifdef WINDOWSCODE
#include <hash_map>
using namespace stdext;
#else
#include <ext/hash_map>
using namespace __gnu_cxx;
#endif
#include <iostream>;
#include <string>
#include <vector>

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


struct eqstr
{
    bool operator()(const char* s1, const char* s2) const
    {
        return strcmp(s1, s2) == 0;
    }
};

int get_keys( hash_map<const char*, int, hash<const char*>, eqstr> & months, vector<string> &vec_string )
{
     hash_map<const char*, int, hash<const char*>, eqstr>::iterator it_map;                      
     for(it_map = months.begin(); it_map != months.end(); it_map++)
    {
         vec_string.push_back((*it_map).first);
    }
    return 1;
}

int get_values( hash_map<const char*, int, hash<const char*>, eqstr> & months, vector<string> &vec_string )
{
     char buf[16];
     hash_map<const char*, int, hash<const char*>, eqstr>::iterator it_map;                      
     for(it_map = months.begin(); it_map != months.end(); it_map++)
    {
         sprintf(buf, "%d", (*it_map).second);
         vec_string.push_back(buf);
    }
    return 1;
}

int main()
{   int i;
    hash_map<const char*, int, hash<const char*>, eqstr> months;
    hash_map<const char*, int, hash<const char*>, eqstr>::iterator it_map;
    vector<string> vec_string;
    vector<string> vec_values;
    vector<string>::iterator  it_keys;
    months["january"] = 31;
    months["february"] = 28;
    months["march"] = 31;
    months["april"] = 30;
    months["may"] = 31;
    months["june"] = 30;
    months["july"] = 31;
    months["august"] = 31;
    months["september"] = 30;
    months["october"] = 31;
    months["november"] = 30;
    months["december"] = 31;
    
   // for(it_map = months.begin(); it_map != months.end(); it_map++)
  //  {
   //      vec_string.push_back((*it_map).first);
   // }
   get_keys(months, vec_string);
   get_values(months, vec_values);

    cout<<"key's count = "<< vec_string.size()<<endl;
  
    sort(vec_string.begin(), vec_string.end());
    
    for(it_keys = vec_string.begin(); it_keys != vec_string.end(); it_keys++)
    {
         cout<<*it_keys<< "= " << months[(*it_keys).c_str()]<<endl;       
    }
    
    for(it_keys = vec_values.begin(); it_keys != vec_values.end(); it_keys++)
    {
        cout<<*it_keys<<endl;
        
    }
  //  cout << "september ->; " << months["september"] << endl;
  //  cout << "april     ->; " << months["april"] << endl;
   // cout << "june      ->; " << months["june"] << endl;
   // cout << "november  ->; " << months["november"] << endl;
//    cin >> i;
}
