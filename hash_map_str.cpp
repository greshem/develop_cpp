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
        a["abc"] = 1; // ��һ��һִ�еĻ�������ֱ���˳�

        system("pause");
} 

/*
template<> struct hash<string>::operator()(const string &)
�����������ݹ顣

����������

        template<> struct hash<string>
        {
                size_t operator()(const string& s) const
                {
                        return __stl_hash_string(s.c_str());
                }
        };*/
