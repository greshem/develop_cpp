#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <deque>
#include <iostream>
/*��STL�������У�������һ���ǳ��������õĶ�����Ϊ��STLҲ�ṩһ���㷨��for_each

����һ�����������ǵ�һ���뵽����
for (int i = 0;i < a.size();++i)
��ѭ����ʵ�֡�

�������м����׶ˣ����������ںܶ�ط���vector��Ϊ�����ò������д��ݣ�Ϊ�˼��ٶ�����������Ĵ��ۣ���һ�����ָ�������ݣ���ô�Ҿ�Ҫ�ڳ���ܶ�ط� д����������Ĵ���
for (int i=0;i < a.size();++i)
     delete a[i];
��Ȼ����ܶ඼һ�������ǵ�������������ѭ����䣬�����Ķ��������׺������ͷ�ָ����Ϊ��������

������for_eachʵ��
������sample*/

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
