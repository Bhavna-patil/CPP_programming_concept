#include<iostream>
#include<string.h>
using namespace std;
//1 complex calss with appropriate member variable function
class Complex
{
    private:
        int real;
        int img;
    public: 
        void setData(int a,int b)    
        {
            real=a;
            img=b;
        }
        void showData()
        {
            cout<<real<<"+"<<img<<"i";
        }
};

//Define class time to represent time like(aa hr,bb min,cc sec) with appropriate member variable an functions
class Time
{
    private:
           int hr,min,sec;
    public:
          void settime(int a,int b,int c)       
          {
             if(c>=60)
               {
                 min=c/60+b;
                 sec=c%60;
                 hr=a;
               } 
             if(b>=60)
              {
                hr=b/60+a;
                min=b%60;
                sec=c;
              }
          }
        void showtime()  
        {
            cout<<hr<<" hr "<<min<<" min "<<sec<<" sec ";
        }
};
//DEfine date class to represent date(like d=31,m=12,y=2020)
char* munthname(int m)
{
    char *munth[]={"Jan","Feb","Mar","Apr","May","Jun","July","Aug","Sep","Oct","Nov","Dec"};
    return munth[m-1];
}
class Date
{
    private:  
        int d,m,y;
    public:
        void setdate(int a,int b,int c)    
        {
            if(a>31||b>12||c<0||a<0||b<0)
                cout<<"Invalid Data";
            else    
            {
              d=a,
              m=b,
              y=c;
            }
        }
      void showdate() 
       {
         cout<<"d="<<d<<" m="<<m<<" y="<<y;
       }
       //Define Date class to show date like 31-12-2020
       void showdateFormate1() 
       {
         cout<<d<<"-"<<m<<"-"<<y;
       }
       //Define Date class to show date like 31-dec-2020
       void showdateFormate2() 
       {
         cout<<d<<"-"<<munthname(m)<<"-"<<y;
       }
};
int main()
{
    Date c;
    c.setdate(6,7,10);
    c.showdateFormate2();
}
