#include <algorithm>
#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <iostream> 
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <vector> 
//########################################################################
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>

using namespace std;
TEST(fseek_write, FILE)
{
	
		
	unlink("test.txt");
	FILE *fp=fopen("test.txt", "w+");
	if(fp==NULL)
	{
		printf("open file error");
	}
	fseek(fp, 10239, SEEK_END);
	EXPECT_EQ(ftell(fp), 10239);	
	EXPECT_EQ(lseek(fileno(fp), 0, SEEK_CUR), 10239);	
	
	fwrite("1", 1, 1, fp);
	EXPECT_EQ(ftell(fp), 10240);	

	EXPECT_EQ(lseek(fileno(fp), 0, SEEK_END), 10240);	
}
int main(int argc, char * argv[])
{
	testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}

