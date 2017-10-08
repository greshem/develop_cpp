#include <wx/wx.h> 
#include <wx/fileconf.h>


void GetIpList(wxArrayString &ServerIpList)
{
	ServerIpList.Add(wxT("192.168.1.1"));
	ServerIpList.Add(wxT("192.168.1.2"));
	ServerIpList.Add(wxT("192.168.1.3"));
	ServerIpList.Add(wxT("192.168.1.4"));
}


void FirstConfig()
{
        wxFileConfig OptionIni( wxEmptyString, wxEmptyString,  _T("option.ini"), wxEmptyString, 
                wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;
    OptionIni.Write(_T("SuperUser/UserName"), _T("Admin"));
    OptionIni.Write(_T("SuperUser/Password"), wxEmptyString);
    OptionIni.Write(_T("AutoWks/AddType"), 2);
    OptionIni.Write(_T("AutoWks/PreName"), _T("WKS"));
    OptionIni.Write(_T("AutoWks/NameCode"), 3);
        OptionIni.Write(_T("AutoWks/Template"), wxEmptyString ) ;

        wxArrayString ServerIpList;
    GetIpList(ServerIpList);

    wxString BootCard = wxEmptyString;
    if (ServerIpList.GetCount() > 0) BootCard = ServerIpList[0];
    wxString BootCardList = wxEmptyString;
    for(unsigned int i=0;i<ServerIpList.GetCount();i++)
    {
        if(i!=0)BootCardList = BootCardList + _T("|");
        BootCardList = BootCardList + ServerIpList[i];
    }
    OptionIni.Write(_T("AllocIP/DynamicIP"), false);
    OptionIni.Write(_T("AllocIP/IpList"), BootCardList);
   // OptionIni.Write(_T("AllocIP/StartIP"), GetAltIp(BootCard, _T("11")));
    //OptionIni.Write(_T("AllocIP/StopIP"), GetAltIp(BootCard, _T("254")));
    OptionIni.Write(_T("Other/LogError"), false);

    OptionIni.Write(_T("Other/ManPass"), _T(""));
    OptionIni.Write(_T("Other/SuperPass"), _T(""));
    OptionIni.Flush();
}


int main()
{
	FirstConfig();
}
