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
//#include <Baselib.hpp>
//#include <dirent.h>

using namespace std;
TEST(SEEK, fd)
{
	
	unlink("test.txt");
	int fd;

	fd=open("test.txt", O_CREAT| O_RDWR);
	if(fd <=0)
	{
		printf("open file error");
		exit(-1);
	}
	//lseek(fd, 1024, SEEK_END);
	EXPECT_EQ(lseek(fd, 1020, SEEK_SET), 1020);
	EXPECT_EQ(write(fd, "1234", 4), 4);
	//perror("write");
	EXPECT_EQ(lseek(fd, 0, SEEK_CUR), 1024);
	EXPECT_EQ(lseek(fd, 0, SEEK_END), 1024);
	close(fd);
	//EXPECT_EQ(filesize<char>("test.txt"),  1024);
	
}


int main(int argc, char * argv[])
{
	testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}

