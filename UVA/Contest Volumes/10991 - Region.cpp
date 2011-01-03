#include<iostream>
#include<cmath>

#define PI acos(-1)

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int k;
    double r1,r2,r3,S,a,b,c,G,x,y,z;
    
    cin>>k;
    
    for(int i=0;i<k;i++){
        cin>>r1>>r2>>r3;
        
        S=sqrt((r1+r2+r3)*r1*r2*r3);
        
        x=asin(2/((r1+r2)*(r1+r3))*S);
        y=asin(2/((r2+r3)*(r2+r1))*S);
        z=asin(2/((r3+r1)*(r3+r2))*S);
        
        
        a=r2+r3;
        b=r3+r1;
        c=r1+r2;
        
        if(a*a>b*b+c*c) x=PI-x;
        else if(b*b>c*c+a*a) y=PI-y;
        else if(c*c>a*a+b*b) z=PI-z;
        
        G=S-r1*r1*x/2-r2*r2*y/2-r3*r3*z/2;        
        
        printf("%.6f\n",G);
    }
}
