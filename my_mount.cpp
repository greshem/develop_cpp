#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
#include <Baselib.hpp>
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif


#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
//#include <dirent.h>
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
#include <sys/mount.h>
//2010_07_12 by qzj. 
// 自己把 /mnt/sda1 写成了 mnt/sda1 错误
using namespace std;

int main(int argc, char *argv[])
{
	int ret=mount ("/dev/sda1", "/mnt/sda1", "vfat", MS_RDONLY ,"iocharset=gb2312");
	cout<<ret<<endl;
	cout<<errno<<endl;
	perror("bbbb");
	cout<<"################"<<endl;
	//perror();

	/*int ret=mount ("/mnt/sda1", "/mnt/sda1", "vfat", MS_RDONLY ,"iocharset=gb2312");
	cout<<ret<<endl;
	cout<<errno<<endl;
	cout<<"################"<<endl;*/
	return 0;
}
