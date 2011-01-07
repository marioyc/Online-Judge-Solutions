#include <cstdio>
#include <cstring>

using namespace std;

int memo[1001][1001];

int solve(int k, int n){
    if(k==1 || n==0) return 1;
    
    int &ret = memo[k][n];
    
    if(ret==-1){
        ret = solve(k-1,n);
        if(n>=k) ret += solve(k,n-k);
        if(ret>10009) ret -= 10009;
    }
    
    return ret;
}

int main(){
    int T,N,K;
    
    scanf("%d",&T);
    
    memset(memo,-1,sizeof(memo));
    
    while(T--){
        scanf("%d %d",&N,&K);
        
        if(N<K) printf("0\n");
        else printf("%d\n",solve(K,N-K));
    }
    
    return 0;
}
