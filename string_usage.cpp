
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
using namespace std;
//find_first_of
//和find 还有有区别的. 
//sizeof    用find_first_of("sizeofdddd") 是可以的. 
//
TEST(string , find_first_fo)
{
	string in="asi=bbb";
	
	//string::size_type pos_sizeof=in.find_first_of("sizeof");
	string::size_type pos_sizeof=in.find("sizeof");
	EXPECT_EQ(pos_sizeof, string::npos);
}

int is_sizeof_eq_eq_line(string in)
{
	
	string::size_type pos_start=in.find_first_of("=");
	string::size_type pos_end=in.find_last_of("=");
	string::size_type pos_sizeof=in.find("sizeof");
	if(pos_sizeof == string::npos)
	{
		return 0;
	}

	if((pos_start!= string::npos) &&(pos_end!= string::npos) &&  (pos_start==pos_end )) 
	{
		return 0;
	}
	return 1;
}
//=....= 中间的字符串.
TEST(string, middle_string)
{
	string test="sizeof =1+1+3+4=10";
	std::string::size_type pos_start=test.find_first_of("=");
	std::string::size_type pos_end=test.find_first_of("=");

	string middle= test.substr(pos_start+1, pos_end);
	EXPECT_EQ(middle, "1+1+3+4");

	//肯定和 npos 不等.
	pos_start=test.find_first_of("sizeof");
	EXPECT_NE(pos_start, string::npos);

	EXPECT_EQ(is_sizeof_eq_eq_line(test), 1);
	EXPECT_EQ(is_sizeof_eq_eq_line("sizeof=333333"), 0);
	EXPECT_EQ(is_sizeof_eq_eq_line("sizeof=333333=33"), 1);
	EXPECT_EQ(is_sizeof_eq_eq_line("sizeo=333333=33"), 0);
	EXPECT_EQ(is_sizeof_eq_eq_line("sizeo=333333=33"), 0);
}

//找不到 npos 的使用. 
TEST(string, never_find)
{
	string test="sizeof =1+1+3+4=10";
	std::string::size_type pos_start=test.find_first_of("#");
	EXPECT_EQ(pos_start, string::npos );
}
int main(int argc, char * argv[])
{
	testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


