//we can use the C header files in C++ by adding an extra 'c' in front of the name & skipping the '.h' part.
#include<cstdio>                                    //exp:: in C == <stdio.h>
#include<cstdlib>                                   //    in C++ == <cstdio>
#include<cstring>

#include "2_functions.cpp"
#include "3_searching.cpp"
#include "4_file_handling.cpp"
#include "5_prototype.h"

#include<iostream>
using namespace std;

int main()
{
int n,m,sm,r;
char text[20]; //this is made for searching option

   readFromFile();//this function will read all the Information written to the FILE(data_base.dat)

start:
   while(1)
    {
      system("clear");//this will clear the screen **in windows-- system("cls")
      cout<<".....................................................................\n";
      cout<<"|-->> Last_Saved: "<<l_date<<" | " <<l_time<<"                            |"<<endl;
      cout<<"|-------------------------------------------------------------------|\n";
      cout<<"|>>>========== |#| Pre-HSC STUDENT_DATABASE_SYSTEM |#| ==========<<<|\n";
      cout<<"|-------------------------------------------------------------------|\n";
      cout<<"|                                      "<<__DATE__<<" | "<<__TIME__" <<<---|"<<endl;
      cout<<".....................................................................";

        cout<<"\n1. New Entry\n\n2. Display\n\n3. Search-By\n\n4. Modify-info\n\n5. Delete Entry\n\n6. Save to Data-Base\n\n7. Remove Data-Base file\n\n8. exit\n== ";
       cin>>n;
      switch(n)
      {
        case 1: addEntry();
        break;
        case 2: cout<<"\n~~~~~~~~~~ :: Display :: ~~~~~~~~~~\n";
                cout<<"\n    1. ALL Student_info\n\n    2. Full-Payment student_info\n\n    3. Dues-Payment student_info\n\n    4. Display Single/Multiple Student Info\n\n    5..:back:..\n== ";
                cin>>r;
                switch(r)
                {
                  case 1: displayAll();
                  break;
                  case 2: payment_FULL();
                  break;
                  case 3: payment_DUES();
                  break;
                  case 4: displaySrM();
                  break;
                  case 5: goto start;
                }
        break;
        case 3: cout<<"\n~~~~~~~~~~ :: Searching :: ~~~~~~~~~~\n";
                cout<<"\n    1. First-Name\n\n    2. Last-Name\n\n    3. School-Name\n\n    4. Mobile-Number\n\n    5. Blood-Group\n\n    6. Sim-user\n\n    7..:back:..\n==";
                cin>>m;
               switch(m)
               {  // by default enum sets the values....
                 //typedef enum {FIRST_NAME = 0, LAST_NAME = 1,SCHOOL_NAME = 2, NUMBER = 3, BLOOD_G = 4, SIM = 5} search_t;-->> {5_prototype.h} contains this line.
                // by using typedef we can write [search_t] instead of [enum]
                 case 1:
                      cout<<("\nEnter the First Name:\n== ");
                      cin>>("%s",text);
                      Search(text,FIRST_NAME);
                      break;
                 case 2:
                      cout<<("\nEnter the Last Name:\n== ");
                      cin>>text;
                      Search(text,LAST_NAME);
                      break;
                case 3:
                      cout<<("\nEnter the School Name:\n== ");
                      cin>>text;
                      Search(text,SCHOOL_NAME);
                      break;
                case 4:
                      cout<<("\nEnter the Number:\n== ");
                      cin>>text;
                      Search(text,NUMBER);
                      break;
                case 5:
                      cout<<("\nEnter the Blood-Group:\n== ");
                      cin>>text;
                      Search(text,BLOOD_G);
                      break;
                 case 6:
                      cout<<("\nWhich operator you want to search ::\n");
                      cout<<("1.Airtel\n2.Banglalink\n3.Robi\n4.GrameenPhone\n5.Teletalk\n== ");
                      cin>>sm;
                      switch(sm)
                      {
                        case 1:Search_sim(AIRTEL);
                        break;
                        case 2:Search_sim(BANGLA);
                        break;
                        case 3:Search_sim(ROBI);
                        break;
                        case 4:Search_sim(GP);
                        break;
                        case 5:Search_sim(TEL);
                        break;
                      }
                  break;
                 case 7: goto start;
               }
        break;
        case 4: modify();
        break;
        case 5: deleteENTRY();
        break;
        case 6: writeToFile();
        break;
        case 7: remove_FILE();
        break;
        case 8: exit(0);
      }
      mygetch();//this function will pause the screen until user presses Enter 2-times.
    }
}
char mygetch()
{
  string val;
  string rel;

  getline(cin,val);//1st time Enter
  getline(cin,rel);//2nd time Enter
}
