#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
double T,x[10000],tmpX[10000];

bool test1(double D){
    tmpX[0] = max(0.0,x[0]-D);
    
    for(int i = 1;i<N;++i){
        if(x[i]-tmpX[i-1]>=T) tmpX[i] = max(tmpX[i-1]+T,x[i]-D);
        else{
            if(x[i]+D-tmpX[i-1]<T) return false;
            tmpX[i] = tmpX[i-1]+T;
        }
    }
    
    return true;
}


bool test2(double D){
    tmpX[N-1] = x[N-1]-D;
    
    for(int i = N-2;i>=0;--i){
        if(tmpX[i+1]-x[i]>=T) tmpX[i] = min(tmpX[i+1]-T,x[i]+D);
        else{
            if(tmpX[i+1]-x[i]+D<T) return false;
            tmpX[i] = tmpX[i+1]-T;
        }
    }
    
    if(tmpX[0]<0) return false;
    
    return true;
}

int main(){
    int TC;
    scanf("%d",&TC);
    
    while(TC--){
        scanf("%d %lf",&N,&T);
        
        for(int i = 0;i<N;++i)
            scanf("%lf",&x[i]);
        
        double lo = 0,hi = 0,mi;
        
        for(int i = 0;i<N;++i)
            hi = max(hi,abs(x[i]-i*T));
        
        for(int it = 0;it<40;++it){
            mi = (lo+hi)/2;
            
            if(!test1(mi) && !test2(mi)) lo = mi;
            else hi = mi;
        }
        
        printf("%.4f\n",hi);
    }
    
    return 0;
}
