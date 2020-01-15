#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<fstream>
using namespace std;
#include "5_prototype.h"

#define MAX_SIZE 100
#define fee1 4300
//currente size of the stud_data array
int current_size = 0;

// this two strings are created to store current time and date ::
// we will use them as last-saved entry;
char l_date[30];
char l_time[30];
//===============================================================

// this id will increase every time a new student added;
int Id=202001;

DATA stud_data[MAX_SIZE];

void last_status()
{
  strcpy(l_date,__DATE__);
  strcpy(l_time,__TIME__);
}

// main..heading of student-information
void Heading()
{
  puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  puts("Id        Date              Full-Name          Nick-name      School         SSC-GPA   SSC-Year    Scholarship        Payment         Number            Blood-Group         Mail");
  puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}
// this is a new heading ::
//when we want to see the due payment students we dont need to see all the informations;
void HeadingDUES()
{
  puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  puts("Id        Date              Full-Name          Nick-name           School         Dues(tk)            Number            Blood-Group            Mail");
  puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

void addEntry()
{
  DATA s;
  char sch,paym,choice;
  int month,paym1,advance;

  if(current_size==MAX_SIZE)
  {puts("~~~~~ !! Sorry NO Seat Available !! ~~~~~");
    return;
  }

    cout<<("*** Enter ur ***");

    cout<<("\nFirst Name : ");
    cin>>s.f_name;

    cout<<"Last Name : ";
    cin>>s.l_name;
    cout<<"** Any Nick-Name---(y/n) == ";
    cin>>choice;
    if(choice=='y')
    { cout<<"\nNick-Name : ";
      cin>>s.nick_name; }
    else
    strcpy(s.nick_name,s.f_name);

    cout<<"SSC year : ";
    cin>>s.year;

    cout<<"G.P.A : ";
    cin>>s.GPA;

    cout<<"School Name : ";
    cin>>s.school;

    cout<<"Scholarship--(y/n) = ";
    cin>>sch;
    if(sch=='y')
    strcpy(s.scholarship,"Yes");
    else
    strcpy(s.scholarship,"No");

    cout<<"Mobile-Number : ";
    cin>>s.number;

    cout<<"Mail-address : ";
    cin>>s.mail;

    cout<<"Blood-Group : ";
    cin>>s.bld_grp;

    cout<<"\nDo u want to give this-month payment--(y/n) == ";
    cin>>paym;
    if(paym=='y')
    {
      cout<<"\n\t# Per-Month-->> "<<fee1<<" tk"<<endl<<"\t## Whats u'r choice ::";
      cout<<"\n\t1. Full-payment\n\t2. Keep Dues\n== ";
      cin>>paym1;
      switch (paym1)
      {
        case 1: strcpy(s.payment,"Paid");
        break;
        case 2: strcpy(s.payment,"Dues");
                cout<<"\n** How much you want to pay == ";
                cin>>advance;
                s.dues=fee1-advance;
        break;
      }
    }
    else
    strcpy(s.payment,"Not-Paid");

    s.id = Id;
    cout<<"Student Id: "<<s.id<<endl;
    ++Id;

    strcpy(s.date,__DATE__);

    stud_data[current_size]=s;
    ++current_size;

}
void displaySrM()
{
  int D_id[10]={0} ,invalidID[10]={0},k=0, i=0,j, heading=0,invalid=0,got=0; // one can display 10 members at a time
  char input;

  cout<<"\n======= Give the Student Id ======="<<endl<<"...Id = ";
  cin>> D_id[i]; ++i;
  while(1)
  {
    cout<<"\n** Do u want to give another Id--(y/n) = ";
    cin>>input;

    if(input=='y')
    { cout<<"\n...Id = ";
      cin>>D_id[i];
      ++i;
    }

    else
    break;
  }

  for(i=0;i<10;i++)
  { got=0;

     for(j=0;j<current_size;j++)
     {
         DATA s = stud_data[j];
         if(D_id[i]==s.id)
         { got=1;
         ++heading;if(heading==1)Heading();
         display(j);
         break;
         }
     }

     if(D_id[i] != 0 && got==0)
     {
       ++invalid;
       invalidID[k]=D_id[i];
       ++k;
     }
  }

if(invalid>0)
{
cout<<"\n..!!.. "<<invalid<<" Invalid Id found = ";
for(i=0;i<invalid;i++)
cout<<invalidID[i]<<",";
}

}

void displayAll()
{
  DATA s;

  if(current_size==0)
  {puts("~~~~~ !! NO Student Admitted Yet !! ~~~~~");
   return;
  }


Heading();
for(int i=0;i<current_size;i++)
      {
        display(i);
      }

}
void display(int k)
{
  DATA s=stud_data[k];
  char fullName[25];
  strcpy(fullName,s.f_name);
  strcat(fullName," ");
  strcat(fullName,s.l_name);

  printf("%-10d%-18s%-20s%-15s%-15s%-10.1f%-15d%-16s%-15s%-20s%-17s%-20s\n",s.id,s.date,fullName,s.nick_name,s.school,s.GPA,s.year,s.scholarship,s.payment,s.number,s.bld_grp,s.mail);
  puts("________________________________________________________________________________________________________________________________________________________________________________________");
}
void modify()
{  int choice1,modify_id,i,found=0,paym1,advance;
  char input;
  char sch,paym,choice;
  int month;

   cout<<"~~~~~~~~ Modify ~~~~~~~~\n";
   cout<<"Give Id ::  ";
   cin>>modify_id;
start1:
for(i=0;i<current_size;i++)
  {
    //DATA s= stud_data[i];

    if(modify_id==stud_data[i].id)
    { found=1;

      cout<<"\nWhich info u want to modify ::\n";
      cout<<"  1. ALL-info\n\n  2.First-Name\n\n  3.Last-Name\n\n  4. Nick-Name\n\n  5. School-Name\n\n  6. SSC-Grade\n\n  7. SSC-Year\n\n  8. Scholarship-info\n\n  9. Mobile-Number\n\n  10. E-mail address\n\n  11. Blood-Group\n\n  12. Payment-info\n\n  13...:back:..\n==";
      cin>>choice1;
      switch(choice1)
      {
        //case 1 for modifying all the information
        case 1:
        cout<<("*** Enter NEW ***");

        cout<<("\nFirst Name : ");
        cin>>stud_data[i].f_name;

        cout<<"Last Name : ";
        cin>>stud_data[i].l_name;
        cout<<"** Any Nick-Name---(y/n) == ";
        cin>>choice;
        if(choice=='y')
        { cout<<"\nNick-Name : ";
          cin>>stud_data[i].nick_name; }
        else
        strcpy(stud_data[i].nick_name,stud_data[i].f_name);

        cout<<"SSC year : ";
        cin>>stud_data[i].year;

        cout<<"G.P.A : ";
        cin>>stud_data[i].GPA;

        cout<<"School Name : ";
        cin>>stud_data[i].school;

        cout<<"Scholarship--(y/n) = ";
        cin>>sch;
        if(sch=='y')
        strcpy(stud_data[i].scholarship,"Yes");
        else
        strcpy(stud_data[i].scholarship,"No");

        cout<<"Mobile-Number : ";
        cin>>stud_data[i].number;

        cout<<"Mail-address : ";
        cin>>stud_data[i].mail;

        cout<<"Blood-Group : ";
        cin>>stud_data[i].bld_grp;

        cout<<"\nDo u want to give this-month payment--(y/n) == ";
        cin>>paym;
        if(paym=='y')
        {
          cout<<"\n\t# Per-Month-->> "<<fee1<<" tk"<<endl<<"\t## Whats u'r choice ::";
          cout<<"\n\t1. Full-payment\n\t2. Keep Dues\n== ";
          cin>>paym1;
          switch (paym1)
          {
            case 1: strcpy(stud_data[i].payment,"Paid");
            break;
            case 2: strcpy(stud_data[i].payment,"Dues");
                    cout<<"\n** How much you want to pay == ";
                    cin>>advance;
                    stud_data[i].dues=fee1-advance;
            break;
          }
        }
        else
        strcpy(stud_data[i].payment,"Not-Paid");

        strcpy(stud_data[i].date,__DATE__);

        cout<<"\n** All information modified successfully..\n";

        break;
//============================================================================
        case 2: cout<<"\n Enter new First-Name : ";
                cin>>stud_data[i].f_name;
                cout<<"\n** First_name modified successfully..\n";
                cout<<"1 "<<stud_data[1].f_name;
                cout<<"Do u want to Modify more--(y/n) == ";
                cin>>input;
                if(input=='y')
                 goto start1;

                else
                return;
        break;
        case 3: cout<<"\n Enter new Last-Name : ";
                cin>>stud_data[i].l_name;
                cout<<"\n** Last_name modified successfully..\n";
                cout<<"Do u want to Modify more--(y/n) == ";
                cin>>input;
                if(input=='y')
                 goto start1;

                else
                return;
        break;
        case 4: cout<<"\n Enter new Nick-Name : ";
                cin>>stud_data[i].nick_name;
                //strcpy(s.nick_name,new_nick_name);
                cout<<"\n** Nick_name modified successfully..\n";
                cout<<"Do u want to Modify more--(y/n) == ";
                cin>>input;
                if(input=='y')
                 goto start1;

                else
                return;
        break;
        case 5: cout<<"\n Enter new School-Name : ";
                cin>>stud_data[i].school;
                //strcpy(s.school,new_school);
                cout<<"\n** School_name modified successfully..\n";
                cout<<"Do u want to Modify more--(y/n) == ";
                cin>>input;
                if(input=='y')
                 goto start1;

                else
                return;
        break;
        case 6: cout<<"\n Enter new SSC-Grade : ";
                cin>>stud_data[i].GPA;
//                s.GPA=new_GPA;
                cout<<"\n** SSC-Grade modified successfully..\n";
                cout<<"Do u want to Modify more--(y/n) == ";
                cin>>input;
                if(input=='y')
                 goto start1;

                else
                return;
        break;
        case 7: cout<<"\n Enter new SSC-Year : ";
                cin>>stud_data[i].year;
//                s.year=new_year;
                cout<<"\n** SSC-Year modified successfully..\n";
                cout<<"Do u want to Modify more--(y/n) == ";
                cin>>input;
                if(input=='y')
                 goto start1;

                else
                return;
        break;
        case 8: cout<<"\n Enter new Scholarship-info : ";
                cin>>stud_data[i].scholarship;
//                s.GPA=new_year;
                cout<<"\n** Scholarship-info modified successfully..\n";
                cout<<"Do u want to Modify more--(y/n) == ";
                cin>>input;
                if(input=='y')
                 goto start1;

                else
                return;
        break;
        case 9: cout<<"\n Enter new Mobile_Number : ";
                cin>>stud_data[i].number;
//                strcpy(s.number,new_number);
                cout<<"\n** Mobile_Number modified successfully..\n";
                cout<<"Do u want to Modify more--(y/n) == ";
                cin>>input;
                if(input=='y')
                 goto start1;

                else
                return;
        break;
        case 10: cout<<"\n Enter new Email_Address : ";
                cin>>stud_data[i].mail;
//                strcpy(s.mail,new_mail);
                cout<<"\n** Email_Address modified successfully..\n";
                cout<<"Do u want to Modify more--(y/n) == ";
                cin>>input;
                if(input=='y')
                 goto start1;

                else
                return;
        break;
        case 11: cout<<"\n Enter new Blood_Group : ";
                cin>>stud_data[i].bld_grp;
//                strcpy(s.bld_grp,new_bld_grp);
                cout<<"\n** Blood_Group modified successfully..\n";
                cout<<"Do u want to Modify more--(y/n) == ";
                cin>>input;
                if(input=='y')
                 goto start1;

                else
                return;
        break;
        case 12: //payment_info_modification
        cout<<"\n\t# Per-Month-->> "<<fee1<<" tk"<<endl<<"\t## Whats u'r choice ::";
        cout<<"\n\t1. Full-payment\n\t2. Keep Dues\n3. No payment \n== ";
        cin>>paym1;
            switch (paym1)
            {
              case 1: strcpy(stud_data[i].payment,"Paid");
                      cout<<"\n** Payment_info modified successfully..\n";
              break;
              case 2: strcpy(stud_data[i].payment,"Dues");
                      cout<<"\n** How much you want to pay == ";
                      cin>>advance;
                      stud_data[i].dues=fee1-advance;
                      cout<<"\n** Payment_info modified successfully..\n";
              break;
              case 3: strcpy(stud_data[i].payment,"Not-Paid");
                      cout<<"\n** Payment_info modified successfully..\n";
              break;
            }

            cout<<"Do u want to Modify more--(y/n) == ";
            cin>>input;
            if(input=='y')
             goto start1;

            else
            return;

        break;
        case 13: break;
      }

    }

  }
  if(found==0)
  cout<<"......!! invalid Id !!......";
}
void payment_FULL()
{
  int count=0,heading=0,i;
  char choice;

   for(i=0;i<current_size;i++)
   {
      DATA s= stud_data[i];
      if(strcmp(s.payment,"Paid")==0)
      ++count;
   }
   cout<<"------>> "<<count<<" Students gave Full-Payment\n";
   cout<<"\n** Do u want to see the LIST---(y/n) == ";
   cin>>choice;
   if(choice=='y')
   {
     for(i=0;i<current_size;i++)
     {
        DATA s= stud_data[i];
        if(strcmp(s.payment,"Paid")==0)
         {
           ++heading;if(heading==1)Heading();
             display(i);
         }
     }
   }
   else
   return;
}
void payment_DUES()
{
  int count=0,i,heading=0;
  char choice;
  char fullName[25];

   for(i=0;i<current_size;i++)
   {
      DATA s= stud_data[i];
      if(strcmp(s.payment,"Dues")==0)
      ++count;
   }
   cout<<"------>> "<<count<<" Students have Dues-Payment\n";
   cout<<"\n** Do u want to see the LIST---(y/n) == ";
   cin>>choice;
   if(choice=='y')
   {
     for(i=0;i<current_size;i++)
     {
        DATA s= stud_data[i];
        if(strcmp(s.payment,"Dues")==0)
         {
           ++heading;if(heading==1)HeadingDUES();
             //display(i);

             strcpy(fullName,s.f_name);
             strcat(fullName," ");
             strcat(fullName,s.l_name);

             printf("%-10d%-18s%-20s%-20s%-15s%-20d%-20s%-20s%-20s\n",s.id,s.date,fullName,s.nick_name,s.school,s.dues,s.number,s.bld_grp,s.mail);
             puts("____________________________________________________________________________________________________________________________________________________");
         }
     }
   }
   else
   return;
}
void deleteENTRY()
{  int delete_id;
   int count=0,i,j;

   cout<<"=========== Which Student Info U Want to Delete ::\n";
   cout<<"------------------------- Input The Id = ";
   cin>> delete_id;

   if(current_size==0)
   {
     cout<<"\n No student addmited yet....\n";
     return;
   }

   for(i=0;i<current_size;i++)
   {
     DATA s= stud_data[i];
     if(delete_id==s.id)
     {
       for(j=i;j<current_size;j++)
       {
         stud_data[j] = stud_data[j+1];
       }

         current_size -=1;
         count=1;
     }
   }
   if(count==1)
   cout<<"\n ***** Student info Deleted *****";

}
