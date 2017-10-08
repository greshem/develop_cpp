#include <tinyxml.h>
#include <iostream>
#include <string>
#include <iostream>
#include <string>

//#include <tinyxml/Tinyxmluse.h>
using namespace std;



//TiXmlBase：整个TinyXML模型的基类。
//TiXmlAttribute：对应于XML中的元素的属性。
//TiXmlNode：对应于DOM结构中的节点。
//TiXmlComment：对应于XML中的注释
//TiXmlDeclaration：对应于XML中的申明部分，<？versiong="1.0" ?>。
//TiXmlDocument：对应于XML的整个文档。
//TiXmlElement：对应于XML的元素。
//TiXmlText：对应于XML的文字部分
//TiXmlUnknown：对应于XML的未知部分。
//TiXmlHandler：定义了针对XML的一些操作。 




int write_xml(int pra1,int pra2)
{
	TiXmlDocument xmlDoc( "test.xml" ); // 建立一个XML文件

	TiXmlDeclaration Declaration( "1.0","gb2312", "yes" ); // 声明XML的属性

	xmlDoc.InsertEndChild( Declaration ); // 写入基本的XML头结构    

	TiXmlNode * pNode = NULL; 
	TiXmlElement* pRootElm = NULL; 
	TiXmlElement* pChildeElm = NULL; 
	TiXmlElement* pItemElm = NULL; 
	TiXmlText* pText = NULL; // 一个指向Text的指针
	pText = new TiXmlText("good") ;

	pRootElm = new TiXmlElement( "todo" ); 

	pNode = xmlDoc.InsertEndChild(*pRootElm) ;
	pRootElm = pNode->ToElement() ;
	
	//插入第一个节点
	pChildeElm = new TiXmlElement("add") ;
	pChildeElm->SetAttribute("num", 9) ;
	pChildeElm->SetAttribute("num1", 90) ;
	pChildeElm->SetAttribute("num2", 999) ;

	pNode = pRootElm->InsertEndChild(*pChildeElm) ;

	TiXmlElement* pChildeElm1 = NULL; 
	pChildeElm1 = pNode->ToElement() ;
	pChildeElm1->InsertEndChild(*pText) ;

	//插入三级子节点
	delete pChildeElm ;
	pChildeElm = NULL ;

	pChildeElm = new TiXmlElement("subchild1") ;
	pChildeElm->SetAttribute("addpra1", pra1) ;
	pChildeElm->SetAttribute("addpra2", pra2) ;
	pNode = pChildeElm1->InsertEndChild(*pChildeElm) ;//插入第一个节点

	//在第一个之前插入第二个二级节点
	delete pChildeElm ;
	pChildeElm = NULL ;
	pChildeElm = new TiXmlElement("mult") ;
	pChildeElm->SetAttribute("num", 10) ;

	pNode = pRootElm->InsertBeforeChild (pChildeElm1, *pChildeElm) ;//在第一个之前插入

	TiXmlElement* pChildeElm2 = NULL; 
	pChildeElm2 = pNode->ToElement() ;
	pChildeElm2->InsertEndChild(*pText) ;

	//插入三级节点
	delete pChildeElm ;
	pChildeElm = NULL ;

	pChildeElm = new TiXmlElement("subchild2") ;
	pChildeElm->SetAttribute("multpra1", pra1) ;
	pChildeElm->SetAttribute("multpra2", pra2) ;
	pNode = pChildeElm2->InsertEndChild(*pChildeElm) ;//插入第一个节点


	xmlDoc.Print() ;

	xmlDoc.SaveFile(); // 把XML文件写入硬盘

	return 0 ;
}

//遍历打印二级子节点内容
int read_2ed_node()
{
	cout<<"开始read XML"<<endl ;
	TiXmlDocument xmlDoc( "test.xml" );
	xmlDoc.LoadFile() ;

	TiXmlElement* xmlRootElement = 0 ;
	TiXmlElement* xmlSubElement = 0 ;
	TiXmlNode * pNode = NULL; 

	pNode = xmlDoc.FirstChild("todo") ;
	xmlRootElement = pNode->ToElement() ;
    if(xmlRootElement)
	{
		pNode = xmlRootElement->FirstChild() ;
		//pNode = xmlRootElement->FirstChild("child1") ;
		while(pNode) //遍历打印二级子节点内容
		{
			xmlSubElement = pNode->ToElement() ;
			cout<<xmlSubElement->Value()<<endl ;           //节点名字
			cout<<xmlSubElement->Attribute("num")<<endl ;  //指定属性
			cout<<xmlSubElement->GetText()<<endl ;         //文本属性
			pNode=pNode->NextSibling();
		}
	}

	cout<<"结束read XML"<<endl ;
	return 0 ;
}

