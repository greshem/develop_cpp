#include <stdio.h>
//########################################################################
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
//#include <dirent.h>
#include <unistd.h>
//#include <locale.h>
#include <sys/stat.h>
//#include <sys/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <assert.h>
//#include <stringprep.h>
#include <string>
#include <list>
#include <iostream>
#include <iterator>
using namespace std;

typedef struct  {
        std::string name;
        std::list <std::string> info;
        } Passwd;

char * rand_name( int size)
{
	int i;
	char *name=(char *)malloc(size);
	for (i=0; i<size; i++)
	{
		*(name+i)='a'+rand()%26;
	}	
	*(name+size)='\0';
	return  name;
}

int Gen_Passwd( Passwd * user)
{
    string temp=string(rand_name(16));
    
    user->name="root";
    (user->info).push_front("x");
    (user->info).push_front("root");
    (user->info).push_front("root");
    (user->info).push_front("/sbin/bash");
	return 1;
}
main()
{     int j;
      std::list<Passwd * > all_user;
      Passwd *temp;
      char word[256];
      temp= new Passwd;
      temp->name="root";
      for (j=0; j<=10; j++)
      {   
          //strtol(j, word, 10);
          memset(word, '\0', sizeof(word));
#ifdef WINDOWSCODE
          _snprintf(word,sizeof(word),  "%d", j); 
#else
          snprintf(word,sizeof(word),  "%d", j); 
#endif
          (temp->info).push_front(word);
        //  (temp->info).push_front("root");
        //  (temp->info).push_front("xxxxxx");
         // (temp->info).push_front("yyyyyyy");
      }
      for(int i=0; i<=10; i++)
      {
              //Gen_Passwd(temp);
              all_user.push_front(temp);
              all_user.push_front(temp);
              all_user.push_front(temp);
      }
  
      std::list<Passwd * >::iterator it;
      std::list <string>::iterator it_stage2;
      
      it=all_user.begin();
      
      
      //((*it)->info).reverse();
      
      //dump list of list 
      for (it= all_user.begin(); it!= all_user.end(); it++)
      {   
          cout << (*it)->name << " ";
          for ( it_stage2=((*it)->info).begin(); it_stage2!=((*it)->info).end(); it_stage2++)
          {
               cout << *it_stage2<<"  ";
          }
          cout <<endl;
      }
      cout <<"######################################"<<endl;
    //copy( ((*it)->info).begin(), ((*it)->info).end(), ostream_iterator<string>(cout, "\n"));
      //cin >> j;
      return 0;
}
