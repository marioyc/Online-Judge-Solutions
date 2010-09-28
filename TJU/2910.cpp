#include <cstdio>
#include <cmath>

using namespace std;

int h,w;

double V1(double r){
    return M_PI*r*r*w;
}

double V2(double r){
    return M_PI*r*r*(h-2*r);
}

int main(){
    double ans;
    
    while(true){
        scanf("%d %d",&w,&h);
        if(w==0) break;
        
        ans = fmax(V1(fmin(h/(2*M_PI+2),w/2.0)),V2(w/(2*M_PI)));
        printf("%.3lf\n",ans);
    }
    
    return 0;
}
