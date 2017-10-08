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
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// 某些 CString 构造函数将为显式的

	#ifndef VC_EXTRALEAN
	#define VC_EXTRALEAN		// 从 Windows 头中排除极少使用的资料
	#endif

	#include <afx.h>
	#include <afxwin.h>         // MFC 核心组件和标准组件
	#include <afxext.h>         // MFC 扩展
	#include <afxdtctl.h>		// MFC 对 Internet Explorer 4 公共控件的支持
	#ifndef _AFX_NO_AFXCMN_SUPPORT
	#include <afxcmn.h>			// MFC 对 Windows 公共控件的支持
	#endif // _AFX_NO_AFXCMN_SUPPORT

BOOL   TransDirectory(LPCTSTR   DirName, vector<string> &out)
{
	CFileFind   tempFind;   //file://声明一个CFileFind类变量，以用来搜索
	char   tempFileFind[1024];   //file://用于定义搜索格式
	sprintf(tempFileFind, "%s\\*.*",DirName);
	//file://匹配格式为*.*,即该目录下的所有文件  

	BOOL   IsFinded=(BOOL)tempFind.FindFile(tempFileFind);
	if(IsFinded)
	{
		printf("找到了\n");
	}
	else
	{
		printf("%s\n", tempFileFind);
		printf("没有找到\n");
	}
	//file://查找第一个文件
	while(IsFinded)
	{
		IsFinded=(BOOL)tempFind.FindNextFile();   //file://递归搜索其他的文件  
		if(!tempFind.IsDots())  // file://如果不是 ". "目录
		{
			char   foundFileName[1024];
			strcpy(foundFileName,tempFind.GetFileName().GetBuffer(1024));
			if(tempFind.IsDirectory())  // file://如果是目录，则递归地调用
			{   //file://DeleteDirectory
				char   tempDir[200];
				sprintf(tempDir, "%s\\%s",DirName,foundFileName);
				printf("DIR: %s\n", tempDir);
//				TransDirectory(tempDir);
			}
			else
			{   //file://如果是文件则直接删除之
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
//glob_t  的主要的结构是
//  { 	__size_t gl_pathc;
//		char **gl_pathv;
//		.
//		.
//		.
//		.
//	}

