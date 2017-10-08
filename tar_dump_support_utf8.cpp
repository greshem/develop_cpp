#include <algorithm>
#include <fstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <vector> 
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>
//#include <gtest/gtest.h>

#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif

#include <stringprep.h>
#include <locale.h>
//2010_08_27 by greshem. 
//1.tar �ļ��� �ļ������кܶ������������ ������10k���ļ��� ���� ������ ����С���ļ�����һ�¡� 
//2. ������� block ��һ��ֻ��һ��, �ǵ���Щ������˵��1����ʵ�Ǵ���ġ�  
//name[100] 
//#2010_09_01_18:54:19 add by greshem , �������Ҫ�� 
//setlocale (LC_ALL, ""), �����ʧ�ܵġ� 

template <typename T> class book {
};
typedef struct tar_header
{
char name[100];
char mode[8];
char uid[8];
char gid[8];
char size[12];
char mtime[12];
char chksum[8];
char typeflag;
char linkname[100];
char magic[6];
char version[2];
char uname[32];
char gname[32];
char devmajor[8];
char devminor[8];
char prefix[155];
char padding[12];
} HEADER;

using namespace std;
int dump_one_tar(string filename);

int main(int argc, char *argv[])
{

	if(argc < 2)
	{
		die<char>("Usage: %s file.tar ", argv[0]);
	}
	for(int i=1; i< argc; i++)
	{
		string filename(argv[i]);
		dump_one_tar( filename);
		//cout<<filename<<endl;

	}

	
	return 0;
}
int dump_one_tar(string filename)
{
	HEADER tmp;
	assert(sizeof(tmp)==512);
	char buf[BUFSIZ];

	//ofstream output("name.list");
	MFile<char> tar;
	if(tar.Open(filename.c_str()) != 1)
	{
		die<char>("open file error\n");
	}

	setlocale (LC_ALL, "");
	long long Length=filesize<char>(filename);
	assert(Length%512==0);
	while(	  tar.GetCurOffset() != Length )
	{
		//cout<<"###################"<<endl;
		// if((Length - tar.GetCurOffset()) ==512)
		// {
		// 	die<char>("at the end of tar file \n");
		// 	break;
		// }
		//ע����Ҫ�������ã� ÿ��ѭ���ı����õ�ʱ���ʼ���� 
		int ret=0;
		int pad=0;
		char *p;
		ret=tar.Read((char *) &tmp, sizeof(tmp)) ;
		//cout<<"����"<<ret<<"�ֽ�"<<endl;
		if(ret ==0 )
		{
			break;
		}
		if(ret != 512)
		{

			cout<<"�� "<<tar.GetCurOffset()<<"���� ��������ݲ�Ϊ 512"<<"Ϊ"<<ret<<endl; 
			die<char>(" ############");
		}
		//cout<<"ftell "<<tar.GetCurOffset()<<endl;
		//assert(tar.GetCurOffset()%512==0);
		long long size=strtoull(tmp.size, NULL, 8);
		if(tmp.name[0]!='\0')
		{
	//		cout<<"name "<<tmp.name<<endl;
	//		cout<<"size "<<size<<endl;
		//	cout<<"./fseek_and_print_v7 "<< filename<< "\t"<< tar.GetCurOffset()<<"\t"<< size<<"\t"<<" > "<<basename(tmp.name)<<endl;
			//cout<<"./fseek_and_print_v7 "<< filename<< "\t"<< tar.GetCurOffset()<<"\t"<< size<<"\t"<<" > "<<tmp.name<<endl;
			//if(size==0)
			{
				p=stringprep_utf8_to_locale(tmp.name);
				if(p)
				//MFile<char>::CreateDirectoryTree();
				{
					//cout<<<<endl;
					printf("##### %s\n", p);
					free(p);
				}
				else
				{
					printf("Error,cann't changge to utf8\n");
				}
			}
		}
		tar.Seek(size, SEEK_CUR);
		if(size%512!=0)
		{
			pad=512-size%512;
		}
		//cout<<"Pad"<<pad<<endl;
		tar.Seek(pad, SEEK_CUR);	
	}
	tar.Close();
	return 1;
}
