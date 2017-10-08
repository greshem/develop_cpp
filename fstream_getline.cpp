#include <stdlib.h>
#include <fstream> 
#include <iostream> 
using namespace std;
void string_replace(string & strBig, const string & strsrc, const string &strdst) {
        string::size_type pos=0;
        string::size_type srclen=strsrc.size();
        string::size_type dstlen=strdst.size();
        while( (pos=strBig.find(strsrc, pos)) != string::npos){
                strBig.replace(pos, srclen, strdst);
                pos += dstlen;
        }
};

int main(int argc, char *argv[])
{
	//没有这样的调用的方式。 
	//fstream file(string(argv[1]),ios::in);
	fstream file(argv[1],ios::in);
	string line;
	while(std::getline(file,line, '\n' ))
    {
		if(line.find("@qianzhongjie@") != string::npos)
		{
//		cout<<"find qianzhongjie"<<endl;
		string_replace(line, "@qianzhongjie@","@wenshuna@");		 
	
		cout<<line<<endl;
		}
		else
		{
		cout<<line<<endl;
		}
	}
}
