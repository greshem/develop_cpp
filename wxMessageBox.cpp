#include <wx/wx.h> 			

int main(int argc, char *argv[])
{
	if ( wxMessageBox( wxT("Are you sure you want to leave this page?\n")
                	wxT("(This demonstrates veto-ing)"),
                	wxT("Notebook sample"),
                	wxICON_QUESTION | wxYES_NO,
                	NULL) != wxYES )
	{
	// event.Veto();
	// veto = _T(" (vetoed)");
	}

	return 0;
}
