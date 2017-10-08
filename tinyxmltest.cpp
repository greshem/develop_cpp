#include <tinyxml.h>
#include <iostream>
#include <string>
#include <iostream>
#include <string>

//#include <tinyxml/Tinyxmluse.h>
using namespace std;



//TiXmlBase������TinyXMLģ�͵Ļ��ࡣ
//TiXmlAttribute����Ӧ��XML�е�Ԫ�ص����ԡ�
//TiXmlNode����Ӧ��DOM�ṹ�еĽڵ㡣
//TiXmlComment����Ӧ��XML�е�ע��
//TiXmlDeclaration����Ӧ��XML�е��������֣�<��versiong="1.0" ?>��
//TiXmlDocument����Ӧ��XML�������ĵ���
//TiXmlElement����Ӧ��XML��Ԫ�ء�
//TiXmlText����Ӧ��XML�����ֲ���
//TiXmlUnknown����Ӧ��XML��δ֪���֡�
//TiXmlHandler�����������XML��һЩ������ 




int write_xml(int pra1,int pra2)
{
	TiXmlDocument xmlDoc( "test.xml" ); // ����һ��XML�ļ�

	TiXmlDeclaration Declaration( "1.0","gb2312", "yes" ); // ����XML������

	xmlDoc.InsertEndChild( Declaration ); // д�������XMLͷ�ṹ    

	TiXmlNode * pNode = NULL; 
	TiXmlElement* pRootElm = NULL; 
	TiXmlElement* pChildeElm = NULL; 
	TiXmlElement* pItemElm = NULL; 
	TiXmlText* pText = NULL; // һ��ָ��Text��ָ��
	pText = new TiXmlText("good") ;

	pRootElm = new TiXmlElement( "todo" ); 

	pNode = xmlDoc.InsertEndChild(*pRootElm) ;
	pRootElm = pNode->ToElement() ;
	
	//�����һ���ڵ�
	pChildeElm = new TiXmlElement("add") ;
	pChildeElm->SetAttribute("num", 9) ;
	pChildeElm->SetAttribute("num1", 90) ;
	pChildeElm->SetAttribute("num2", 999) ;

	pNode = pRootElm->InsertEndChild(*pChildeElm) ;

	TiXmlElement* pChildeElm1 = NULL; 
	pChildeElm1 = pNode->ToElement() ;
	pChildeElm1->InsertEndChild(*pText) ;

	//���������ӽڵ�
	delete pChildeElm ;
	pChildeElm = NULL ;

	pChildeElm = new TiXmlElement("subchild1") ;
	pChildeElm->SetAttribute("addpra1", pra1) ;
	pChildeElm->SetAttribute("addpra2", pra2) ;
	pNode = pChildeElm1->InsertEndChild(*pChildeElm) ;//�����һ���ڵ�

	//�ڵ�һ��֮ǰ����ڶ��������ڵ�
	delete pChildeElm ;
	pChildeElm = NULL ;
	pChildeElm = new TiXmlElement("mult") ;
	pChildeElm->SetAttribute("num", 10) ;

	pNode = pRootElm->InsertBeforeChild (pChildeElm1, *pChildeElm) ;//�ڵ�һ��֮ǰ����

	TiXmlElement* pChildeElm2 = NULL; 
	pChildeElm2 = pNode->ToElement() ;
	pChildeElm2->InsertEndChild(*pText) ;

	//���������ڵ�
	delete pChildeElm ;
	pChildeElm = NULL ;

	pChildeElm = new TiXmlElement("subchild2") ;
	pChildeElm->SetAttribute("multpra1", pra1) ;
	pChildeElm->SetAttribute("multpra2", pra2) ;
	pNode = pChildeElm2->InsertEndChild(*pChildeElm) ;//�����һ���ڵ�


	xmlDoc.Print() ;

	xmlDoc.SaveFile(); // ��XML�ļ�д��Ӳ��

	return 0 ;
}

