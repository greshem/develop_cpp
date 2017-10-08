#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

//待测试的类
class Complex
{
	int x, y;
public:
	Complex(int a,int b):x(a),y(b){}
	int add()
		{
			return x+y;
		}
	int sub()
		{
			return x-y;
		}
};

//用于测试类而写的类，它继承TestCase类
class ComplexNumberTest:public CppUnit::TestCase
{
private:
	Complex *object;
public:
	void setUp();
	void tearDown();
	void testAdd();
	void testSub();
	
	static CppUnit::Test* suite()
	{
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("ComplexNumberTest");
    suiteOfTests->addTest(new CppUnit::TestCaller<ComplexNumberTest>
        ("相加", &ComplexNumberTest::testAdd));
    suiteOfTests->addTest(new CppUnit::TestCaller<ComplexNumberTest>
        ("相减", &ComplexNumberTest::testSub));
    return suiteOfTests;
	}
};

//setUp()用于初始化类Complex的值
void ComplexNumberTest::setUp()       
{
	object = new Complex(10, 1);
}
//用于销毁对象，及内存
void ComplexNumberTest::tearDown()
{
	delete object;
	object = NULL;
}
//测试函数testAdd()
void ComplexNumberTest::testAdd()
{
	CPPUNIT_ASSERT(object->add() == 11);
}
//测试函数testSub()
void ComplexNumberTest::testSub()
{
	CPPUNIT_ASSERT(object->sub() == 9);
}

//------------------------------------------------------------------------
//自动运行测试代码

//------------------------------------------------------------------------
//得到测试结果
/*static ComplexNumberTest::CppUnit::Test* suite()
{
	CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("ComplexNumberTest");
	suiteOfTests->addTest(new CppUnit::TestCaller<ComplexNumberTest>
		("相加", &ComplexNumberTest::testAdd));
	suiteOfTests->addTest(new CppUnit::TestCaller<ComplexNumberTest>
		("相减", &ComplexNumberTest::testSub));
	return suiteOfTests;
}*/


int main()
{
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestSuite suite;

	CppUnit::TestResult result;

	suite.addTest(new CppUnit::TestCaller<ComplexNumberTest>( "相加", &ComplexNumberTest::testAdd));
	suite.addTest(new CppUnit::TestCaller<ComplexNumberTest>( "相减", &ComplexNumberTest::testSub));
	suite.run(&result);

	runner.addTest(ComplexNumberTest::suite());
	runner.run();
	return 0;

}

