//########################################################################
//#include <QzjUnit.hpp>
//#include <MLmyUnit.hpp>
//#include <Baselib.hpp>
#include <gtest/gtest.h>
#include <fstream>
#include <string> 
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
using namespace std; 

struct FileInfo
{
	unsigned int	filesize;
	long long		tar_offset;
	time_t			mtime;
public:
	FileInfo():filesize(),tar_offset(), mtime(){};
	FileInfo(int a,int b,int c):filesize(a),tar_offset(b), mtime(c){};
	FileInfo( const FileInfo &other)
	{
		filesize=other.filesize;
		tar_offset=other.tar_offset;
		mtime=other.mtime;
	}
	FileInfo & operator = (const FileInfo &other)
	{
		filesize=other.filesize;
		tar_offset=other.tar_offset;
		mtime=other.mtime;	
		return *this;
	}
	friend ostream &  operator << (ostream &in , const FileInfo &fileinfo)
	{
		in<<"------------------------------------"<<endl;
		in<<"filesize "<<fileinfo.filesize<<endl;
		in<<"tar_offset "<<fileinfo.tar_offset<<endl;
		in<<"mtime "<<fileinfo.mtime<<endl;
		return in;
	}
};


int main()
{
	FileInfo a(1,1,1),b(2,2,2),c(3,3,3);
	FileInfo d(a);
	FileInfo *ptr= new  FileInfo (1,2,3);
	cout<<a<<b<<c<<d<<endl;
}
