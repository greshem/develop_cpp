//#2011_04_06_ 星期三 add by greshem
//########################################################################
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
//#include <Baselib.hpp>
#include <gtest/gtest.h>
#include <fstream>
#include <string> 
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//###################################################

char mbr[512];
TEST(endian , size)
{
	EXPECT_EQ( sizeof(mbr), 512 );
	EXPECT_EQ( sizeof(int), 4 );

	if(sizeof(long) == 8)//64bit
	{
		EXPECT_EQ( sizeof(long), 8 );
	}
	else
	{
		EXPECT_EQ( sizeof(long), 4 );
	}

	EXPECT_EQ( sizeof(long long ), 8 );
}

TEST(fat, info)
{
	EXPECT_EQ((1-1) ,0);
	
}

TEST(istringstream, test)
{
    {
        //istringstream iss;
        //iss.str("#123 1.23 aaa ,zzz kk,k oo.jjj");
        //istringstream iss("#123 1.23 aaa ,zzz kk,k oo.jjj");
        istringstream iss("a  1234 3.3333 ,zzz     kk,k oo.jjj");
        
        cout << iss.str() << endl;

        char ch;
        iss >> ch;
        //cout << ch << endl;
		EXPECT_EQ(ch, 'a');

        int i;
        iss >> i;
        //cout << i << endl;
        EXPECT_EQ(i, 1234);

		float f;
        iss >> f;
        //fixme , 浮点数如何 相等c++  中? 
        //EXPECT_EQ(f, 3.33333);

        
        char buf[1024]={0};
        iss >> buf;
        //cout << buf << endl;
		EXPECT_EQ(string(buf), string(",zzz"));

        //iss.ignore(100, ',');
        //iss >> buf;
        //cout << buf << endl;
    }
}

TEST(istringstream, float)
{
        istringstream iss("3.33333 ");
		float f;
        iss >> f;
        //fixme , 浮点数如何 相等c++  中? 
        //EXPECT_EQ(f, 3.33333);

}

int main(int argc, char * argv[])
{
	testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}

