#include<iostream>
using namespace std;
//1
class Complex
{
    private:
       int a,b;
    public:
      void setData(int x,int y) {a=x;b=y;}
      void showData() {cout<<a<<"+"<<b<<"i"<<endl;}
      Complex add(Complex C)
      {
        Complex temp;
        temp.a=a+C.a;
        temp.b=b+C.b;
        return temp;
      }
      Complex substract(Complex C)
      {
        Complex temp;
        temp.a=a-C.a;
        temp.b=b-C.b;
        return temp;
      }
     Complex multiply(Complex C)
     {
        Complex temp;
        temp.a=a*C.a-b*C.b;
        temp.b=a*C.b-b*C.a;
        return temp;
     }
};
class Time
{
    private:
           int hr,min,sec;
    public:
          void settime(int a,int b,int c) {hr=a;min=b;sec=c;}
          void showtime()  { cout<<hr<<" hr "<<min<<" min "<<sec<<" sec "<<endl;}
          void normalize()
          {
                min=min+sec/60;
                sec=sec%60;
                hr=hr+min/60;
                min=min%60;
          }
          Time add(Time t)
          {
            Time temp;
            temp.hr=hr+t.hr;
            temp.min=min+t.min;
            temp.sec=sec+t.sec;
            return temp;
          }
          bool is_greater(Time t)
          {
             if(hr>t.hr)
                return false;
             else if(min>t.min)   
                return false;
             else if(sec>t.sec)   
                return false;
             else 
                return true;   
          }
};

class TestResult
{
    private:
         int roll_no,right,wrong,net_score;
         static int right_weightage,wrong_weightage;
    public:
         void set_rollno(int a){roll_no=a;}
         void set_right(int a){right=a;}
         void set_wrong(int a){wrong=a;}
         void set_net_score(int n){net_score=n;}
         int get_rollno(){return roll_no;}
         int get_right(){return right;}
         int get_wrong(){return wrong;}
         int get_net_score(){return net_score;}
         static void set_right_weightage(int w){right_weightage=w;}
         static void set_wrong_weightage(int r){wrong_weightage=r;}
         static int get_right_weightage(){return right_weightage;}
         static int get_wrong_weightage(){return wrong_weightage;}
};
int TestResult::right_weightage=1;
int TestResult::wrong_weightage=1;
void SetTestResult(TestResult *t,int a,int b,int c)
{
   t->set_rollno(a);
   t->set_right(b);
   t->set_wrong(c);
   t->set_net_score(b*t->get_right_weightage()-c*t->get_wrong_weightage());
}
void PrintTestResult(TestResult t)
{
   cout<<t.get_rollno()<<" "<<t.get_net_score()<<endl;
}
void sort_by_netscore(TestResult *t,int size)
{
   int round,j;
   TestResult temp;
   for(round=1;round<size;round++)
   {
      for(j=0;j<size-round;j++)
      {
         if((t+j)->get_net_score()>(t+j+1)->get_net_score())
         {
             temp=t[j];
             t[j]=t[j+1];
             t[j+1]=temp;
         }
      }
   }
}
class Matrix
{
   private:
       int a[3][3];
   public:
       void SetMatrix(int(*)[3]);
       void printMatrix();
       Matrix add(Matrix);
       Matrix substract(Matrix);
       Matrix multiply(Matrix);
       Matrix transpose();
       bool is_singular();

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
Matrix Matrix::add(Matrix m)
{
   int i,j;
   Matrix temp;
   for(i=0;i<3;i++)
     for(j=0;j<3;j++)
        temp.a[i][j]=a[i][j]+m.a[i][j];
   return temp;     
}
Matrix Matrix::substract(Matrix m)
{
   int i,j;
   Matrix temp;
   for(i=0;i<3;i++)
     for(j=0;j<3;j++)
        temp.a[i][j]=a[i][j]-m.a[i][j];
   return temp;     
}
Matrix Matrix::multiply(Matrix m)
{
   int i,j,k,c=0;
   Matrix temp;
   for(i=0;i<3;i++)
   {
      for(j=0;j<3;j++)
      {
        for(k=0;k<3;k++)
        {
            c+=a[i][k]*m.a[k][j];
        }
        temp.a[i][j]=c;
      }  
   }
   return temp;
}
Matrix Matrix::transpose()
{
   int i,j;
   Matrix temp;
   for(i=0;i<3;i++)
   {
     for(j=0;j<3;j++)
     {
        temp.a[i][j]=a[j][i];
     }
   }
   return temp;
}

bool Matrix::is_singular()
{
   int i,j,k;
   if(a[0][0]==1&&a[1][1]==1&&a[1][1]==1)
      k=1;
   else
      return false;   
   for(i=0;i<3;i++)
   {
      for(j=0;j<3;j++)
      {
         if(i!=j)
         {
           if(a[i][j]&k)
             return false;
         }
      }
   }
   return true;
}
int main()
{  int a[3][3]={{1,56,0},{4,1,7},{9,8,6}};
   Matrix m1,m2;
   m1.SetMatrix(a);
   m1.printMatrix(); 
   m2=m1.transpose();
   m2.printMatrix();
   if(m2.is_singular())
     cout<<"Single";
   else
     cout<<"not Singular";  
    return 0;
}