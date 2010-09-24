#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int T,p,q,r,s,t,u;
    double lo,hi,mi,f;
    
    while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)==6){
        if(p*exp(-1)+q*sin(1)+r*cos(1)+s*tan(1)+t+u>1e-9 || p+r+u<0){
            printf("No solution\n");
            continue;
        }
        
        lo=0.0; hi=1.0;
        
        for(int i=0;i<30;i++){
            mi=(lo+hi)/2;
            
            f=p*exp(-mi)+q*sin(mi)+r*cos(mi)+s*tan(mi)+t*mi*mi+u;
            
            if(f>0) lo=mi;
            else hi=mi;
        }
        
        printf("%.4f\n",lo);
    }
    
    return 0;
}
