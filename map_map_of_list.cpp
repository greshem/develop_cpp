#include <map>
#include <list>
#include <iostream>
#include <string>
using namespace std;

typedef struct
{
	unsigned short wLinkCount;//连接数量
	unsigned short wUserCount;//关联帐号数量
	unsigned long dwFirstLinkTime;//该节点第一次连接时间
	std::list <string > listName;//帐号信息
}tagInfoLinkData;
//################################################################################

typedef struct
{
	unsigned short wLinkCount; //连接数量
	unsigned short wUserCount; //关联帐号数量
	unsigned long dwFirstLinkTime;//该ip第一次连接时间
	std::list <std::string> listName;//帐号信息
	std::map< std::string, tagInfoLinkData > listInfoMap;
}tagIPLinkData;
//################################################################################
main()
{     
    int nouse;
	std::map< unsigned long, tagIPLinkData > mapIPLink;
    tagIPLinkData      ipdata;
    tagInfoLinkData    linkdata;
//################################################################################
//有其他的赋值的方式吗? 
                                                               
    linkdata.wLinkCount=100;
    linkdata.wUserCount=100;
    linkdata.dwFirstLinkTime=1000;
    linkdata.listName.push_front("qianzhognjie");
//################################################################################
    ipdata.wLinkCount=10;
    ipdata.wUserCount=100;
    ipdata.listName.push_front("qianlong");
    ipdata.listName.push_front("qianlong2");
    
    //map 的插入方式.  
    ipdata.listInfoMap.insert( make_pair("qianlong", linkdata) );
    ipdata.listInfoMap.insert( make_pair("qianlong2", linkdata) );
//###
     //最最上层的MAP  
     mapIPLink.insert(make_pair(1,ipdata));
     mapIPLink.insert(make_pair(2,ipdata));
     mapIPLink.insert(make_pair(3,ipdata));
     mapIPLink.insert(make_pair(4,ipdata));
//################################################################################
    //cout << ipdata.listInfoMap["qianlong2"].wLinkCount<<endl;
//################################################################################
   std::map< unsigned long, tagIPLinkData >::iterator map_it;
   for(map_it=mapIPLink.begin();map_it!=mapIPLink.end();map_it++)
   {
        cout <<(*map_it).second.wLinkCount<<endl;                                                                                                                                                                                      
   }
//################################################################################
// 通过ip 来找到账户号 
   map_it=mapIPLink.find(2);
   cout <<"#################"<<endl;
   cout <<*((*map_it).second.listName.begin())<<endl;
//################################################################################
//
//   cin >> nouse;

}
