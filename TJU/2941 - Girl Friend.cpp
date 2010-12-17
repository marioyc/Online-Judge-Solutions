#include <cstdio>
#include <algorithm>

using namespace std;

int N,P[100000],V[100000];
double memo[100000];

double solve(int n){
    if(n==N) return 0;
    
    double &ret = memo[n];
    
    if(ret<-0.5) ret = max(solve(n+1),(P[n]*V[n]+(100-P[n])*solve(n+1))/100);
    
    return ret;
}

int main(){
    while(true){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i = 0;i<N;++i)
            scanf("%d %d",&P[i],&V[i]);
        
        for(int i = 0;i<N;++i) memo[i] = -1.0;
        printf("%.2lf\n",solve(0));
    }
    
    return 0;
}
