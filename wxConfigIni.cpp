/*
{  
  wxConfigBase *pConfig = wxConfigBase::Get();
  if ( pConfig == __null )
    return;


  pConfig->Write(L"/Controls/Text", m_text->GetValue());
  pConfig->Write(L"/Controls/Check", m_check->GetValue());


  int x, y, w, h;
  GetClientSize(&w, &h);
  GetPosition(&x, &y);
  pConfig->Write(L"/MainFrame/x", (long) x);
  pConfig->Write(L"/MainFrame/y", (long) y);
  pConfig->Write(L"/MainFrame/w", (long) w);
  pConfig->Write(L"/MainFrame/h", (long) h);

  pConfig->Write(L"/TestValue", L"A test value");
	return;
}
*/
int main(int argc, char *argv[])
{
	return 0;
}
