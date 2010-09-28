#include <iostream>
#include <iomanip>
#include <cmath>

#define PI 3.141592653589793

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    double x1,y1,x2,y2,x3,y3;
    double a,b,c,S,R;
    
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3){
        a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
        
        S=0.5*fabs(x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1);
        
        R=a*b*c/(4*S);
        
        cout<<fixed<<setprecision(2)<<2*PI*R<<endl;
    }

    return 0;
}
