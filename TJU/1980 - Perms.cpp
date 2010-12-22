#include <cstdio>

using namespace std;

double memo[19][201];

double solve(int n, int inv){
    if(inv<0) return 0;
    if(n==0) return (inv==0? 1 : 0);
    
    double &ret = memo[n][inv];
    
    if(ret<-0.5){
        ret = 0;
        
        for(int i = 0;i<n;++i)
            ret += solve(n-1,inv-i);
    }
    
    return ret;
}

int main(){
    for(int i = 0;i<=18;++i)
        for(int j = 0;j<=200;++j)
            memo[i][j] = -1;
    
    int n,k;
    
    while(true){
        scanf("%d %d",&n,&k);
        if(n==0) break;
        
        printf("%.0f\n",solve(n,k));
    }
    
    return 0;
}
