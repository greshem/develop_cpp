
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
#include <dirent.h>
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <queue>
#include <map>
#include <gtest/gtest.h>
//2011_05_08 by greshem. 

pthread_mutex_t muteks = PTHREAD_MUTEX_INITIALIZER;


using namespace std;
class base_scene
{
public:
	virtual void show()
	{
		cout<<"======================Base=============================================="<<endl;
		cout<<"=Base																  ="<<endl;
		cout<<"========================================================================"<<endl;
	}
};

class top_scene:public base_scene
{
	public:
	void show()
	{
		cout<<"======================Top10============================================="<<endl;
		cout<<"=Top10																  ="<<endl;
		cout<<"========================================================================"<<endl;
	}
};

class loser_scene:public base_scene
{
	public:
	void  show()
	{
		cout<<"======================Loser10==========================================="<<endl;
		cout<<"=Loser10																  ="<<endl;
		cout<<"========================================================================"<<endl;
	}
};

 base_scene * get_scene(int type)
{
	static base_scene *  base=NULL;
	static base_scene *  top=NULL;
	static base_scene *  loser=NULL;
	if(type==0)
	{
		if(base==NULL)
		{
			base=new base_scene;
		}
		return base;
	}
	else if(type == 1)
	{
		if(top==NULL)
		{
			top=new top_scene;
		}
		return top;
	}
	else if(type == 2)
	{
		if(loser==NULL)
		{
			loser=new loser_scene;
		}
		return loser;
	}
	return NULL;
}
queue<int> message;	
void* put_message(void *)
{
	static int i=0;
	while(1)
	{
		//int tmp=rand()%4;
		message.push(rand()%3);
		message.push(rand()%3);
		message.push(rand()%3);
		message.push(rand()%3);
			//cout<<"put message"<<i<<endl;
		sleep(2);
		i++;
	}
}
void * show(void *)
{
	base_scene *scene;
	while(1)
	{
		if(! message.empty())	
		{
			int mess=message.front();	
			message.pop();
			cout<<"get message"<<mess<<endl;	
			scene=get_scene(mess);		
			scene->show();
		}
		else
		{
			cout<<"message ЮЊПе"<<endl;
		}
		sleep(1);
	}
}
int main(int argc, char *argv[])
{
	pthread_t pth_producer;
	pthread_t pth_consumer;
	pthread_create(&pth_producer, NULL, put_message, NULL);
	pthread_create(&pth_consumer, NULL, show, NULL);
	while(1)
	{
		cout<<"this pareant"<<endl;
		sleep(10);
	}

}
