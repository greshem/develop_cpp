#include <map>
#include <list>
#include <iostream>
#include <string>
using namespace std;

typedef struct
{
	unsigned short wLinkCount;//��������
	unsigned short wUserCount;//�����ʺ�����
	unsigned long dwFirstLinkTime;//�ýڵ��һ������ʱ��
	std::list <string > listName;//�ʺ���Ϣ
}tagInfoLinkData;
//################################################################################

typedef struct
{
	unsigned short wLinkCount; //��������
	unsigned short wUserCount; //�����ʺ�����
	unsigned long dwFirstLinkTime;//��ip��һ������ʱ��
	std::list <std::string> listName;//�ʺ���Ϣ
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
//�������ĸ�ֵ�ķ�ʽ��? 
                                                               
    linkdata.wLinkCount=100;
    linkdata.wUserCount=100;
    linkdata.dwFirstLinkTime=1000;
    linkdata.listName.push_front("qianzhognjie");
//################################################################################
    ipdata.wLinkCount=10;
    ipdata.wUserCount=100;
    ipdata.listName.push_front("qianlong");
    ipdata.listName.push_front("qianlong2");
    
    //map �Ĳ��뷽ʽ.  
    ipdata.listInfoMap.insert( make_pair("qianlong", linkdata) );
    ipdata.listInfoMap.insert( make_pair("qianlong2", linkdata) );
//###
     //�����ϲ��MAP  
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
// ͨ��ip ���ҵ��˻��� 
   map_it=mapIPLink.find(2);
   cout <<"#################"<<endl;
   cout <<*((*map_it).second.listName.begin())<<endl;
//################################################################################
//
//   cin >> nouse;

}
