#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

//�����Ե���
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

//���ڲ������д���࣬���̳�TestCase��
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
        ("���", &ComplexNumberTest::testAdd));
    suiteOfTests->addTest(new CppUnit::TestCaller<ComplexNumberTest>
        ("���", &ComplexNumberTest::testSub));
    return suiteOfTests;
	}
};

//setUp()���ڳ�ʼ����Complex��ֵ
void ComplexNumberTest::setUp()       
{
	object = new Complex(10, 1);
}
//�������ٶ��󣬼��ڴ�
void ComplexNumberTest::tearDown()
{
	delete object;
	object = NULL;
}
//���Ժ���testAdd()
void ComplexNumberTest::testAdd()
{
	CPPUNIT_ASSERT(object->add() == 11);
}
//���Ժ���testSub()
void ComplexNumberTest::testSub()
{
	CPPUNIT_ASSERT(object->sub() == 9);
}

//------------------------------------------------------------------------
//�Զ����в��Դ���

//------------------------------------------------------------------------
//�õ����Խ��
/*static ComplexNumberTest::CppUnit::Test* suite()
{
	CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("ComplexNumberTest");
	suiteOfTests->addTest(new CppUnit::TestCaller<ComplexNumberTest>
		("���", &ComplexNumberTest::testAdd));
	suiteOfTests->addTest(new CppUnit::TestCaller<ComplexNumberTest>
		("���", &ComplexNumberTest::testSub));
	return suiteOfTests;
}*/


int main()
{
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestSuite suite;

	CppUnit::TestResult result;

	suite.addTest(new CppUnit::TestCaller<ComplexNumberTest>( "���", &ComplexNumberTest::testAdd));
	suite.addTest(new CppUnit::TestCaller<ComplexNumberTest>( "���", &ComplexNumberTest::testSub));
	suite.run(&result);

	runner.addTest(ComplexNumberTest::suite());
	runner.run();
	return 0;

}