//打印第三级子节点属性
int read_3th_node()
{
	TiXmlDocument* myDocument = new TiXmlDocument();

	myDocument->LoadFile("test.xml");

	TiXmlElement* rootElement = myDocument->RootElement();  //Class

	TiXmlElement* Elements = rootElement->FirstChildElement();   //子键
	
	TiXmlElement* Element = Elements->FirstChildElement();   //三级子键


	while(Element) 
	{

		TiXmlAttribute* attributeOfStudent = Element->FirstAttribute();  //遍历打印节点属性

		while (attributeOfStudent)
		{
			std::cout<<attributeOfStudent->Name()<<" : "<<attributeOfStudent->Value()<<std::endl;
			attributeOfStudent = attributeOfStudent->Next(); 
		}

		//TiXmlElement* phoneElement = studentElement->FirstChildElement(); //获得student的phone元素

		//std::cout<<"phone"<<" : "<<phoneElement->GetText()<<std::endl;

		//TiXmlElement* addressElement = phoneElement->NextSiblingElement(); 

		//std::cout<<"address"<<" : "<<phoneElement->GetText()<<std::endl;

		Element = Element->NextSiblingElement(); 
	}
	return 0;

}

//获得文件声明
bool get_xml_declare()   
{   
	// 定义一个TiXmlDocument类指针   
	TiXmlDocument *pDoc = new TiXmlDocument();   
	if (NULL==pDoc)   
	{   
		return false;   
	}   
	pDoc->LoadFile("test.xml");   
	TiXmlNode* pXmlFirst = pDoc->FirstChild();      
	if (NULL != pXmlFirst)     
	{     
		TiXmlDeclaration* pXmlDec = pXmlFirst->ToDeclaration();     
		if (NULL != pXmlDec)     
		{     
			string strVersion = pXmlDec->Version();   
			string strStandalone = pXmlDec->Standalone();   
			string strEncoding = pXmlDec->Encoding();   
			std::cout<<strVersion<<" : "<<strStandalone<<" : "<<strEncoding<<std::endl;
		}   
	}   
	return true;   
}  

//读取add节点的子节点值 并返回相加结果
int read_spe_node(string nodename)
{
	string nodevalue;
	TiXmlDocument* myDocument = new TiXmlDocument();

	myDocument->LoadFile("test.xml");

	TiXmlElement* rootElement = myDocument->RootElement();  //Class

	TiXmlElement* Element = rootElement->FirstChildElement();   //子键

	while(Element) {
		nodevalue=Element->Value();
		if(nodevalue==nodename)
		{
			TiXmlAttribute* attributeOfStudent = Element->FirstAttribute();  //遍历打印节点属性

			while (attributeOfStudent){

				std::cout<<attributeOfStudent->Name()<<" : "<<attributeOfStudent->Value()<<std::endl;
				attributeOfStudent = attributeOfStudent->Next(); 
			}
		}
		Element = Element->NextSiblingElement(); 
	}
	return 0;
}

//递归查找指定节点名的节点指针
bool GetNodePointerByName(TiXmlElement* pRootEle,string &strNodeName,TiXmlElement* &Node)
{
	// 假如等于根节点名，就退出
	if (strNodeName==pRootEle->Value())
	{
		Node = pRootEle;
		return true;
	}
	TiXmlElement* pEle = pRootEle;  
	for (pEle = pRootEle->FirstChildElement(); pEle; pEle = pEle->NextSiblingElement())  
	{  
		//递归处理子节点，获取节点指针
		if(GetNodePointerByName(pEle,strNodeName,Node))
			return true;
	}  
	return false;
}  


//读取指定节点指定属性
bool read_spe_node_attri_value(string nodename,string attri,string &value)
{
	string nodevalue;
	TiXmlDocument* myDocument = new TiXmlDocument();

	myDocument->LoadFile("test.xml");

	TiXmlElement* rootElement = myDocument->RootElement();  //Class
	TiXmlElement* findElement=NULL;
	if(GetNodePointerByName(rootElement,nodename,findElement))
	{
		cout<<nodename<<":"<<attri<<":"<<findElement->Attribute(attri.c_str())<<endl;
        value=findElement->Attribute(attri.c_str());
	}
	return true;
}

//删除add节点
int remove_node(string nodename)
{
	string nodevalue;
	TiXmlDocument* myDocument = new TiXmlDocument();

	myDocument->LoadFile("test.xml");

	TiXmlElement* rootElement = myDocument->RootElement();  //Class

	TiXmlElement* Element = rootElement->FirstChildElement();   //子键


	while(Element) {
		nodevalue=Element->Value();
		if(nodevalue==nodename)
		{
			TiXmlNode *pParNode =  Element->Parent();  
			if (NULL==pParNode)   
			{   
				return 0;   
			}		
			TiXmlElement* pParentEle = pParNode->ToElement();   
			if (NULL!=pParentEle)   
			{   
				if(pParentEle->RemoveChild(Element))   
				{
					myDocument->SaveFile("test.xml");   
					return 0;
				}
				else  
					return 1;   
			}
		}
		Element = Element->NextSiblingElement(); 
	}
	return 0;
}

int main()
{
	write_xml(6,7);
	get_xml_declare() ;
	read_2ed_node();
	read_3th_node();
    read_spe_node("add");
    string value;
	bool ff = read_spe_node_attri_value("add","num2",value);
	if(ff)
	{
		cout<<"查找到:"<<value<<endl;
	}
	remove_node("add");
	int a;
	return 0;
}

