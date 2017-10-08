#include <string>
#include <vector> 
#include <iostream>
using namespace std;
int nest(vector<string> in, string str);
int main()
{
    vector<string> vec_str;
    vec_str.push_back("a");
    vec_str.push_back("b");
    nest(vec_str, "f");
        
}

int nest(vector<string> in, string str)
{
    int size=in.size();
    vector<string >    vec_tmp(in.begin(), in.begin()+size -1);
    string tmp;
	tmp=str;

    if(size ==1)
    {
       cout<<in[0]+str<<endl;
       return 1;
    }
    else
    {
        tmp+=in[size-1];
        nest(vec_tmp, tmp);
    }
	return 1;
}

