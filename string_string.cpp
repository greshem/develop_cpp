#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iterator>
//#incldue <stdio.h>
using namespace std;
int main(){
        ifstream in("list.txt");
        string strtmp;
        vector<string> vect;
        while(getline(in, strtmp, '\n'))
        vect.push_back(strtmp.substr(0, strtmp.find('\n')));// awk '{print }'
        vect.push_back(strtmp.substr(0, strtmp.find(' ')));//awk '{print $1}' 
       // vect.push_front(strtmp.substr(0, strtmp.find(' ')));
        //sort(vect.begin(), vect.end());
        vector<string>::iterator it;
        //vector<string>::iterator it=unique(vect.begin(), vect.end());
        it=vect.end();
        copy(vect.begin(), it, ostream_iterator<string>(cout, "\n"));
//        getline(cin,strtmp,'\n');
        return 0;
}
