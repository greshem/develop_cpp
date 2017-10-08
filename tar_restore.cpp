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

//2010_08_27 by greshem. 
//1.tar �ļ��� �ļ������кܶ������������ ������10k���ļ��� ���� ������ ����С���ļ�����һ�¡� 
//2. ������� block ��һ��ֻ��һ��, �ǵ���Щ������˵��1����ʵ�Ǵ���ġ�  
//name[100] 
//#2010_10_09_09:58:46 add by greshem , ���tar����ͷ��У�顣 
//#2010_10_09_10:08:37 add by greshem, �� tar_dump_v2.cpp �仯������ �� fseek_print �ɺ���ȡ����

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
        int i, sum_u, sum_s, sum;


	MFile<char> tar;
	if(tar.Open(filename.c_str()) != 1)
	{
		die<char>("open file error\n");
	}

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
		//����ͷ��
		memset((char *)&tmp, '\0', sizeof(tmp));
		ret=tar.Read((char *) &tmp, sizeof(tmp)) ;


       /* Do checksum on headers.
		* POSIX says that checksum is done on unsigned bytes, but
 		* Sun and HP-UX gets it wrong... more details in
 		* GNU tar source. */

     

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
		//��Ч��ͷ���� ���ͷ��֮�������������ļ��� 
		if(tmp.name[0]!='\0')
		{
			//########################################################################
			//����У��
		   	sum_s = sum_u = ' ' * sizeof(tmp.chksum);
			for (i = 0; i < 148 ; i++) {
					sum_u += ((unsigned char*)&tmp)[i];
					sum_s += ((signed char*)&tmp)[i];
			}
			for (i = 156; i < 512 ; i++) {
					sum_u += ((unsigned char*)&tmp)[i];
					sum_s += ((signed char*)&tmp)[i];
			}
			/* This field does not need special treatment (getOctal) */
			sum = strtoul(tmp.chksum,NULL,  8);
		
			if (sum_u != sum && sum_s != sum) 
			{
					printf("invalid tar header checksum\n");
			}
			//########################################################################

			cout<<"name "<<tmp.name<<"\t";
			cout<<"size "<<size<<endl;
		//	cout<<"./fseek_and_print_v7 "<< filename<< "\t"<< tar.GetCurOffset()<<"\t"<< size<<"\t"<<" > "<<basename(tmp.name)<<endl;

		}
		//########################################################################
		//��ʼ�����ļ�����
		//������ ��д���ļ�ϵͳ�ˡ� 
		int skip=0;
		if(skip)
		{
			tar.Seek(size, SEEK_CUR);
			if(size%512!=0)
			{
				pad=512-size%512;
			}
			//cout<<"Pad"<<pad<<endl;
			tar.Seek(pad, SEEK_CUR);	
		}
		else
		{
			char buffer[512];
			char output[512];
			memset(output, '\0', sizeof(output));
			if(tmp.name[0]=='/')
			{
				strncpy(output, "./",2);
				strcat(output, tmp.name);
			}
			else
			{
				strncpy(output, tmp.name, sizeof(output));
			}
			int count=0;
			int ret=0;
			MFile<char> output_file;
			output_file.Create(output);
			cout<<"#######"<<MString<char>(output).dirname()<<endl;
			MFile<char>::CreateDirectoryTree(MString<char>(output).dirname());
			while(   count < size ) 
			{
				ret=tar.Read(buffer, sizeof(buffer))  ;	
				count+=ret;
				if(count > size)
				{
					output_file.Write(buffer, ret-(count -size));
				}
				else
				{
					output_file.Write(buffer, ret);
				}
			}	
		}
		//########################################################################
	}
	tar.Close();
	return 1;
}
