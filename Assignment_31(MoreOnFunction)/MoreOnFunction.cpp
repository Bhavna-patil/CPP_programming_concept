#include<iostream>
#include<string.h>
using namespace std;
/**Define a function to sort an integer array in descending or ascending order depending on
 bool type argument (true for ascending and false for descending).use default argument to
 implement it**/
void sort(int arr[],int size,bool a=true) 
{
    int i,j,round,temp;
    if(a)//ascending order
    {
        for(round=1;round<size;round++)
        {
            for(j=0;j<size-round;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
    }
    else //descending order
    {
        for(round=1;round<size;round++)
        {
            for(j=0;j<size-round;j++)
            {
                if(arr[j]<arr[j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
    }

}

/**2Define a function to sort an String array in descending or ascending order depending on
 bool type argument (true for ascending and false for descending).use default argument to
 implement it**/
void sort(char *str,bool a=true) 
{
    int i,j,round,l;
    char temp;
    l=strlen(str);
    if(a)//ascending order
    {
        for(round=1;round<l;round++)
        {
            for(j=0;j<l-round;j++)
            {
                if(str[j]>str[j+1])
                {
                    temp=str[j];
                    str[j]=str[j+1];
                    str[j+1]=temp;
                }
            }
        }
    }
    else //descending order
    {
        for(round=1;round<l;round++)
        {
            for(j=0;j<l-round;j++)
            {
                if(str[j]<str[j+1])
                {
                    temp=str[j];
                    str[j]=str[j+1];
                    str[j+1]=temp;
                }
            }
        }
    }

}

/**3Define a function to rotate an array by n position in d direction. implement position
and direction using default argument.Argumet d can be -1 or 1 denoting left or right direction
Argument n should be the last  argument with default value 1**/
void rotate(int a[],int size,int p=0,int d=1)
{
    int i=0,temp;
    if(d==-1)
    {
       while(p)
       {
          temp=a[0];
          for(i=0;i<size-1;i++)
            a[i]=a[i+1];
          a[size-1]=temp;
          p--;
       }
    }
    else
    {
        while(p)
        {
            temp=a[size-1];
            for(i=size-1;i>0;i--)
               a[i]=a[i-1];
            a[i]=temp;   
            p--;
        }
    }
}

//4 Lcm of three number
int LCM(int a,int b,int c)
{
    int i,k;
    k=a>b?a>c?a:b:b>c?b:c; 
    for(i=k;i<a*b*c;i++)
    {
        if(i%a==0&&i%b==0&&i%c==0)
           return i;
    }
    return a*b*c;
}

//5define a function to calculate all prime factore of a number
void prime_factore(int a)
{
    int i=2;
    while(a)
    {
        while(a%i==0)
        {
            a=a/i;
            cout<<i<<" ";
        }
        i++;
    }
}
//6define a function to calculate HCF of two number
int HCF(int a,int b)
{
    int i;
    for(i=a/2;i>=1;i--)
    {
        if(a%i==0&&b%i==0)
           return i;
    }
}
//7define a overloaded function to calculate volumn of cuboid,cone,sphere;
int volume(int l,int b,int h)
{
    return l*b*h;
}
double volume(int r,int h)
{
    return 3.141*r*r*h/3;
}
double volume(int r)
{
    return 4*3.141*r*r*r/3;
}

/**8Define function to print substring from startindex(inclusive) to endindex(exclusive).
 Define function in such a way if the second argument is not provided ,string will print 
 till the last index**/

void print_substring(char *str,int startindex,int endindex=0)
{
    int i,l;
    l=strlen(str);
    if(endindex==-1)
      endindex=l;
    if(startindex>0&&endindex<=l&&startindex<endindex)
        for(i=startindex;i<endindex;i++)   
          cout<<str[i];
    else
          cout<<"Invalid index";
}
//9Define a function to swap two arrays
void swap_array(int a[],int size,int b[])
{
    int i,temp;
    for(i=0;i<size;i++)
       {
          temp=a[i];
          a[i]=b[i];
          b[i]=temp;
       }      
}

//10Define a function to merge two sorted array of same size
void merge(int a[],int b[],int size,int result[])
{
   int i,j,k;
   for(i=0,j=0,k=0;i<size&&j<size;k++)
   {
      if(a[i]<b[j])
      {
        result[k]=a[i];
        i++;
      }
      else
      {
        result[k]=b[j];
        j++;
      }
   }
   while(i<size)
   {
     result[k]=a[i];
     k++;
     i++;
   }
   while(j<size)
   {
     result[k]=b[j];
     j++;
     k++;
   }
}
int main()
{
    int a[]={1,2,3,14,15},b[]={6,7,8,19,200},i,result[10];
    merge(a,b,5,result);
   for(i=0;i<10;i++)
       cout<<result[i]<<" ";   
    return 0;
}