//������ӡ�����ӽڵ�����
int read_2ed_node()
{
	cout<<"��ʼread XML"<<endl ;
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
		while(pNode) //������ӡ�����ӽڵ�����
		{
			xmlSubElement = pNode->ToElement() ;
			cout<<xmlSubElement->Value()<<endl ;           //�ڵ�����
			cout<<xmlSubElement->Attribute("num")<<endl ;  //ָ������
			cout<<xmlSubElement->GetText()<<endl ;         //�ı�����
			pNode=pNode->NextSibling();
		}
	}

	cout<<"����read XML"<<endl ;
	return 0 ;
}

//��ӡ�������ӽڵ�����
int read_3th_node()
{
	TiXmlDocument* myDocument = new TiXmlDocument();

	myDocument->LoadFile("test.xml");

	TiXmlElement* rootElement = myDocument->RootElement();  //Class

	TiXmlElement* Elements = rootElement->FirstChildElement();   //�Ӽ�
	
	TiXmlElement* Element = Elements->FirstChildElement();   //�����Ӽ�


	while(Element) 
	{

		TiXmlAttribute* attributeOfStudent = Element->FirstAttribute();  //������ӡ�ڵ�����

		while (attributeOfStudent)
		{
			std::cout<<attributeOfStudent->Name()<<" : "<<attributeOfStudent->Value()<<std::endl;
			attributeOfStudent = attributeOfStudent->Next(); 
		}

		//TiXmlElement* phoneElement = studentElement->FirstChildElement(); //���student��phoneԪ��

		//std::cout<<"phone"<<" : "<<phoneElement->GetText()<<std::endl;

		//TiXmlElement* addressElement = phoneElement->NextSiblingElement(); 

		//std::cout<<"address"<<" : "<<phoneElement->GetText()<<std::endl;

		Element = Element->NextSiblingElement(); 
	}
	return 0;

}

//����ļ�����
bool get_xml_declare()   
{   
	// ����һ��TiXmlDocument��ָ��   
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

//��ȡadd�ڵ���ӽڵ�ֵ ��������ӽ��
int read_spe_node(string nodename)
{
	string nodevalue;
	TiXmlDocument* myDocument = new TiXmlDocument();

	myDocument->LoadFile("test.xml");

	TiXmlElement* rootElement = myDocument->RootElement();  //Class

	TiXmlElement* Element = rootElement->FirstChildElement();   //�Ӽ�

	while(Element) {
		nodevalue=Element->Value();
		if(nodevalue==nodename)
		{
			TiXmlAttribute* attributeOfStudent = Element->FirstAttribute();  //������ӡ�ڵ�����

			while (attributeOfStudent){

				std::cout<<attributeOfStudent->Name()<<" : "<<attributeOfStudent->Value()<<std::endl;
				attributeOfStudent = attributeOfStudent->Next(); 
			}
		}
		Element = Element->NextSiblingElement(); 
	}
	return 0;
}

//�ݹ����ָ���ڵ����Ľڵ�ָ��
bool GetNodePointerByName(TiXmlElement* pRootEle,string &strNodeName,TiXmlElement* &Node)
{
	// ������ڸ��ڵ��������˳�
	if (strNodeName==pRootEle->Value())
	{
		Node = pRootEle;
		return true;
	}
	TiXmlElement* pEle = pRootEle;  
	for (pEle = pRootEle->FirstChildElement(); pEle; pEle = pEle->NextSiblingElement())  
	{  
		//�ݹ鴦���ӽڵ㣬��ȡ�ڵ�ָ��
		if(GetNodePointerByName(pEle,strNodeName,Node))
			return true;
	}  
	return false;
}  


//��ȡָ���ڵ�ָ������
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

//ɾ��add�ڵ�
int remove_node(string nodename)
{
	string nodevalue;
	TiXmlDocument* myDocument = new TiXmlDocument();

	myDocument->LoadFile("test.xml");

	TiXmlElement* rootElement = myDocument->RootElement();  //Class

	TiXmlElement* Element = rootElement->FirstChildElement();   //�Ӽ�


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
		cout<<"���ҵ�:"<<value<<endl;
	}
	remove_node("add");
	int a;
	return 0;
}

