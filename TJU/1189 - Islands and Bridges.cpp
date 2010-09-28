#include <cstdio>
#include <cstring>

using namespace std;

int dp[13][13][(1<<13)];
long long ways[13][13][(1<<13)];

int main(){
    int T,n,m,V[13],u,v;
    bool M[13][13];
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d %d",&n,&m);
        
        for(int i=0;i<n;++i) scanf("%d",&V[i]);
        
        memset(M,false,sizeof(M));
        
        for(int i=0;i<m;++i){
            scanf("%d %d",&u,&v);
            --u; --v;
            M[u][v] = M[v][u] = true;
        }
        
        if(n==1){
            printf("%d 1\n",V[0]);
            continue;
        }
        
        memset(dp,-1,sizeof(dp));
        memset(ways,0,sizeof(ways));
        
        for(int i=0;i<n;++i) for(int j=0;j<n;++j){
            if(i==j || !M[i][j]) continue;
            ways[i][j][(1<<n)-1] = 1;
            dp[i][j][(1<<n)-1] = V[i]*V[j];
        }
        
        for(int mask=(1<<n)-2;mask>=3;--mask) for(int i=0;i<n;++i) for(int j=0;j<n;++j){
            if(i==j || (mask & (1<<i))==0 || (mask & (1<<j))==0 || !M[i][j]) continue;
            
            for(int k=0;k<n;++k){
                if((mask & (1<<k))!=0 || !M[j][k] || dp[j][k][mask | (1<<k)]<0) continue;
                
                int aux = dp[j][k][mask | (1<<k)]+V[i]*V[j];
                if(M[i][k]) aux += V[i]*V[j]*V[k];
                
                if(aux>dp[i][j][mask]){
                    dp[i][j][mask] = aux;
                    ways[i][j][mask] = ways[j][k][mask | (1<<k)];
                }else if(aux==dp[i][j][mask]) ways[i][j][mask] += ways[j][k][mask | (1<<k)];
            }
        }
        
        int best = -1;
        long long paths = 0;
        
        for(int i=0;i<n;++i) for(int j=0;j<n;++j){
            if(i==j || !M[i][j]) continue;
            
            int aux = dp[i][j][(1<<i) | (1<<j)];
            
            if(aux>best){
                best = aux;
                paths = ways[i][j][(1<<i) | (1<<j)];
            }else if(aux==best) paths += ways[i][j][(1<<i) | (1<<j)];
        }
        
        if(best==-1) printf("0 0\n");
        else{
            int sum = 0;
            for(int i=0;i<n;++i) sum += V[i];
            printf("%d %lld\n",sum+best,paths/2);
        }
    }
    
    return 0;
}
