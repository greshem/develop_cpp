#include <string>
#include <vector> 
#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std;

vector<string> gen_vec_str(int n);

int dump_vec_vec(vector<vector<string > > in);

int  MeshAll(vector<vector<string> > &In, string right );
int  MeshAll( vector<vector<string> > &In );

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
	vector<string> vec_str1;
	vec_str1.push_back("aa");
	vec_str1.push_back("bb");
	vec_str1.push_back("cc");

	vector<string> vec_str2;
	vec_str2.push_back("11");
	vec_str2.push_back("22");
	vec_str2.push_back("33");

	vector<string> vec_str3;
	vec_str3.push_back("##");
	vec_str3.push_back("**");
	vec_str3.push_back("__");

	
    vector<vector<string> > vec_vec_str1;

    
    vec_vec_str1.push_back(vec_str1);
    vec_vec_str1.push_back(vec_str2);
    vec_vec_str1.push_back(vec_str3);  
    
	int size=vec_vec_str1.size();
    vector<vector<string> > vec_vec_str2(vec_vec_str1.begin(),    vec_vec_str1.begin()+size-1  );
    cout<< vec_vec_str2.size()<<endl;
	dump_vec_vec(vec_vec_str1);
	cout<<"#################################################################"<<endl;
	dump_vec_vec(vec_vec_str2);
	
	cout<<"#################################################################"<<endl;
	MeshAll(vec_vec_str1);
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


int  MeshAll( vector<vector<string> > &In )
{
    int size=In.size();
	//vector<vector<string> >  	vec_vec_str2(In.begin(), In.begin()+size-1);
	vector<string> right2(In[size-1]);
	
	vector<string>::iterator it;

	for(it=right2.begin(); it!=right2.end(); it++)
	{
		//cout<<"Deal with "<<(*it).c_str()<<endl;
		MeshAll(In, *it);
	}
	return 1;
}

/*##############################################################################
# 
#
#
##############################################################################*/
int MeshAll(vector<vector<string> > &In, string right )
{

	string temp(right);
	int size=In.size();
	vector<vector<string> > vec_vec_str_temp(In.begin(), In.begin()+size-1);
	vector<string> vec_str_temp(In[0]);
	vector<string> vec_str_last(In[size-1]);
	vector<string>::iterator it;

	
	if(size== 1)
	{
			vector<string > last(In[0]);
			//历遍， 并全部放入全局 vec<MString> 中。 
		//	for_each(last.begin(), last.end, )
		//	vec_str_temp=In[0];
			for(it=vec_str_temp.begin(); it!=vec_str_temp.end() ; it++)
			{
				temp=right;
				temp+=*it;
				//cout<<temp<<endl;
				printf("|||||||||| %s\n", temp.c_str());
			}
			return 1;
	}
	else
	{
		vec_str_temp = In[size-2];
	//	for(it=vec_str_temp.begin(); it!=vec_str_temp.end() ; it++)
		for(it=vec_str_last.begin(); it!=vec_str_last.end();it++)
		{
			temp=right;
			temp+=*it;
			//cout<<"DDD  "<<temp.c_str()<<endl;
			MeshAll(vec_vec_str_temp, temp);

		}
			
	}	

	return 1;
}

