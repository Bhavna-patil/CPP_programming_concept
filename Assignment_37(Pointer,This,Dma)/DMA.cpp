#include<iostream>
#include<string.h>
using namespace std;
//************* 1*************
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
//************** 2*********
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
//**************** 4 ***********
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
           for(r=1;r<5;r++)
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
//******************* 8 *******************
class String
{
    private:
        char *str;
        int length;
    public:
        String()
        {
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
        void InputString()
        {
            char *q,ch;
            int i,size=1;
            str=new char[size];
            str[0]='\0';
            while(1) 
            {
               ch=getchar();
               if(ch=='\n')
                  break;
               q=new char[size+1];
               for(i=0;i<size;i++)   
                  q[i]=str[i];
               q[size-1]=ch;
               q[size]='\0';  
               delete []str;
               str=new char[size+1];
               strcpy(str,q);
               delete []q;
               size++;
            }
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
        void StrUpr(String s){ strupr(s.str); }
        void StrLwr(String s){  strlwr(s.str);}
        char* getString(){ return str;}
        int getLength(){ return length; }
        ~String(){ delete []str; }
};
int main()
{
   String s1,s2,s3;
   s1.InputString();
   s1.ShowString();
   cout<<s1.getLength();
   return 0;
}