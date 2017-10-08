#include <gtest/gtest.h>
#include <iostream>
#include <queue>
using namespace std;

template<typename T>
class MyQueue
{
public:
    MyQueue()
	{
	}
	void InitQueue()
	{
	    for (int i = 0; i < 10; i++)
	    {
           m_queue.push(i);
		}
	}
    int PrintQueue()
	{
	   int index = 0;
	   cout << "/*The following are the elements in the queue!*/" << endl;
	   while (!m_queue.empty())
	   {
	       ++index;
	       T a = m_queue.front();
		   cout << a << endl;
		   m_queue.pop();
	   }
	   cout << "/*All the elements in the queue have been printed!*/" << endl;

	   return index;
	}

private:
	queue<T> m_queue; 
};

class QueueTest: public ::testing::Test
{
public:
  virtual void SetUp()
  {
      m_TestQueue.InitQueue();
	  cout << "QueueTest SetUp() has been invoked\n" << endl;
  }
  virtual void TearDown()
  {
      cout << "QueueTest TearDown() has been invoked\n" << endl;
  }
public:
  MyQueue<int> m_TestQueue;
};

TEST_F(QueueTest, TestInit)
{
    int index = 0;
    index = m_TestQueue.PrintQueue();
    EXPECT_EQ(index, 10);
}

TEST_F(QueueTest, TestInitSec)
{
    int index = 0;
	index = m_TestQueue.PrintQueue();
	EXPECT_EQ(index, 11);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

