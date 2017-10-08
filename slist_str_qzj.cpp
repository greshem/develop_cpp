#include <stdlib.h>
//#include <MLmyUnit.hpp>
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
using namespace std;
typedef struct node{
		char *name;
		node * next;
	} NODE;

void initList(node *in, char *name)
{
	in->name=strdup(name);
	in->next=NULL;
}
int insertStr(node *in , char *str)
{
	node *tmp=(node *)malloc(sizeof(NODE));
	tmp->name=strdup(str);
	tmp->next=NULL;
	
	//node *end;
	//end=in;
	while(in->next!=NULL)
	{
		in=in->next;
	}
	//in=tmp;
	in->next=tmp;
	//in->name=strdup(
	return 1;
}

int dumpList(node *in)
{
	node *end;
	end=in;
	//in->next 的方式比较便于理解。 
	//end=in; 
	//while(end)
	//{ end=end->next;
	//}
	while(in->next!=NULL)
	{
		printf("%s\n", in->name);	
		in=in->next;
	}
	printf("%s\n", in->name);
	return 1;
}
int insertList(node *root, node *child)
{
	node *tmp;

	tmp=root->next;
	return 1;
	
}
int find(node *root, char *str)
{
	int nth=-1;
	int i=0;
	while(root->next !=NULL)
	{
		i++;
		if(strncmp(root->name, str,strlen(str))==0)
		{
			return i-1;	
		}
		root=root->next;
	}	
	
	//20100601  最后一个函数做特殊处理。 	
	if(strncmp(root->name, str,strlen(str))==0)
	{
		return i;
	}
	return -1;
}
int getCount( node *root)
{
	int i=0;
	while(root->next !=NULL)
	{
		root=root->next;
		i++;
	}	
	i++;
	return i;
}
int clear (node *root)
{
	//20100601 保存头节点。 
	int count=getCount(root);
	node ** ptr=(node **)malloc(count* sizeof(node));
	node *first=root;
	int i=0;
	//free(root->name);
	while(root->next != NULL)
	{
		free(root->name);
		
		ptr[i]=root->next;
		root=root->next;
		i++;
	}	
	//尾部节点特殊处理。 
	free(root->name);
	//释放str结束。 
	for(int i=0; i<count; i++)
	{
		free(ptr[i]);
	}	
	free(ptr);
	//开始释放 node struct
	//
	return 1;
	
}
int main(int argc, char *argv[])
{
	cout<<"list_str.cpp"<<endl;
	node root;
	initList(&root, "qianlong");
	insertStr(&root, "wenshuna1");	
	insertStr(&root, "wenshuna2");	
	insertStr(&root, "wenshuna3");	
	insertStr(&root, "wenshuna4");	
	insertStr(&root, "wenshuna5");	
	insertStr(&root, "wenshuna6");	
	insertStr(&root, "wenshuna7");	
	printf("%d\n", find(&root, "wenshuna7"));
	printf("%d\n", find(&root, "qianlong"));
	printf("count %d\n", getCount(&root));
	dumpList(&root);
	clear(&root);
	return 0;
}
