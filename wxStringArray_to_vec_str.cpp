#include <stdlib.h>
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
#include <map>
//#include <gtest/gtest.h>
//2011_03_09 by greshem. 

#include <wx/wx.h>
#include <wx/thread.h>
#include <wx/confbase.h>
#include <wx/encconv.h>
#include <wx/datetime.h>
//wxString::AfterFirst(wchar_t) const
//wxString::AfterLast(wchar_t) const
//wxString::BeforeFirst(wchar_t) const
//wxString::BeforeLast(wchar_t) const
//wxString::CmpNoCase(wchar_t const*) const
//wxString::CmpNoCase(wxString const&) const
//wxString::Cmp(wchar_t const*) const
//wxString::Cmp(wxString const&) const
//wxString::EndsWith(wchar_t const*, wxString*) const
//wxString::Find(wchar_t, bool) const
//wxString::Find(wchar_t const*) const
//wxString::FormatV(wchar_t const*, __va_list_tag*)
//wxString::Format(wchar_t const*, ...)
//wxString::Freq(wchar_t) const
//wxString::FromAscii(char)
//wxString::FromAscii(char const*)
//wxString::GetWriteBuf(unsigned long)
//wxString::IsAscii() const
//wxString::IsNumber() const
//wxString::IsWord() const
//wxString::Left(unsigned long) const
//wxString::Lower() const
//wxString::MakeLower()
//wxString::MakeUpper()
//wxString::Matches(wchar_t const*) const
//wxString::mb_str(wxMBConv const&) const
//wxString::Mid(unsigned long, unsigned long) const
//wxString::Pad(unsigned long, wchar_t, bool)
//wxString::PrintfV(wchar_t const*, __va_list_tag*)
//wxString::Printf(wchar_t const*, ...)
//wxString::Replace(wchar_t const*, wchar_t const*, bool)
//wxString::Right(unsigned long) const
//wxString::Shrink()
//wxString::sprintf(wchar_t const*, ...)
//wxString::StartsWith(wchar_t const*, wxString*) const
//wxString::Strip(wxString::stripType) const
//wxString::ToAscii() const
//wxString::ToDouble(double*) const
//wxString::ToLong(long*, int) const
//wxString::ToLongLong(long long*, int) const
//wxString::ToULongLong(unsigned long long*, int) const
//wxString::ToULong(unsigned long*, int) const
//wxString::Trim(bool)
//wxString::Truncate(unsigned long)
//wxString::UngetWriteBuf()
//wxString::UngetWriteBuf(unsigned long)
//wxString::Upper() const
//wxString::wxString(char const*, wxMBConv const&, unsigned long)
//

using namespace std;
//函数来自于 /root/develop_cpp/file_to_vector_string.cpp
int file_to_vector_string(string filename, vector<string> &out)
{
	//构造函数是 (char * , iso::in) 的参数. 
	//fstream file(filename.c_str() , ios::in);
	fstream file(filename.c_str() , ios::in);
	if(! file)
	{
		cout<<"file open file error"<<endl;
	}
	string line;
	while(std::getline(file, line, '\n'))
	{
		out.push_back(line);
	}
	return 1;
}

int vector_string_2_wxArrayString( vector<string> &in  , wxArrayString &out)
{
	vector<string>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		wxString tmp((*it).c_str(), wxConvUTF8);
		out.Add(tmp);
	}	
	return 1;
}

int wxArrayString_2_vector_string(  wxArrayString &in, vector<string> &out  )
{
	int count= in.GetCount();
	for(int i=0; i<count; i++)
	{
		string str(in.Item(i).mb_str());
		out.push_back(str);
	}
	return 1;
}


int main(int argc, char *argv[])
{
	
	//wxString  a;
	//string str(wxLogo.mb_str());
	//cout<<str.c_str()<<endl;
	vector<string> in;
	wxArrayString wx_array_str;
	file_to_vector_string("/etc/passwd", in);
	vector_string_2_wxArrayString(in, wx_array_str);		

	vector<string> out;
	wxArrayString_2_vector_string(wx_array_str, out);

 	copy(out.begin(), out.end(), ostream_iterator<string>(cout,"\n"));

	return 0;
}
