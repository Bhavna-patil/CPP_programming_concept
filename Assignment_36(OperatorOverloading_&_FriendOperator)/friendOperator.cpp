#include<iostream>
#include<string.h>
using namespace std;
class Complex
{
    private:
       int real,img;
    public:
       void SetData(int a,int b)
       {
          real=a;img=b;
       }
       void ShowData()
       {
        cout<<real<<"+"<<img<<"i"<<endl;
       }
       friend Complex operator+(Complex,Complex);
       friend Complex operator-(Complex,Complex);
       friend Complex operator*(Complex,Complex);
       friend Complex operator-(Complex);
};
Complex operator+(Complex c1,Complex c2)
{
    Complex temp;
    temp.real=c1.real+c2.real;
    temp.img=c1.img+c2.img;
    return temp;
}
Complex operator-(Complex c1,Complex c2)
{
    Complex temp;
    temp.real=c1.real-c2.real;
    temp.img=c1.img-c2.img;
    return temp;
}
Complex operator*(Complex c1,Complex c2)
{
    Complex temp;
    temp.real=c1.real*c2.real;
    temp.img=c1.img*c2.img;
    return temp;
}
Complex operator-(Complex C)
{
    Complex temp;
    temp.real=-C.real;
    temp.img=-C.img;
    return temp;
}
//2
class Time
{
    private:
        int hr,min,sec;
    public:
       void SetTime(int a,int b,int c)    
       {
          hr=a;min=b;sec=c;
       }
       void ShowTime()
       {
          cout<<hr<<" hr "<<min<<" min "<<sec<<" sec ";
       }
       void operator=(Time);
       friend ostream& operator<<(ostream&,Time);
       friend istream& operator>>(istream&,Time&);
};
void Time::operator=(Time t)
{
    hr=t.hr;
    min=t.min;
    sec=t.sec;
}
ostream& operator<<(ostream &out,Time t)
{
    out<<t.hr<<" hr "<<t.min<<" min "<<t.sec<<" sec ";
    return out;
}
istream& operator>>(istream &in,Time &t)
{
    in>>t.hr>>t.min>>t.sec;
    return in;
}

class Array
{
    private:
       int *p;
       int size;
    public:
       Array(Array &a)  
       {
          size=a.size;
          p=new int[size];
          int i;
          for(i=0;i<size;i++)
            p[i]=a.p[i];
       }
       Array(int a):size(a)
       {
           p=new int[size];
       }
       void input()
       {
          int i;
          for(i=0;i<size;i++)
             cin>>p[i];
       }
       void print()
       {
          int i;
          for(i=0;i<size;i++)
             cout<<p[i]<<" ";
       }
       void operator=(Array a)  
       {
          delete []p;
          size=a.size;
          p=new int[size];
          int i;
          for(i=0;i<size;i++)
            p[i]=a.p[i];
       }
       friend Array operator+(Array arr1,Array arr2);
       ~Array()
       {
          delete []p;
       }
};
Array operator+(Array a1,Array a2)
{
    int i=0,k=0;
    Array temp(a1.size+a2.size);
       for(i=0;i<temp.size;i++)
       {
          if(i<a1.size)
          {
             temp.p[i]=a1.p[k];
             k++;
          }
          else
          {
            if(i==a1.size)
              k=0;
            temp.p[i]=a2.p[k];
            k++;
          }
       }
       return temp;
}

//**************** 7*****************
class Integer
{
    private:
       int a;
    public:
       void SetInteger(int x){a=x;}
       void ShowData(){cout<<a;}
       friend bool operator!(Integer);
       friend bool operator==(Integer,Integer);   
};
bool operator!(Integer n)
{
   if(n.a!=0)
     return false;
   return true;  
}
bool operator==(Integer x,Integer y)
{
    if(x.a==y.a)
        return true;
    return false;    
}

//**************** 8 ****************
class Coordinate
{
   private:
      int X,Y;
   public:
      void SetCoordinate(int a,int b){X=a,Y=b;}
      void ShowCoordinate(){cout<<"X="<<X<<" Y="<<Y;}
      Coordinate operator,(Coordinate c){ return c; }
      friend istream& operator>>(istream&,Coordinate&);    
      friend ostream& operator<<(ostream&,Coordinate);
};

istream& operator>>(istream &in,Coordinate &c)
{
    in>>c.X>>c.Y;
    return in;
}
ostream& operator<<(ostream &out,Coordinate c)
{
    cout<<"X="<<c.X<<" Y="<<c.Y<<endl;
    return out;
}

//************************* 10 **************************
class Student
{
    private:
        int roll_no;
        char name[20];
        int age;
    public:
        void SetStudent(int a,char s[],int b)    
        {
            roll_no=a;
            strcpy(name,s);
            age=b;
        }
        void ShowStudent()
        {
            cout<<roll_no<<" "<<name<<" "<<age<<endl;
        }
        bool operator==(Student s)
        {
            if(roll_no==s.roll_no&&!(strcmp(name,s.name))&&age==s.age)
                return true;
            return false;    
        }
};
int main()
{
    Student s1,s2;
    s1.SetStudent(1,"bhavna",20);
    s2.SetStudent(1,"bhavna",20);
    if(s1==s2)
    cout<<"True";
    else cout<<"False";
    return 0;
}