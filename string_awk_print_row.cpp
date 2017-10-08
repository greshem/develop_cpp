#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iterator>  
using namespace std;
string   awk_1th(string strtmp);
int main()
{       
		cout<< awk_1th("aaa:bbb eee:fff ");
        //reverse(strtmp.begin(), strtmp.end());
        //copy(vect.begin(), it, ostream_iterator<string>(cout, "\n"));
        return 0;
}

string   awk_1th(string strtmp)
{
	string ret_str=strtmp.substr(0, strtmp.find(' ')); //awk -F\   '{print $1}' 
   		// vect.push_back(strtmp.substr(0, strtmp.find(':')));
        //vect.push_back(strtmp.substr(0, strtmp.find_last_of(':'))); 

	return ret_str;
}
