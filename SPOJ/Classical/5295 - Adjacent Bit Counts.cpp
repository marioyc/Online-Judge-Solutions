#include <cstdio>
#include <cstring>

using namespace std;

int memo[99][100][2];

int solve(int n, int adj, int last){
    if(adj < 0) return 0;
    if(n < 0) return (adj == 0);
    
    int &ret = memo[n][adj][last];
    
    if(ret == -1) ret = solve(n-1,adj,0) + solve(n-1,last == 1? adj-1 : adj,1);
    
    return ret;
}

int main(){
    int T,tc,N,K;
    
    scanf("%d",&T);
    memset(memo,-1,sizeof(memo));
    
    while(T--){
        scanf("%d %d %d",&tc,&N,&K);
        if(K >= N) printf("%d 0\n",tc);
        else printf("%d %d\n",tc,solve(N-2,K,0) + solve(N-2,K,1));
    }
    
    return 0;
}
