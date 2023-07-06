#include<iostream>
#include<math.h>
using namespace std;
int Is_prime(int a)
{
    int i;
    for(i=2;i<=a/2;i++)
        if(a%i==0)
        return 0;
    if(i=a/2+1)    
       return 1;   
}

int find_highest_digit(int a)
{
    int h=0;
    while(a)
    {
       if(h<a%10)
       h=a%10;
       a=a/10;
    }
    return h;
}

int calculate_X_to_power_Y(int x,int y)
{
    int p;
    if(y==1)
      return x;
    p=calculate_X_to_power_Y(x,y-1)*x;  
    return p;
}

int fact(int a)
{
    int i,fact=1;
    for(i=1;i<=a;i++)
     fact*=i;
    return fact;
}

int combi(int n,int r)
{
    return fact(n)/(fact(r)*fact(n-r));
}

void print_pascale_triangle(int line)
{
    int i,j,k=1,l;
    for(i=0;i<line;i++)
    {
        l=0,k=1;
        for(j=0;j<=2*line-1;j++)
        {
             if(j>=line-i&&j<=line+i&&k)
             {
               cout<<combi(i,l);
               l++;
               k=0;
             }
             else
             {
                cout<<" ";
                k=1;
             }
        }
        cout<<endl;
    }
}

int Is_term_in_fibonacci_series(int num) 
{
    int a=-1,b=1,c=0;
    while(c<num)
    {
       c=a+b;
       if(num==c)
         return 1;
       a=b;
       b=c;
    }
    return 0;  
}

void swap(int &a,int &b)
{
    a=a+b;
    b=a-b;
    a=a-b;
}

int add(int a,int b,int c=0)
{
    return a+b+c;
}

//overloaded function to area of circle,triangle,rectangle
float area(float r)
{
    return 3.141*r*r;
}
int area(int l,int b)
{
    return l*b;
}
double area(int a,int b,int c)
{
  double s;
  s=(a+b+c)/2.0;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}

/**define a function using function overloading to find maximum of two num & both the num
   can be integer or real;**/
int max(int a,int b)  
{
    return a>b?a:b;
}
double max(double a,double b)
{
    return a>b?a:b;
}

//define a function using function overloading to add two num having diff data type
double add(int a,double b)
{
    return a+b;
}
double add(double a,int b)
{
    return a+b;
}
int main()
{
    int x;
    float y;
    cout<<"Enter two num";
    cin>>x>>y;
    cout<<"sum is "<<add(y,x);
    return 0; 
}