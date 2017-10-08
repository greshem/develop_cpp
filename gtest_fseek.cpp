#include <algorithm>
#include <fstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <vector> 
#include <gtest/gtest.h>
//########################################################################
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>

using namespace std;
TEST(fseek, file)
{
	
	FILE *fp;
	unlink("test.txt");
	fp=fopen("test.txt", "w+");
	if(fp ==NULL)
	{
		prinf("open file error");
		exit(-1);
	}

	EXPECT_EQ(ftell(fp), 0);
	fseek(fp, 1020, SEEK_CUR);
	fwrite("1234", 4, 1, fp);
	EXPECT_EQ(ftell(fp), 1024);
	fseek(fp, 0, SEEK_CUR);
	EXPECT_EQ(ftell(fp) ,  1024);
	fseek(fp, 0, SEEK_END);
	EXPECT_EQ(ftell(fp) ,  1024);



	fwrite("1234", 4, 1, fp);
	fseek(fp, -4, SEEK_CUR);
	EXPECT_EQ(ftell(fp) ,  1024);
	
	fseek(fp, 0, SEEK_END);
	EXPECT_EQ(ftell(fp) ,  1024+4);

	fseek(fp, 0, SEEK_CUR);
	EXPECT_EQ(ftell(fp) ,  1024+4);
	fclose(fp);
	
	EXPECT_EQ(filesize<char>("test.txt"), 1028);
}

char mbr[512];
TEST(endian , size)
{
	EXPECT_EQ( sizeof(mbr), 512 );
	EXPECT_EQ( sizeof(int), 4 );
	EXPECT_EQ( sizeof(long), 4 );
	EXPECT_EQ( sizeof(long long ), 8 );
}

TEST(fat, info)
{
	EXPECT_EQ((1-1) ,0);
	
}
int main(int argc, char * argv[])
{
	testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}

