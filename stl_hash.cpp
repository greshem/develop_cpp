#ifdef WINDOWSCODE
#include <hash_map> 
#else
#include <ext/hash_map>
using namespace __gnu_cxx;
#endif

#include <iostream> 
#include <string>
#include <algorithm> 
using namespace std;

int print( pair<int, string> it)
{
    std::cout<<it.first<<"-->";
    std::cout<<it.second<<std::endl;
    return 0;
}
int main(){
        hash_map<int, string> mymap;
        mymap[9527]="唐伯虎点秋香";
        mymap[1000000]="百万富翁的生活";
        mymap[10000]="白领的工资底线";
        mymap[10001]="白领的工资底线2";
        mymap[10002]="白领的工资底线3";
        mymap[10003]="白领的工资底线4";
        mymap[10004]="白领的工资底线5";
        mymap[10005]="白领的工资底6线";
        //if(mymap.find(10000) != mymap.end())
        //{
        //     std::cout<<mymap[10000]<<std::endl;
        //}
        std::for_each(mymap.begin(), mymap.end(), print);
       //std::cin.get();
}
