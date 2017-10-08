#include <string>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;
class T
{
public:
    T(int i1,int i2,string s){score1 = i1;score2 = i2;name = s;totalscore = i1+i2;}
    int score1;
    int score2;
    int totalscore;
    string name;
    void print()
    {
    cout << name << "\t\t" << score1 << "\t\t" << score2 << "\t\t" << totalscore << endl;
    }
};
int main(int argc,char ** argv)
{
    int i;
    list<T> lstT;
    lstT.push_back(T(34,75,"TOM"));
    lstT.push_back(T(23,84,"JIM"));
    lstT.push_back(T(43,63,"JOHN"));
    lstT.push_back(T(61,69,"MIKE"));
    lstT.push_back(T(21,90,"ROBIN"));
    lstT.push_back(T(59,87,"SALLY"));
    lstT.push_back(T(54,72,"LINDA"));
    lstT.push_back(T(43,79,"JAMES"));
    for_each(lstT.begin(),lstT.end(),mem_fun_ref(&T::print));
    cout << endl;

    list<T*> lstTa;
    lstTa.push_back(new T(34,75,"tom"));//"guw" in vi can chanage a word lowercase.
    lstTa.push_back(new T(23,84,"jim"));
    lstTa.push_back(new T(43,63,"john"));
    lstTa.push_back(new T(61,69,"mike"));
    lstTa.push_back(new T(21,90,"robin"));
    lstTa.push_back(new T(59,87,"sally"));
    lstTa.push_back(new T(54,72,"linda"));
    lstTa.push_back(new T(43,79,"james"));
    for_each(lstTa.begin(),lstTa.end(),mem_fun(&T::print));
    cout << endl;
    //cin >> i;
}

