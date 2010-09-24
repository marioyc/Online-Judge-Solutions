#include <iostream>
#include <cmath>
#include <iomanip>

#define PI 3.14159265358979323846

using namespace std;

int main(){
    
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t;
    double x1,y1,x2,y2,x3,y3;
    double a,b,c,S,R;
    double m,n,p;
    double e1,e2;
    int N;
    
    cin>>t;
    
    for(int i=0;i<t;i++){
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        
        S=fabs(x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3)*0.5;
        a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
        
        R=a*b*c/(4*S);
        
        m=2*asin(a/(2*R));
        n=2*asin(b/(2*R));
        p=2*asin(c/(2*R));        
        
        for(int j=3;j<201;j++){
            e1=m*j/(2*PI);
            e2=n*j/(2*PI);
            
            e1-=round(e1);
            e2-=round(e2);
            
            if(fabs(e1)<1e-5 && fabs(e2)<1e-5){
                cout<<j<<endl;
                break;
            }
        }
    }

    return 0;
}
