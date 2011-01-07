#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double x,y,v;

double solve(double t2){
    if(t2<0) return -1;
    double t = sqrt(t2);
    return acos(x/(v*t));
}

int main(){
    int T;
    double g = 9.8,A = g*g/4,B,C,disc;
    
    cin>>T;
    
    while(T--){
        cin>>x>>y>>v;
        
        if(x<1e-9 && y<1e-9){
            puts("0.000000");
            continue;
        }
        
        B = y*g-v*v;
        C = x*x+y*y;
        disc = B*B-4*A*C;
        
        if(B*B-4*A*C<0) puts("-1");
        else{
            double ret1 = solve((-B+sqrt(disc))/(2*A));
            double ret2 = solve((-B-sqrt(disc))/(2*A));
            
            if(ret1<-0.5 && ret2<-0.5) puts("-1");
            else if(ret1<-0.5) printf("%.6f\n",round(ret2*1e6)/1e6);
            else if(ret2<-0.5) printf("%.6f\n",round(ret1*1e6)/1e6);
            else printf("%.6f\n",round(min(ret1,ret2)*1e6)/1e6);
        }
    }
    
    return 0;
}
