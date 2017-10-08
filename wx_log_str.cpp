
#include <wx/sizer.h>                                                                               
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/colour.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/font.h>
#include <wx/gdicmn.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/string.h>
#include <wx/wx.h> 


#include <fstream>
#include <string> 
#include <sstream>
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
int main()
{
	int i;
 	wxString tmp=wxString::Format( _T("%d"), i);
	tmp+=tmp;
	string log(tmp.mb_str());
	//log::Instance()->logger("test %s\n", log.c_str());
}
