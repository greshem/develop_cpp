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


//���ڲ������д���࣬���̳�TestCase��
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
        ("response�ṹ��sizeof�ıȽ�", &myCppUnitTest::Test_equal_struct_respon));
    suiteOfTests->addTest(new CppUnit::TestCaller<myCppUnitTest>
            ("request�ṹ��sizeof�ıȽ�", &myCppUnitTest::Test_equal_struct_request));
    suiteOfTests->addTest(new CppUnit::TestCaller<myCppUnitTest>
            ("decl�ṹ��sizeof�ıȽ�", &myCppUnitTest::Test_equal_struct_decl));
    return suiteOfTests;
	}
};

//setUp()���ڳ�ʼ����Complex��ֵ
void myCppUnitTest::setUp()       
{
}
//�������ٶ��󣬼��ڴ�
void myCppUnitTest::tearDown()
{
}
//���Ժ���Test_equal_struct_respon()
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
	//��1��װ�䷽ʽ.
	// suite.addTest(new CppUnit::TestCaller<myCppUnitTest>( "�Ƚ�struct_response", &myCppUnitTest::Test_equal_struct_respon));
	// suite.addTest(new CppUnit::TestCaller<myCppUnitTest>( "�Ƚ�struct_request", &myCppUnitTest::Test_equal_struct_request));
	// suite.addTest(new CppUnit::TestCaller<myCppUnitTest>( "�Ƚ�struct_decl", &myCppUnitTest::Test_equal_struct_decl));
	// suite.run(&result);

	
	//========================================================================
	//�ڶ���װ�䷽ʽ.
	runner.addTest(myCppUnitTest::suite());
	//cpp unit  �ɹ��ķ���ֵ�� 1 , 0��ʾʧ��.
	return !(runner.run());

}

