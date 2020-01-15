#include<iostream>
#include<cstring>
#include<fstream>

#include<sstream>
//by using <sstream> header file we can convert an int-value to a string.
using namespace std;
#include "5_prototype.h"

char fname[]={"data_base.dat"};

void text_data()
{
  ofstream fout;
// <sstream> is the header file for [stringstream] data-type ....
  stringstream ss[current_size];

  for(int i=0;i<current_size;i++)
  {
  DATA s=stud_data[i];

   ss[i]<<s.id<<".txt"<<endl; // ss[] array will store new strings each time 'i' get incremented.
   string txtFileName = ss[i].str();

   fout.open(txtFileName);

   fout<<"~~~~~~~~~~~~ Admission Form ~~~~~~~~~~~~"<<endl;
   fout<<"............. Id :: "<<s.id<<" .............\n\n\n";
   fout<<"\t\tFirst name      : "<<s.f_name<<endl<<endl;
   fout<<"\t\tLast name       : "<<s.l_name<<endl<<endl;
   if(strcmp(s.nick_name,s.f_name)!=0)
   fout<<"\t\tNick-name       : "<<s.nick_name<<endl<<endl;
   fout<<"\t\tSSC year        : "<<s.year<<endl<<endl;
   fout<<"\t\tSSC GPA         : "<<s.GPA<<endl<<endl;
   fout<<"\t\tSCHOOL name     : "<<s.school<<endl<<endl;
   fout<<"\t\tScholarship     : "<<s.scholarship<<endl<<endl;
   fout<<"\t\tContact-Number  : "<<s.number<<endl<<endl;
   fout<<"\t\tBlood-Group     : "<<s.bld_grp<<endl<<endl;
   fout<<"\t\tMail-Address    : "<<s.mail<<endl<<endl;
   fout<<"----------------------------------------\n";
   fout<<"Payment Status : ";
   if(strcmp(s.payment,"Paid")==0)
   fout<<"Full-Paid"<<endl;
   else if(strcmp(s.payment,"Not-Paid")==0)
   fout<<"Not Paid yet"<<endl;
   else
   {
      fout<<"\n\t\t\t\t\t\t\t\t\tPaid = "<<fee1-s.dues<<endl;
      fout<<"\t\t\t\t\t\t\t\t\tDues = "<<s.dues<<endl;
   }
   fout<<"------------------ x -------------------";

   fout.close();
  }
}

void readFromFile()
{
  ifstream file(fname,ios::in| ios::binary);

  file.read((char *) l_date ,sizeof(l_date));
  file.read((char *) l_time ,sizeof(l_time));

  file.read((char *) stud_data ,sizeof(stud_data));

  file.read((char *) &current_size ,sizeof(current_size));

  file.read((char *) &Id ,sizeof(Id));


  file.close();
}

void writeToFile()
{
   last_status();

   ofstream file(fname,ios::out| ios::binary);

   file.write((char *) l_date ,sizeof(l_date));
   file.write((char *) l_time ,sizeof(l_time));

   file.write((char *) stud_data ,sizeof(stud_data));

   file.write((char *) &current_size ,sizeof(current_size));

   file.write((char *) &Id ,sizeof(Id));

   puts("********* Student Information Added Successfully *********");

   file.close();

   text_data();
}

void remove_FILE()
{  char choice;
   char new_file_name[10];

  cout<<"## Before deleting ::\n";
  cout<<"## Do u want to make a COPY of the file---(y/n) == ";
  cin>>choice;

  if(choice=='y')
  {
    cout<<"\nEnter the new file name = ";
    cin>>new_file_name;

    ofstream file( new_file_name ,ios::out| ios::binary);

    file.write((char *) l_date ,sizeof(l_date));
    file.write((char *) l_time ,sizeof(l_time));

    file.write((char *) stud_data ,sizeof(stud_data));

    file.write((char *) &current_size ,sizeof(current_size));

    file.write((char *) &Id ,sizeof(Id));

    cout<<"********* Student Information Copied Successfully to "<<new_file_name<<" *********";

    file.close();

    strcpy(fname,new_file_name);

    cout<<"\n--> Do u want to delete now--(y/n) == ";
    cin>>choice;
    if(choice=='y')
    {
    remove(fname);
    cout<<"\n*** File Deleted Successfully ***";
    }
    else
    return;
  }
  else
  {
  remove(fname);
  cout<<"\n*** File Deleted Successfully ***";
  }

}
