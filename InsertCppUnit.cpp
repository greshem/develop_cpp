#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <locale.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <assert.h>
#include <stringprep.h>
#include <gtest/gtest.h>

#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>


//用于测试类而写的类，它继承TestCase类
class myCppUnitTest:public CppUnit::TestCase
{
public:
	void setUp();
	void tearDown();
	void Test_equal_struct_respon();
	void Test_equal_struct_request();
	void Test_equal_struct_decl();
	void Test_sizeof_double();
	
	static CppUnit::Test* suite()
	{
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("myCppUnitTest");
    suiteOfTests->addTest(new CppUnit::TestCaller<myCppUnitTest>
        ("response结构体sizeof的比较", &myCppUnitTest::Test_equal_struct_respon));
    suiteOfTests->addTest(new CppUnit::TestCaller<myCppUnitTest>
            ("request结构体sizeof的比较", &myCppUnitTest::Test_equal_struct_request));
    suiteOfTests->addTest(new CppUnit::TestCaller<myCppUnitTest>
            ("decl结构体sizeof的比较", &myCppUnitTest::Test_equal_struct_decl));
    return suiteOfTests;
	}
};

//setUp()用于初始化类Complex的值
void myCppUnitTest::setUp()       
{
}
//用于销毁对象，及内存
void myCppUnitTest::tearDown()
{
}
//测试函数Test_equal_struct_respon()
void myCppUnitTest::Test_equal_struct_respon()
{
	CPPUNIT_ASSERT(sizeof(long long ) == 4 + 4  );
}
//------------------------------------------------------------------------
void myCppUnitTest::Test_sizeof_double()
{
	CPPUNIT_ASSERT(sizeof(double)== 8);
}

void myCppUnitTest::Test_equal_struct_request()
{
	CPPUNIT_ASSERT(sizeof(char)== 1);
}
//------------------------------------------------------------------------
void myCppUnitTest::Test_equal_struct_decl()
{
	CPPUNIT_ASSERT(sizeof(int)== 4);
}
//------------------------------------------------------------------------
int main()
{
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestSuite suite;

	CppUnit::TestResult result;

	//========================================================================
	//第1种装配方式.
	// suite.addTest(new CppUnit::TestCaller<myCppUnitTest>( "比较struct_response", &myCppUnitTest::Test_equal_struct_respon));
	// suite.addTest(new CppUnit::TestCaller<myCppUnitTest>( "比较struct_request", &myCppUnitTest::Test_equal_struct_request));
	// suite.addTest(new CppUnit::TestCaller<myCppUnitTest>( "比较struct_decl", &myCppUnitTest::Test_equal_struct_decl));
	// suite.run(&result);

	
	//========================================================================
	//第二种装配方式.
	runner.addTest(myCppUnitTest::suite());
	//cpp unit  成功的返回值是 1 , 0表示失败.
	return !(runner.run());

}

