#include <iomanip>
//������iomanip�����ñȽ϶�:
//Ҫ�Ƕ�cin,cout֮���һЩ���������ӣ�����setfill,setw,setbase,setprecision�ȵȡ�����I/O������ͷ
// ,����C����ĸ�ʽ�����һ��.������һЩ�����Ŀ��ƺ�����:
//dec �û���Ϊ10 �൱��"%d"
//hex �û���Ϊ16 �൱��"%X"
//oct �û���Ϊ8 �൱��"%o"
//setfill(c) ������ַ�Ϊc
//setprecision(n) ����ʾС������Ϊnλ
//setw(n) �����Ϊn���ַ�
//������Ʒ�����˼�Ǳ�֤�������Ϊn���磺
//cout<<setw(3)<<1<<setw(3)<<10<<setw(3)<<100; ������Ϊ
//1 10100 ��Ĭ�����Ҷ��룩��������ȴ���3ʱ(<<1000)��setw(3)�������á�
//setioflags(ios::fixed) �̶��ĸ�����ʾ
//setioflags(ios::scientific) ָ����ʾ
//setiosflags(ios::left) �����
//setiosflags(ios::right) �Ҷ���
//setiosflags(ios::skipws ����ǰ���հ�
//setiosflags(ios::uppercase) 16��������д���
//setiosflags(ios::lowercase) 16����Сд���
//setiosflags(ios::showpoint) ǿ����ʾС����
//setiosflags(ios::showpos) ǿ����ʾ����
//������
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int i;
    cout<<12345.0<<endl;//���"12345"
    cout<<setiosflags(ios::fixed)<<setprecision(3)<<1.2345<<endl;//���"1.235"
    cout<<setiosflags(ios::scientific)<<12345.0<<endl;//���"1.234500e+004 "
    cout<<setprecision(3)<<12345.0<<endl;//���"1.235e+004 "
    //cin >>i;
    return 0;
}