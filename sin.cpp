#include <algorithm>
#include <fstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <vector> 
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
#include <gtest/gtest.h>
//2010_08_25 by qzj. 

template <typename T> class book {
};

//#2010_08_25_18:08:28 add by qzj
//sin( x ) x 以 pi为单位。 , 弧度。 
using namespace std;
TEST(sin, math)
{
	//sin(pi)==0	
	EXPECT_FLOAT_EQ(sin(0.0),0);
	EXPECT_FLOAT_EQ(sin(M_PI/2), 1);
	EXPECT_FLOAT_EQ(sin(M_PI), 0);
	EXPECT_FLOAT_EQ(sin(M_PI*3/2), -1);
	EXPECT_FLOAT_EQ(sin(M_PI), 0);
}

int main(int argc, char * argv[])
{
	testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}

