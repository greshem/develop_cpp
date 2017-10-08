/***************************************************
* Description - 寻找vim 的插件的路径。 
* Author -      qianzhongjie@gmail.com
* Date -        2010_08_04_14:54:35
* *************************************************/

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
//#include <QzjUnit.hpp>
//#include <dirent.h>
//2010_08_04 by qzj. 

using namespace std;
string path[]=
{
"/usr/share/vim/vim72/doc",
"/usr/share/vim/vim72/keymap",
"/usr/share/vim/vim72/indent",
"/usr/share/vim/vim72/compiler",
"/usr/share/vim/vim72/syntax",
"/usr/share/vim/vim72/plugin",
"/usr/share/vim/vim72/lang",
"/usr/share/vim/vim72/ftplugin",
"/usr/share/vim/vim72/colors",
"/usr/share/vim/vim72/tutor",
"/usr/share/vim/vim72/print",
"/usr/share/vim/vim72/autoload",
"/usr/share/vim/vim72/macros",
"/usr/share/vim/vim72/spell"
};
#define COUNT(x) (sizeof(x)/sizeof(x[0]))

string  getKeyword( string in[], int size);

int main(int argc, char *argv[])
{
	map<string, string> vimPath;
		
	if( argc != 2)
	{
		warn<char> ("Usage: %s keyword", argv[0]);
		cout<<"#################################"<<endl;
		string tmp=getKeyword(path, COUNT(path) );
		die<char> ("keyword= \n%s", tmp.c_str() ) ;
	}	

	for (unsigned int i=0; i< COUNT(path); i++)
	{
		if( string(argv[1]) == basename(path[i].c_str()))
		{
		//	cout<<basename(path[i])<<endl;
			cout<<path[i]<<endl;
			break;
		}
	}
	
	return 1;
}

string  getKeyword( string in[], int size)
{
	string keyword;
	for (unsigned int i=0; i< COUNT(path); i++)
	{
		keyword+=basename(path[i].c_str());
		keyword+="\t";
		if(i%4==3)
		{
		
			keyword+="\n";
		}
		//cout<<keyword;
	}
	return keyword;	
}
