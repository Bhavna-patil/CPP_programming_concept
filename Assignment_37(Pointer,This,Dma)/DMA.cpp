#include<iostream>
#include<string.h>
using namespace std;
//define class persone and define destructor to initialize member variable 
class person
{
    private:
        char name[20];
        int age;
    public:
        person(char name[],int age)
        { 
          strcpy(this->name,name);
          this->age=age;
        }    
};
//Define a complex class with parametrized construct 
class Complex
{
    private:
       int a,b;
    public:
       void SetData(int a,int b)   
       {
          this->a=a;
          this->b=b;
       }
       void showData()
       {
          cout<<a<<"+"<<b<<"i";
       }
};
void f1()
{
    Complex *c=new Complex;
    c->SetData(2,3);
    c->showData();
    delete c; 
}
/**define a time class with appropriate methods and define an other method to dynamically
   creat an array of time object of specified size also define a method to sort time obj**/
class Time
{
    private:
       int hr,min,sec;
    public:
       void SetTime(int hr,int min,int sec)   
       {
          this->hr=hr;
          this->min=min;
          this->sec=sec;
       }
       void ShowTime()
       {
          cout<<hr<<" hr "<<min<<" min "<<sec<<" sec"<<endl;
       }
       void SetHour(int hr){this->hr=hr;}
       void SetMinut(int min){this->min=min;}
       void SetSecond(int sec){this->sec=sec;}
       int getHour(){return hr;}
       int getMinute(){return min;}
       int getSecond(){return sec;}
       Time* TimeArray(int size)
       {
           Time *temp=new Time[size];
           return temp;
       }
       bool operator>(Time t)
       {
          int sec1,sec2;
          sec1=hr*3600+min*60+sec;
          sec2=t.hr*3600+t.min*60+t.sec;
          if(sec1>sec2)
             return true;
          return false;   
       }
       void sortTime(Time *t,int size)
       {
           int i,r;
           Time temp;
           for(r=1;r<size;r++)
           {
             for(i=0;i<size-r;i++)
             {
                if(t[i]>t[i+1])
                {
                    temp=t[i];
                    t[i]=t[i+1];
                    t[i+1]=temp;
                }
             }
           }
       }
       void DisplayTimeArray(Time *t,int size)
       {
           int i;
            for(i=0;i<5;i++)
               t[i].ShowTime();
       }
};
/** define a class string with char pointer and length of string as instance member,define a 
    metod to hold the add of variable length string**/
class String
{
    private:
        char *str;
        int length;
    protected:
         char* InputString()
        {
            char *q,ch,*p;
            int i,size=1;
            p=new char[size];
            p[0]='\0';
            while(1) 
            {
               ch=getchar();
               if(ch=='\n')
                  break;
               q=new char[size+1];
               for(i=0;i<size;i++)   
                  q[i]=p[i];
               q[size-1]=ch;
               q[size]='\0';  
               delete []p;
               str=new char[size+1];
               strcpy(p,q);
               delete []q;
               size++;
            }
            return p;
        }   
    public:
        String()
        { 
           str=NULL;
           length=0;
        }
        String(String &s)
        {
            str=new char[strlen(s.str)];
            strcpy(str,s.str);
            length=s.length;
        }
        void operator=(String s)
        {
            delete []str;
            str=new char[strlen(s.str)];
            strcpy(str,s.str);
            length=s.length;
        }
        void SetString()
        {
           if(str!=NULL)
              delete str;
           str=InputString();
           length=strlen(str);
        }
        void SetString(char *s)
        {
            if(str!=NULL)
               delete []str;
            str=new char[strlen(s)];
            length=strlen(s);
            strcpy(str,s);
        }
        void ShowString(){ cout<<str<<endl;}
        void StrUpr(){ strupr(str); }
        void StrLwr(){  strlwr(str);}
        char* getString(){ return str;}
        int getLength(){ return length; }
        ~String(){ delete []str; }
};
