#include <stdlib.h>
#include <string>
#include <list>
#include <map>
#include <iostream>
using namespace std;
//################################################################################


typedef struct
{
	unsigned short wLinkCount;//连接数量
	unsigned short wUserCount;//关联帐号数量
	unsigned long dwFirstLinkTime;//该节点第一次连接时间
#ifdef BUG
	std::list <char[32]> listName;//帐号信息
#else
	std::list <string> listName;//帐号信息
#endif
}tagInfoLinkData;
//################################################################################

typedef struct
{
	unsigned short wLinkCount; //连接数量
	unsigned short wUserCount; //关联帐号数量
	unsigned long dwFirstLinkTime;//该ip第一次连接时间
#ifdef BUG
	std::list <char[32]> listName;//帐号信息
	std::map< char[32], tagInfoLinkData > listInfoMap;
#else

	std::list <string> listName;//帐号信息
	std::map< string , tagInfoLinkData > listInfoMap;
#endif
}tagIPLinkData;
//################################################################################

typedef struct
{
	unsigned long dwFirstLinkTime;//第一次连接时间
	unsigned short wFailCount;
}tagNameLinkData;
//################################################################################

int main()
{
    std::map< unsigned long, tagIPLinkData > mapIPLink;
}
