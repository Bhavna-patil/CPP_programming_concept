#include<iostream>
#include<stdlib.h>
using namespace std;
class Complex
{
    private:
       int real,img;
    public:
       void SetData(int a,int b)   
       {
          real=a;
          img=b;
       }
       void ShowData()
       {
        cout<<real<<"+"<<img<<"i"<<endl;
       }
       Complex operator+(Complex c) 
       {
          Complex temp;
          temp.real=real+c.real;
          temp.img=img+c.img;
          return temp;
       }
       Complex operator-(Complex c) 
       {
          Complex temp;
          temp.real=real-c.real;
          temp.img=img-c.img;
          return temp;
       }
       Complex operator*(Complex c) 
       {
          Complex temp;
          temp.real=real*c.real-img*c.img;
          temp.img=real*c.img+img*c.real;
          return temp;
       }
       bool operator==(Complex c) 
       {
          if(real==c.real&&img==c.img)
            return true;
          return false;  
       }
};
class Time
{
    private:
        int hr,min,sec;
    public:
        void SetTime(int a,int b,int c)    
        {
            hr=a;
            min=b;
            sec=c;
        }
        void ShowTime()
        {
            cout<<hr<<":"<<min<<":"<<sec<<endl;
        }
        bool operator>(Time t)
        {
            if(hr>t.hr)
              return true;
            else if(hr==t.hr&&min>t.min)  
              return true;
            else if(min==t.min&&sec>t.sec)  
              return true;
            return false;  
        }
        Time operator++(int)
        {
           sec++;
           min=min+sec/60;
           sec=sec%60;
           hr=hr+min/60;
           min=min%60;
           return *this;
        }
        Time operator++()
        {
           Time temp=*this;
           sec++;
           min=min+sec/60;
           sec=sec%60;
           hr=hr+min/60;
           min=min%60;
           return *this;
        }
        Time operator+(Time t)
        {
           Time temp;
           temp.hr=hr+t.hr;
           temp.min=min+t.min;
           temp.sec=sec+t.sec;
           return temp;
        }
};
class Matrix
{
   private:
       int a[3][3];
   public:
       void SetMatrix(int(*)[3]);
       void printMatrix();
       Matrix operator+(Matrix);
       Matrix operator-(Matrix);
       Matrix operator*(Matrix);
};
void Matrix::SetMatrix(int b[][3])
{
   int i,j;
   for(i=0;i<3;i++)
     for(j=0;j<3;j++)
        a[i][j]=b[i][j];
}
void Matrix::printMatrix()
{
   int i,j;
   for(i=0;i<3;i++)
   {
      for(j=0;j<3;j++)
        cout<<a[i][j]<<" ";
      cout<<endl;   
   }
}
Matrix Matrix::operator+(Matrix m)
{
   int i,j;
   Matrix temp;
   for(i=0;i<3;i++)
     for(j=0;j<3;j++)
        temp.a[i][j]=a[i][j]+m.a[i][j];
   return temp;     
}
Matrix Matrix::operator-(Matrix m)
{
   int i,j;
   Matrix temp;
   for(i=0;i<3;i++)
     for(j=0;j<3;j++)
        temp.a[i][j]=a[i][j]-m.a[i][j];
   return temp;     
}
Matrix Matrix::operator*(Matrix m)
{
   int i,j,k,c=0;
   Matrix temp;
   for(i=0;i<3;i++)
   {
      for(j=0;j<3;j++)
      {
        for(k=0,c=0;k<3;k++)
        {
            c+=a[i][k]*m.a[k][j];
        }
        temp.a[i][j]=c;
      }  
   }
   return temp;
};

class Number
{
   private:
      int x,y,z;
   public:
      void SetNumber(int a,int b,int c)   
      {
         x=a;
         y=b;
         z=c;
      }
      void ShowNumber()
      {
         cout<<x<<" "<<y<<" "<<z<<endl;
      }
      Number operator-()
      {
         Number temp;
         temp.x=-x;
         temp.y=-y;
         temp.z=-z;
         return temp;
      }
};
class Fraction
{
   private:
      long numerator;
      long denominator;
   public:
      Fraction(long n=0,long d=0):numerator(n),denominator(d)
      {}   
      void ShowFraction()
      {
         cout<<numerator<<"/"<<denominator<<"  ";
      }
      Fraction operator+(Fraction f)
      {
         Fraction temp;
         temp.numerator=numerator*f.denominator+f.numerator*denominator;
         temp.denominator=denominator*f.denominator;
         return temp;
      }
      bool operator<(Fraction f)
      {
          return numerator*f.denominator<f.numerator*denominator;   
      }
};
class Distance
{
   private:
       int km,m,cm;
   public:
       Distance(int km=0,int m=0,int cm=0):km(km),m(m),cm(cm)   
       { }
       void show_distance()
       {
         cout<<km<<" km "<<m<<" m "<<cm<<" cm "<<endl;
       }
       Distance operator+(Distance d)
       {
           Distance temp;
           temp.cm=cm+d.cm;
           temp.m=m+d.m+temp.cm/100;
           temp.cm%=60;
           temp.km=km+d.km+temp.m/1000;
           temp.m%=1000;
           return temp; 
       }
       Distance operator--(int)
       {
          if(cm>0)
           cm--;
          else
          {
            cm=99;
            if(m>0)
              m--;
            else
            {
               km=999;
               km--;
            }  
          }  
           return *this;
       }
       Distance operator--()
       {
           Distance temp=*this;
           if(cm>0)
           cm--;
          else
          {
            cm=99;
            if(m>0)
              m--;
            else
            {
               km=999;
               km--;
            }  
          }  
           return temp;
       }
       void normalize()
       {
         if(cm>=100)
         {
            m=m+cm/100;
            cm=cm%100;
         }
         if(m>=1000)
         {
            km=km+m/1000;
            m=m%1000;
         }
       }
};

class Array
{
   private:
       int *p;
       int size;
   public:
       Array(int a)    
       {
          size=a;
          p=new int[size];
       }
       int& operator[](int Index)
       {
          if(Index<0||Index>size)
             {
               cout<<"Invalied Index"; 
             } 
         else
           return p[Index];
       }
       void ShowArray(int Index)
       {
           if(Index<0||Index>=size)
               cout<<"Invalied Index";
          else 
               cout<<p[Index]<<" ";
       }
       ~Array()
       {
         delete p;
       }
};
