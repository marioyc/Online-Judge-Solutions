#include <cstdio>
#include <cstring>

using namespace std;

long double memo[101][101];

long double solve(int n, int m){
    if(m<0) return 0;
    if(n==0){
        if(m==0) return 1;
        return 0;
    }
    
    long double &ret = memo[n][m];
    if(ret>-0.5) return ret;
    
    ret = 0;
    
    for(int i = 1;i<=6;++i)
        ret += solve(n-1,m-i)/6;
    
    return ret;
}

int main(){
    int T,n,m;
    scanf("%d",&T);
    
    memset(memo,-1,sizeof(memo));
    
    while(T--){
        scanf("%d %d",&n,&m);
        printf("%.2Lf\n",solve(n,m));
    }
    
    return 0;
}
