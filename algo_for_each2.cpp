#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <deque>
#include <iostream>
/*对STL的容器中，遍历是一个非常经常采用的动作，为此STL也提供一个算法，for_each

遍历一个容器，我们第一个想到的是
for (int i = 0;i < a.size();++i)
的循环来实现。

这样做有几个弊端，比如我现在很多地方用vector作为传引用参数进行传递，为了减少对象构造和析构的代价，我一般采用指针来传递，那么我就要在程序很多地方 写上类似下面的代码
for (int i=0;i < a.size();++i)
     delete a[i];
虽然代码很多都一样，可是到处泛滥着这种循环语句，让人阅读程序容易和其它释放指针行为产生混淆

而改用for_each实现
如下面sample*/

using namespace std;
template<class T>
class deletePtr
{
    public:
    int operator()(T *t)
    {
        printf("%d\n",*t);
        delete t;
		return 1;
    }
};
deletePtr <int> deleteIntPtr;
int main()
{   int i;
    deque<int* > xxx;
    for(i =  0; i <=  100; i++)
    {
          xxx.push_back(new int(i));
    }
    sort(xxx.begin(), xxx.end());
    for_each(xxx.begin(),xxx.end(),deleteIntPtr);
    
    //cin >> i;
}
