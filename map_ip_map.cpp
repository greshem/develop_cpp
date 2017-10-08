#include <stdlib.h>
#include <string>
#include <list>
#include <map>
#include <iostream>
using namespace std;
//################################################################################


typedef struct
{
	unsigned short wLinkCount;//��������
	unsigned short wUserCount;//�����ʺ�����
	unsigned long dwFirstLinkTime;//�ýڵ��һ������ʱ��
#ifdef BUG
	std::list <char[32]> listName;//�ʺ���Ϣ
#else
	std::list <string> listName;//�ʺ���Ϣ
#endif
}tagInfoLinkData;
//################################################################################

typedef struct
{
	unsigned short wLinkCount; //��������
	unsigned short wUserCount; //�����ʺ�����
	unsigned long dwFirstLinkTime;//��ip��һ������ʱ��
#ifdef BUG
	std::list <char[32]> listName;//�ʺ���Ϣ
	std::map< char[32], tagInfoLinkData > listInfoMap;
#else

	std::list <string> listName;//�ʺ���Ϣ
	std::map< string , tagInfoLinkData > listInfoMap;
#endif
}tagIPLinkData;
//################################################################################

typedef struct
{
	unsigned long dwFirstLinkTime;//��һ������ʱ��
	unsigned short wFailCount;
}tagNameLinkData;
//################################################################################

int main()
{
    std::map< unsigned long, tagIPLinkData > mapIPLink;
}
