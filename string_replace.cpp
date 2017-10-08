#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
#include <vector> 
#include <iostream> 
#include <algorithm>

//#2010_08_24_16:19:47 add by qzj
//遭到抛弃了， 请用 Baselib/Tools.hpp 里面的str_replace 函数。 
using namespace std;
void StringReplace(string & strBig, const string & strsrc, const string &strdst) ;
int main(int argc, char *argv[])
{
	string a("qianzhongjie__PATTERN__");
	StringReplace(a, "__PATTERN__", "198308190917");
	cout<<a<<endl;
	return 0;
}

void StringReplace(string & strBig, const string & strsrc, const string &strdst) 
{
        string::size_type pos=0;
        string::size_type srclen=strsrc.size();
        string::size_type dstlen=strdst.size();
        while( (pos=strBig.find(strsrc, pos)) != string::npos)
		{
                strBig.replace(pos, srclen, strdst);
                pos += dstlen;
        }
}
