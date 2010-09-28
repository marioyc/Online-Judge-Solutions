#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int T,lo,hi,mi;
    double r,R,H,V,PI=M_PI,h,v;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%lf %lf %lf %lf",&r,&R,&H,&V);
        
        if(V>=PI*H*(R*R+R*r+r*r)/3) printf("%.6f\n",H);
        else{
            lo=0;hi=H*1000000;
            
            while(lo!=hi){
                mi=(lo+hi+1)/2;
                h=(double)mi/1000000;
                
                v=PI*(r*r*h+r*(R-r)*h*h/H+(R-r)*(R-r)*h*h*h/(3*H*H));
                
                if(v>V) hi=mi-1;
                else lo=mi;
            }
            
            printf("%.6f\n",(double)lo/1000000);
        }
    }
    
    return 0;
}
