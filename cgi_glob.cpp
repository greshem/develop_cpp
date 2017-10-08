#include <iostream> 
#include <map>
#ifdef WINDOWSCODE
//#error "not support widnows now "
#else
#include <glob.h>
#endif



#include <gtest/gtest.h>
#include <fstream>
//#include <dirent.h>
#include <string> 
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include <Baselib.hpp>
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
//2010_07_13 by qzj. 
//#2010_08_20_15:36:17 add by qzj
using namespace std;
//int  glob_stl(string in,  vector<string> &out);

#ifdef WINDOWSCODE

#include <iostream>
#include <tchar.h>
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// ĳЩ CString ���캯����Ϊ��ʽ��

	#ifndef VC_EXTRALEAN
	#define VC_EXTRALEAN		// �� Windows ͷ���ų�����ʹ�õ�����
	#endif

	#include <afx.h>
	#include <afxwin.h>         // MFC ��������ͱ�׼���
	#include <afxext.h>         // MFC ��չ
	#include <afxdtctl.h>		// MFC �� Internet Explorer 4 �����ؼ���֧��
	#ifndef _AFX_NO_AFXCMN_SUPPORT
	#include <afxcmn.h>			// MFC �� Windows �����ؼ���֧��
	#endif // _AFX_NO_AFXCMN_SUPPORT

BOOL   TransDirectory(LPCTSTR   DirName, vector<string> &out)
{
	CFileFind   tempFind;   //file://����һ��CFileFind�����������������
	char   tempFileFind[1024];   //file://���ڶ���������ʽ
	sprintf(tempFileFind, "%s\\*.*",DirName);
	//file://ƥ���ʽΪ*.*,����Ŀ¼�µ������ļ�  

	BOOL   IsFinded=(BOOL)tempFind.FindFile(tempFileFind);
	if(IsFinded)
	{
		printf("�ҵ���\n");
	}
	else
	{
		printf("%s\n", tempFileFind);
		printf("û���ҵ�\n");
	}
	//file://���ҵ�һ���ļ�
	while(IsFinded)
	{
		IsFinded=(BOOL)tempFind.FindNextFile();   //file://�ݹ������������ļ�  
		if(!tempFind.IsDots())  // file://������� ". "Ŀ¼
		{
			char   foundFileName[1024];
			strcpy(foundFileName,tempFind.GetFileName().GetBuffer(1024));
			if(tempFind.IsDirectory())  // file://�����Ŀ¼����ݹ�ص���
			{   //file://DeleteDirectory
				char   tempDir[200];
				sprintf(tempDir, "%s\\%s",DirName,foundFileName);
				printf("DIR: %s\n", tempDir);
//				TransDirectory(tempDir);
			}
			else
			{   //file://������ļ���ֱ��ɾ��֮
				char   tempFileName[1024];
				sprintf(tempFileName, "%s\\%s ",DirName,foundFileName);
				//printf("%s\n", tempFileName);
				out.push_back(string(tempFileName));
				//DeleteFile(tempFileName);
			}
		}
	}
	tempFind.Close();

	return   TRUE;
} 

#else
int  glob_stl(string in,  vector<string> &out)
{
	
	glob_t gl;
    int ret;
	ret=glob("*", 0, NULL, &gl);
	int count=gl.gl_pathc;
	for(int i=0;i<count;i++)
	{
		out.push_back( gl.gl_pathv[i] );
	} 
	globfree(&gl);
	return  count;

}
#endif

int main(int argc, char *argv[])
{
	cout<<"Content-type:text/html";
  	vector<string> vecStr; 
#ifdef WINDOWSCODE
	TransDirectory("c:\\", vecStr);
#else
	glob_stl("*", vecStr);
#endif
	copy(vecStr.begin(), vecStr.end(), ostream_iterator<string>(cout, "\n"));

	return 0;
}

//###############################################################################
//glob_t  ����Ҫ�Ľṹ��
//  { 	__size_t gl_pathc;
//		char **gl_pathv;
//		.
//		.
//		.
//		.
//	}

