#include<fstream>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
//program to copy content of file and store it in another file;
void copy()
{
    ifstream fin;
    ofstream fout;
    char ch;
    fin.open("file1.txt",ios::in|ios::binary);
    fout.open("file2",ios::out|ios::binary);
    if(!fin)
      cout<<"File not found";
    else
       {
          ch=fin.get();
          while(!fin.eof())
          {
             fout<<ch;
             ch=fin.get();
          }
       }
       fin.close();
       fout.close();  
}
// Search word in a file
int Is_word(char *str)
{
    ifstream fin;
    char ch[20];
    fin.open("file1.txt",ios::in|ios::binary);
    if(!fin)
       cout<<"file not found ";
    else
       {
          while(!fin.eof())
          {
             fin>>ch;
              if(!strcmp(ch,str)) 
                 return 1;
          }
       }   
    return 0; 
    fin.close();  
}
//**************** 3 ********************
class Employee
{
  private:
      int empid;
      char name[20];
      float salary;
  public:
      void InputEmployee()    
      {
        cin>>empid;
        cin.ignore();
        cin.getline(name,20);
        cin>>salary;
      }
      void DisplayEmployee()
      {
        cout<<empid<<" "<<name<<" "<<salary<<endl;
      }
      void StoreNewRecord();
      void DisplayAllEmployeeRecord();
      void SearchEmployee(int);
      void EditEmpData(int);
      void deleteEmployee(int);
};
void Employee::StoreNewRecord()
{
    ofstream fout;
    fout.open("EmployeeR.dat",ios::app|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
}
void Employee::DisplayAllEmployeeRecord()
{
   ifstream fin;
   fin.open("EmployeeR.dat",ios::in|ios::binary);
   if(!fin)
      cout<<"File not found";
   else
    {
      fin.read((char*)this,sizeof(*this));
      while(!fin.eof())
      {
         DisplayEmployee();
         fin.read((char*)this,sizeof(*this));
      }
    }
   fin.close();     
}
void Employee::SearchEmployee(int id)
{
  ifstream fin;
  fin.open("EmployeeR.dat",ios::in|ios::binary);
  if(fin)
    {
       fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(empid==id)
            {
               DisplayEmployee();
               break;
            }
            else
              fin.read((char*)this,sizeof(*this));
        }
        if(fin.eof())
        cout<<"Search Faild !!!!!!!!";
    }
  else
     cout<<"File not found"; 
  fin.close(); 
}
void Employee::EditEmpData(int id)
{
   fstream file;
   int flag=0;
   file.open("EmployeeR.dat",ios::in|ios::out|ios::binary);
      if(!file)
         cout<<"File not found";
      else
         {
           file.read((char*)this,sizeof(*this));
          while(!file.eof())
          {
              if(empid==id)
              {
                 cout<<"Enter new data";
                 InputEmployee();
                 file.seekp(file.tellp()-sizeof(*this));
                 file.write((char*)this,sizeof(*this));
                 flag=1;
                 break;
              }
              file.read((char*)this,sizeof(*this));
          }
      }   
      file.close();   
      if(flag)   
        cout<<"Record Edit Successfully";
      else
        cout<<"Record not found";  
}
void Employee::deleteEmployee(int id)
{
   ifstream fin;
   ofstream fout;
   int flag=0;
   fin.open("EmployeeR.dat",ios::in|ios::binary);
   fout.open("temp.dat",ios::out|ios::binary);
   if(fin)
   {
      fin.read((char*)this,sizeof(*this));
      while(!fin.eof())
      {
         if(empid!=id)
            fout.write((char*)this,sizeof(*this));
         else
             flag=1;
         fin.read((char*)this,sizeof(*this));   
      }
   }
   else
     cout<<"File Not found";
   fin.close();
   fout.close();
   remove("EmployeeR.dat");
   rename("temp.dat","EmployeeR.dat");
   if(flag)  
     cout<<"Deletion Successful!!!!!";
   else
     cout<<"Record not found";  
}
int menu()
{
   cout<<"\n\n1.Input new record";
   cout<<"\n2.view all record";
   cout<<"\n3.Edit record";
   cout<<"\n4.Search record";
   cout<<"\n5.delete record";
   cout<<"\n6.Exit";
   int choice;
   cout<<"\nEnter your choice";
   cin>>choice;
   return choice;
}
int main()
{
    Employee e;
    while(1)
    {
      switch(menu())
      {
         case 1:
             e.InputEmployee();
             e.StoreNewRecord();
             break;
         case 2:
             e.DisplayAllEmployeeRecord();
             break;
         case 3:
             int id;
             cout<<"Enter Employee id";
             cin>>id;
             e.EditEmpData(id);    
             break;
         case 4:
             int d;
             cout<<"Enter Employee id";
             cin>>d;
             e.SearchEmployee(d);
             break;
         case 5:
             int i;
             cout<<"Enter Employee id";
             cin>>i;
             e.deleteEmployee(i);
             break;   
         case 6:
             exit(0);
         default:
            cout<<"Invalied Choice";              
      }
    }
    return 0;
}