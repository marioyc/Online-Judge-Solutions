#include <iostream>
#include <cmath>
#include <iomanip>

#define EPSILON 1e-8

using namespace std;

struct line{
    
    double a;
    double b;
    double c;
    
    line(double x1,double y1,double x2, double y2)
    {
        if(fabs(x1-x2)<=EPSILON)
        {
            a=1;
            b=0;
            c=-x1;
        }else{
            b=1;
            a=-(y1-y2)/(x1-x2);
            c=-(a*x1)-y1;
        }
    }
    
};

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N;
    scanf("%d", &N);
    
    double x1,y1,x2,y2,r;//centro del pilar siempre en el origen
    
    double d1,d2;//medidas de los segmentos tangentes
    
    double a,b,x;//x:angulo necesario para hallar la medida del arco
    
    double m1,m2,m3;
    
    double tot;
    
    for(int i=0;i<N;i++)
    {
                
        cin>>x1>>y1>>x2>>y2>>r;
        
        line l=line(x1,y1,x2,y2);
        
        d1=fabs(l.c/sqrt(pow(l.a,2)+pow(l.b,2)));
        
        m1=pow(x1,2)+pow(y1,2);
        m2=pow(x2,2)+pow(y2,2);   
        m3=pow(x1-x2,2)+pow(y1-y2,2);
        
        if((d1-r>EPSILON)||((d1-r<=EPSILON) && m1>r && m2>r)){
            cout<<fixed<<setprecision(3)<<sqrt(m3)<<endl;
        }else{       
        
            d1=sqrt(m1-pow(r,2));
            d2=sqrt(m2-pow(r,2));
        
            a=atan(d1/r);
            b=atan(d2/r);
        
            x=acos((m1+m2-m3)/(2*sqrt(m1)*sqrt(m2)))-a-b;
        
            tot=d1+d2+x*r;
            cout<<fixed<<setprecision(3)<<tot<<endl;
        }
    }
    
    return 0;
}
