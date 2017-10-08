#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
#include <Baselib.hpp> 
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
//2010_08_05 by qzj. 
class videoPlay
{
	public:
		virtual void play()
		{
			cout<<"video play"<<endl;
		}
};

class  DVDPlay :public videoPlay
{
	void play()
	{
		cout<<"DvD play"<<endl;
	}
};
class  VCDPlay :public videoPlay
{
	void play()
	{
		cout<<"VCD play"<<endl;
	}
};
//###########################################################
using namespace std;
class MP4
{
private:
	videoPlay *mp4;
public:
	MP4(char *in)
	{
		mp4=NULL;
		if(( strcmp(in, "vcd")==0))
		{
			mp4=new VCDPlay;	
		}	
		else if(	strcmp(in,"dvd")==0)
		{
			mp4=new DVDPlay;	
		}
		else
		{
			cout<<"不支持的对象"<<in<<endl;
		}
	}
public:
	int start()
	{
		printf("%x", mp4);
		if(mp4)
		{
			mp4->play();
		}
		else
		{
			cout<<"mp4 对象为空 正确初始化 mp4 对象"<<endl;
		}
		return 1;
	}
	
};
//###########################################################
int main(int argc, char *argv[])
{
	MP4 ipod("ddvd");
	ipod.start();	
	return 0;
}
