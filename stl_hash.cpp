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
        mymap[9527]="�Ʋ���������";
        mymap[1000000]="�����̵�����";
        mymap[10000]="����Ĺ��ʵ���";
        mymap[10001]="����Ĺ��ʵ���2";
        mymap[10002]="����Ĺ��ʵ���3";
        mymap[10003]="����Ĺ��ʵ���4";
        mymap[10004]="����Ĺ��ʵ���5";
        mymap[10005]="����Ĺ��ʵ�6��";
        //if(mymap.find(10000) != mymap.end())
        //{
        //     std::cout<<mymap[10000]<<std::endl;
        //}
        std::for_each(mymap.begin(), mymap.end(), print);
       //std::cin.get();
}
