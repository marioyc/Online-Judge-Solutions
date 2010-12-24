#include <cstdio>
#include <algorithm>

using namespace std;

int n,a[101],r;
double b,v,e,f,memo[101];

double solve(int cur){
    double &ret = memo[cur];
    
    if(ret<-0.5){
        ret = 1e9;
        double t = 0;
        
        for(int i = 0,j = cur+1;i<a[n]-a[cur];++i){
            if(i==a[j]-a[cur]) ret = min(ret,t+b+solve(j++));
            
            if(i>=r) t += 1.0/(v-e*(i-r));
            else t += 1.0/(v-f*(r-i));
        }
        
        ret = min(ret,t);
    }
    
    return ret;
}

int main(){
    a[0] = 0;
    
    while(true){
        scanf("%d",&n);
        if(n==0) break;
        
        for(int i = 1;i<=n;++i)
            scanf("%d",&a[i]);
        
        scanf("%lf",&b);
        scanf("%d %lf %lf %lf",&r,&v,&e,&f);
        
        for(int i = 0;i<=n;++i) memo[i] = -1;
        printf("%.4f\n",solve(0));
    }
    
    return 0;
}
