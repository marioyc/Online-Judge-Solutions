#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N,M,L,C[1024],memo[101][(1<<10)];
int pos[1024][1024];

int solve(int n, int mask){
    if(n==0) return 0;
    int &ret = memo[n][mask];
    
    if(ret==-1){
        if(n<=N-L+1) ret = max(C[(mask*2) & ((1<<L)-1)]+solve(n-1,(mask*2) & ((1<<L)-1)),
            C[(mask*2+1) & ((1<<L)-1)]+solve(n-1,(mask*2+1) & ((1<<L)-1)));
        else ret = max(solve(n-1,(mask*2) & ((1<<L)-1)),solve(n-1,(mask*2+1) & ((1<<L)-1)));
    }
    
    return ret;
}

int main(){
    int T,sc;
    scanf("%d",&T);
    
    char p[11];
    
    while(T--){
        scanf("%d %d %d",&N,&M,&L);
        
        memset(C,0,sizeof(C));
        
        for(int i = 0;i<M;++i){
            int mask = 0;
            scanf("%s %d",p,&sc);
            
            for(int j = 0;j<L;++j)
                if(p[j]=='B') mask |= (1<<j);
            
            C[mask] = sc;
        }
        
        memset(memo,-1,sizeof(memo));
        printf("%d\n",solve(N,0));
    }
    
    return 0;
}
