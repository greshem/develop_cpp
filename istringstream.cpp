//#2011_04_06_ ÐÇÆÚÈý add by greshem
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void test()
{
    {
        //istringstream iss;
        //iss.str("#123 1.23 aaa ,zzz kk,k oo.jjj");
        istringstream iss("#123 1.23 aaa ,zzz kk,k oo.jjj");
        
        cout << iss.str() << endl;

        char ch;
        iss >> ch;
        cout << ch << endl;

        int i;
        iss >> i;
        cout << i << endl;

        float f;
        iss >> f;
        cout << f << endl;

        char buf[1024];
        iss >> buf;
        cout << buf << endl;

        iss.ignore(100, ',');
        iss >> buf;
        cout << buf << endl;
    }
}

int main(int argc, char* argv[])
{   
    test();
    return 0;
}

