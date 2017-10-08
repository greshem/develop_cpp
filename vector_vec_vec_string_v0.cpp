#include <string>
#include <vector> 
#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std;

vector<string> gen_vec_str(int n);

int dump_vec_vec(vector<vector<string > > in);
//#int dump_vec(vector<vector<string > > in);
int dump_vec_string(vector<string > in);

int rand_string(char *name, int size)
{
	int i;
	for (i=0; i< size-1; i++)
	{
		*(name+i)='a'+rand()%26;
	}	
	*(name+size)='\0';
	return 0;
}

int main()
{
    vector<vector<string> > vec_vec_str1;

    
    vec_vec_str1.push_back(gen_vec_str(5));
    vec_vec_str1.push_back(gen_vec_str(5));
    vec_vec_str1.push_back(gen_vec_str(8));  
    vec_vec_str1.push_back(gen_vec_str(10));   
    vec_vec_str1.push_back(gen_vec_str(8));  
    vec_vec_str1.push_back(gen_vec_str(10));   
    
	int size=vec_vec_str1.size();
    vector<vector<string> > vec_vec_str2(vec_vec_str1.begin(),    vec_vec_str1.begin()+size-1  );
    cout<< vec_vec_str2.size()<<endl;
	dump_vec_vec(vec_vec_str1);
	cout<<"#################################################################"<<endl;
	dump_vec_vec(vec_vec_str2);
	
	cout<<"#################################################################"<<endl;
	
	vector<string> vec_str=vec_vec_str2[0];
	dump_vec_string(vec_str);
	
	cout<<"#################################################################"<<endl;
    //getchar();
    
}

vector<string> gen_vec_str(int n)
{
    char buffer[8];
    int i;
    vector<string > vec_str;
    for(i=0; i<n ;i++)
    {
     rand_string(buffer, 8);
     string tmp(buffer);
     vec_str.push_back(tmp);
    }
    return vec_str;
               
}
int dump_vec_string(vector<string > in)
{
	vector<string>::iterator it;
	for(it=in.begin(); it != in.end(); it++)
	{
		cout<<*it<<"\t";
	}
	cout<<endl;
	return 0;
}
int dump_vec_vec(vector<vector<string > > in)
{
	vector<string> vec_str;
	vector< vector <string>  >::iterator it;
	vector<string>::iterator it2;
	
	for(it=in.begin(); it!= in.end(); it++)
	{
		for(it2 = (*it).begin(); it2!=(*it).end(); it2++)
		{
			cout<<*it2<<"\t";
		}
		cout<<endl;
	}
	return 1;
}

int mesh(vector<vector<string > > in)
{
  int size=in.size();
  return 1;
}
