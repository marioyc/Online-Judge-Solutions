#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

double eps = 1e-7;
double x[10000],h[10000],A[10000];

int main(){
    int T,N;
    double w,d,target;
    bool first = true;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        double total = 0;
        
        for(int i = 0;i < N;++i){
            scanf("%lf %lf %lf %lf",&x[i],&h[i],&w,&d);
            total += h[i] * w * d;
            A[i] = w * d;
        }
        
        scanf("%lf",&target);
        
        if(!first) puts("");
        first = false;
        
        if(total < target - eps) puts("OVERFLOW");
        else{
            double lo = 0,hi = 1e4,mi;
            
            for(int it = 0;it < 21;++it){
                mi = (lo + hi) / 2;
                
                double aux = 0;
                
                for(int i = 0;i < N;++i)
                    aux += min(max(0.0,mi - x[i]),h[i]) * A[i];
                
                if(aux > target) hi = mi;
                else lo = mi;
            }
            
            printf("%.2f\n",lo);
        }
    }
    
    return 0;
}
