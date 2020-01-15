#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<fstream>
using namespace std;
#include "5_prototype.h"

//searching by f-name, l-name, number , blood group
void Search(char *text, search_t type)
{ int i, heading;
  char input;
   if(type==FIRST_NAME)
   {heading=0;
      for(i=0;i<current_size;i++)
      {
         if(strcmp(text,stud_data[i].f_name)==0)
         { ++heading;if(heading==1)Heading();
           display(i);
         }
         else
         puts("!....Sorry Invalid Input....!!");
      }
   }
   else if(type==LAST_NAME)
   {heading=0;
      for(i=0;i<current_size;i++)
      {
         if(strcmp(text,stud_data[i].l_name)==0)
         { ++heading;if(heading==1)Heading();
           display(i);
         }
         else
         puts("!....Sorry Invalid Input....!!");
      }
   }
   else if(type==SCHOOL_NAME)
   {heading=0;
      for(i=0;i<current_size;i++)
      {
         if(strcmp(text,stud_data[i].school)==0)
         { ++heading;if(heading==1)Heading();
           display(i);
         }
         else
         puts("!....Sorry Invalid Input....!!");
      }
   }
   else if(type==NUMBER)
   {heading=0;
      for(i=0;i<current_size;i++)
      {
         if(strcmp(text,stud_data[i].number)==0)
         {++heading;if(heading==1)Heading();
           display(i);
         }
         else
         puts("!....Sorry Invalid Input....!!");
      }
   }
   else if(type==BLOOD_G)
   { int count=0;
     heading=0;

     for(i=0;i<current_size;i++)
       {if(strcmp(text,stud_data[i].bld_grp)==0)
         ++count;}
if(count>0)
cout<<"\n\t\t************ "<<count<< " Members Found ************\n";

else
puts("....!!! Sorry no Record Found !!!....");

        cout<<"\n Do u want to see the list--(y/n) = ";
        cin>>input;
        if(input=='y')
        {
          for(i=0;i<current_size;i++)
             {
               if(strcmp(text,stud_data[i].bld_grp)==0)
               { ++heading;if(heading==1)Heading();
                 display(i);
               }
             }
        }
    }

}
//search by sim number
void Search_sim(int mySim_INT)
{
int i,found=0 , sim_found , sim_check,heading=0;
char sim[20],input;

//loop-1 for counting if there any unknown operator
for(i=0;i<current_size;i++)
{
   strcpy(sim,stud_data[i].number);
   if(sim[2]=='6'||sim[2]=='5'||sim[2]=='7'||sim[2]=='9'||sim[2]=='3'||sim[2]=='4')
     found=1;
}
//found==1 means operator is varified & print the heading
if(found==0)
{
puts("!!!......sorry invalid operator.....!!!");
return;
}
//==============================================================
if(mySim_INT==AIRTEL)
{ sim_found=0;
  sim_check=0;

  for(i=0;i<current_size;i++)
  {
     strcpy(sim,stud_data[i].number);
     if(sim[2]=='6')
      ++sim_check;
  }
  if(sim_check>0)
  { cout<<"\n\t\t************ "<<sim_check<< " Members Found ************\n";

    cout<<" Do u want to see the list--(y/n) = ";
    cin>>input;
    if(input=='y')
    { Heading();
    for(i=0;i<current_size;i++)
    {
       strcpy(sim,stud_data[i].number);
       if(sim[2]=='6')
       { sim_found=1;
          display(i);
        }
    }
    }
  }
  if(sim_found==0)
  puts("~~~~~ !! SORRY No AIRTEL-Sim user found !! ~~~~~");

  return;
}

if(mySim_INT==BANGLA)
{ sim_found=0;
  sim_check=0;

  for(i=0;i<current_size;i++)
  {
     strcpy(sim,stud_data[i].number);
     if(sim[2]=='9'||sim[2]=='4')
      ++sim_check;
  }
  if(sim_check>0)
  {cout<<"\n\t\t************ "<<sim_check<< " Members Found ************\n";


      cout<<" Do u want to see the list--(y/n) = ";
      cin>>input;
      if(input=='y')
      { Heading();
      for(i=0;i<current_size;i++)
      {
         strcpy(sim,stud_data[i].number);
         if(sim[2]=='9'||sim[2]=='4')
         { sim_found=1;
            display(i);
          }
      }
      }
    }
    if(sim_found==0)
    puts("~~~~~ !! SORRY No BANGLALINK-Sim user found !! ~~~~~");

    return;
}

if(mySim_INT==ROBI)
{ sim_found=0;
  sim_check=0;

  for(i=0;i<current_size;i++)
  {
     strcpy(sim,stud_data[i].number);
     if(sim[2]=='8')
      ++sim_check;
  }
  if(sim_check>0)
  {cout<<"\n\t\t************ "<<sim_check<< " Members Found ************\n";


      cout<<" Do u want to see the list--(y/n) = ";
      cin>>input;
      if(input=='y')
      { Heading();
      for(i=0;i<current_size;i++)
      {
         strcpy(sim,stud_data[i].number);
         if(sim[2]=='8')
         { sim_found=1;
            display(i);
          }
      }
      }
    }

    if(sim_found==0)
    puts("~~~~~ !! SORRY No ROBI-Sim user found !! ~~~~~");

    return;
}

if(mySim_INT==TEL)
{sim_found=0;
  sim_check=0;

  for(i=0;i<current_size;i++)
  {
     strcpy(sim,stud_data[i].number);
     if(sim[2]=='5')
      ++sim_check;
  }
  if(sim_check>0)
  {cout<<"\n\t\t************ "<<sim_check<< " Members Found ************\n";


      cout<<" Do u want to see the list--(y/n) = ";
      cin>>input;
      if(input=='y')
      { Heading();
      for(i=0;i<current_size;i++)
      {
         strcpy(sim,stud_data[i].number);
         if(sim[2]=='5')
         { sim_found=1;
            display(i);
          }
      }
      }
    }
  if(sim_found==0)
  puts("~~~~~ !! SORRY No TELETALK-Sim user found !! ~~~~~");
  return;
}

if(mySim_INT==GP)
{ sim_found=0;
  sim_check=0;

  for(i=0;i<current_size;i++)
  {
     strcpy(sim,stud_data[i].number);
     if(sim[2]=='7'||sim[2]=='3')
      ++sim_check;
  }
  if(sim_check>0)
  {cout<<"\n\t\t************ "<<sim_check<< " Members Found ************\n";

      cout<<" Do u want to see the list--(y/n) = ";
      cin>>input;
      if(input=='y')
      { Heading();
      for(i=0;i<current_size;i++)
      {
         strcpy(sim,stud_data[i].number);
         if(sim[2]=='7'||sim[2]=='3')
         { sim_found=1;
            display(i);
          }
      }
      }
    }
    if(sim_found==0)
    puts("~~~~~ !! SORRY No GrameenPhone-Sim user found !! ~~~~~");

    return;
}

}
