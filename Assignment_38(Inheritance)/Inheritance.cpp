#include<iostream>
#include<string.h>
using namespace std;
class person
{
    private:
        char name[20];
        int age;
    protected:
         void setName(char *s) {strcpy(name,s);}
         void setAge(int a) {age=a;}
         char* getName() {  return name;}
         int getAge()  {return age;}
    public:
         void showperson()     
         {
            cout<<name<<" "<<age;
         }
};

class Employee:public person
{
    private:
        float salary;
    public:
        void setEmployee(char *s,int a,float s1)   
        {
             setName(s);
             setAge(a);
             salary=s1;
        }
        void ShowEmployee()
        {
            cout<<getName()<<" "<<getAge()<<" "<<salary<<endl;
        }
        virtual void f1()
        {cout<<"employee f1";}
};
//**************************** 2 ****************************

class Circle
{
    private:
        int radius;
    public:
        void setRadius(int a) {radius=a;}   
        int getRadius() {return radius;}
        virtual float getArea() {return 3.141*radius*radius;}
};
class ThickCircle:public Circle
{
    private:
        int thickness;
    public:
        void setThickness(int a){thickness=a;}    
        int getThickness(){return thickness;}
        float getArea()
        {
            float a;
            a=thickness/2.0;
            return 3.141*a*a;
        }
};
//*************************** 3 ******************************
class Coordinate
{
    private:
       int x,y;
    public:
    Coordinate(int a,int b){x=a,y=b;}
    Coordinate(){x=0,y=0;}
    void setCoordinateX(int a){x=a;}
    void setCoordinateY(int b){y=b;}
    int getCoordinateX(){return x;}
    int getCoordinateY(){return y;}
    Coordinate getDistance() {return *this;}//distance from origin 
    virtual Coordinate getDistance(Coordinate c)//distance b/w two coordinate
    {
       Coordinate temp;
          temp.x=x-c.x;
          temp.y=y-c.y;
          return temp;
    }
};
class Shape
{
    private:
       char shapename[20];
    public:
       void setShapename(char *str){strcpy(shapename,str);}   
       char* getShapename() {return shapename;}
};
//********************************* 5 ***********************
class StraightLine:public Shape,public Coordinate
{
    private:
       Coordinate c1,c2;
    public:
       void setLine(Coordinate a,Coordinate b){c1=a,c2=b;}   
       Coordinate getDistance(Coordinate a,Coordinate b)//distance b/w two coordinate
      {
          Coordinate temp;
          temp.setCoordinateX(a.getCoordinateX()-b.getCoordinateX());
          temp.setCoordinateY(a.getCoordinateY()-b.getCoordinateY());
          return temp;
      }
      void showLine()
      {
         cout<<"("<<c1.getCoordinateX()<<","<<c1.getCoordinateY()<<")";
         cout<<"("<<c2.getCoordinateX()<<","<<c2.getCoordinateY()<<")";
      }
};
//******************************** 6 **********************
class Game
{
    private:
        int a[5];
    public:
        void SetScore(int round,int score)
        {
           if(round<5&&round>0)
              a[round-1]=score;
           else  
              cout<<"Invalied round Number";
        }
        int getScore(int round)
        {
            return a[round-1];
        }
};

class GameResult:public Game
{
    private:
       int gmrslt[5];
    public:
       void setResult(int round,int a)   
       {
          if(a==1||a==2||a==3)
            gmrslt[round-1]=a;
          else
             cout<<"Invalied Result";  
       }
       int getResult(int round)
       {
        return round;
       }
       void FinalResult();
};

void GameResult::FinalResult()
{
    int i,win=0,lose=0,draw=0,result;
    for(i=0;i<5;i++)
       {
         if(gmrslt[i]==2)
             win++;
         else if(gmrslt[i]==1)    
             lose++;
         else
             draw++;    
       }
    result=win>lose?win>draw?win:draw:lose>draw?lose:draw;
    if(result==win)  
          cout<<"Winner";
    else if(result==draw)      
          cout<<"Game Draw";
    else
          cout<<"Loserrr";      
}
//************************** 8 *************
class Actor
{
    private:
       char name[20];
       int age;
    public:
        void setName(char *str) {strcpy(name,str);}  
        void setAge(int a)  {age=a;}
        char* getName() {return name;}
        int getAge() {return age;}
};
class TvActor:virtual public Actor
{
    private:
        int p_done,p_running;
    public:
        void setDoneProject(int x){p_done=x;}
        void setRunningProject(int y){p_running=y;}
        int getDoneProject() {return p_done;}
        int getRunningProject() {return p_running;}
        void SetTvActor(char *str,int a,int x,int y)    
        {
            setName(str);
            setAge(a);
            p_done=x;
            p_running=y;
        }
        void ShowTvActor()
        {
            cout<<getName()<<" "<<getAge()<<"Done Project="<<p_done<<" Running Project="<<p_running;
        }

};
class MovieActor:virtual public Actor
{
    private:
        int mv_done,mv_running;
    public:
        void setDoneMovie(int x){mv_done=x;}
        void setRunningMovie(int y){mv_running=y;}
        int getDoneMovie() {return mv_done;}
        int getRunningMovie() {return mv_running;} 
        void SetMovieActor(char *str,int a,int x,int y)    
        {
            setName(str);
            setAge(a);
            mv_done=x;
            mv_running=y;
        } 
        void ShowMovieActor()
        {
            cout<<getName()<<" "<<getAge()<<"Done Movie="<<mv_done<<" Running Movie="<<mv_running;
        }  
};
class AllScreenActor:public TvActor,public MovieActor
{
    public:
       void setActorData(char *str,int a)
       {
          setName(str);
          setAge(a);
       }
       void ShowActorData()
       {
         cout<<getName()<<" "<<getAge();
       }
          
};
int main()
{
    AllScreenActor a1;
    a1.setActorData("Bhavna",20);
    a1.ShowActorData();
    return 0;
  
}