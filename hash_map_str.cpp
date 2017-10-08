#include <string>
#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx;

namespace __gnu_cxx
{
        template<> struct hash<const string>
        {
                size_t operator()(const string& s) const
                { return hash()(s.c_str()); }
        };
        template<> struct hash<string>
        {
                size_t operator()(const string& s) const
                { return __stl_hash_string(s.c_str()); }
        };
}

int main( void )
{
        hash_map<string,int> a;
        a["abc"] = 1; // 这一句一执行的话，程序直接退出

        system("pause");
} 

/*
template<> struct hash<string>::operator()(const string &)
定义成了无穷递归。

如下修正：

        template<> struct hash<string>
        {
                size_t operator()(const string& s) const
                {
                        return __stl_hash_string(s.c_str());
                }
        };*/
