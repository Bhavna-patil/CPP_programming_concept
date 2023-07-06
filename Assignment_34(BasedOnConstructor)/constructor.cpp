#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class Cuboid
{
    private:
        int l,b,h;
    public:
        Cuboid():l(0),b(0),h(0)//default constructor
        {}
        Cuboid(int a,int b,int c):l(a),b(b),h(c)//parameterised constructor
        {}    
        void Setside(int x,int y,int z) 
        {
           l=x;
           b=y;
           h=z;
        }
};
class Customer
{
    private:
        int cust_id;
        char email[30];
        long int mobile;
    public:
        Customer()    
        {
            cust_id=0;
            strcpy(email,"xyzExample@ gmail.com");
            mobile=0;
        }
        Customer(int a,char *e,long int m)
        {
            cust_id=a;
            strcpy(email,e);
            mobile=m;
        }
};
class Time
{
    private:
        int hr,min,sec;
    public:
        Time():hr(0),min(0),sec(0)
        {}
        Time(int a,int b,int c): hr(a),min(b),sec(c)  
        {}
};
class Book
{
    private:
        int book_id;
        char title[20];
        float price;
    public:
        Book():book_id(0),title("null"),price(0.00)    
        {}
        Book(int a,char str[],float p) 
        {
            book_id=a;
            strcpy(title,str);
            price=p;
        }
};
class Complex
{
    private:
        int a,b;
    public:
        Complex(int x,int y)
        {
           a=x;
           b=y;
        }
        void ShowData()
        {
            cout<<a<<"+"<<b<<"i"<<endl;
        }
};
void Example()
{
    Complex c[5]={Complex(2,4),Complex(9,0),Complex(8,9),Complex(3,4),Complex(1,8)};
    int i;
    for(i=0;i<5;i++)
       c[i].ShowData();
}
class Number
{
    private:
        int size;
        int *arr;
    public:
        Number(int s)    
        {
            size=s;
            arr=(int*)calloc(size,sizeof(int));
        }
        Number(Number &n)
        {
            size=n.size;
            arr=(int*)calloc(size,sizeof(int));
            int i;
            for(i=0;i<size;i++)
               arr[i]=n.arr[i];
        }
        ~Number()
        {
            delete []arr;
        }
};
class Student
{
    private:
         int roll_no;
         char name[20];
    public:
        Student()    
        {
            cout<<"Enter student roll no and name"<<endl;
            cin>>roll_no;
            cin.ignore();
            cin.getline(name,20);
        }
        void ShowDetails()
        {
            cout<<roll_no<<"   "<<name<<endl;
        }

};
class Date
{
    private:
        int d,m,y;
    public:
        Date(int a,int b,int c):d(a),m(b),y(c)
        {}   
        Date():d(0),m(0),y(0)
        {} 
};
class Room
{
    private:
        int room_no;
        char room_type[20];
        bool is_Ac;
        float price;
    public:
        Room()
        {
            room_no=-1;
            strcpy(room_type,"None");
            is_Ac=false;
            price=0.00;
        }
        Room(int a,char str[],bool l,float p)
        {
            room_no=a;
            strcpy(room_type,str);
            is_Ac=l;
            price=p;
        }
};
class Circle
{
    private:
        int radius;
    public:
        Circle(int a):radius(a)
        {}   
        Circle():radius(0)
        {}
};
int main() 
{
    Student s1,s2;
    s1.ShowDetails();
    s2.ShowDetails();
    return 0;
}