#include <cstdio>
#include <cstring>

using namespace std;

bool dp[5001][(1 << 12)];

int main(){
    int n,m,LT,f[5000];
    char P[12][21],LP[12];
    char T[5001];
    bool occ[5001][12];
    
    while(true){
        scanf("%d %d",&n,&m);
        if(n == 0) break;
        
        for(int i = 0;i < n;++i){
            scanf("%s",P[i]);
            LP[i] = strlen(P[i]);
        }
        
        LT = 0;
        
        for(int i = 0;i < m;++i){
            scanf("%s",T + LT);
            LT += strlen(T + LT);
        }
        
        f[0] = 0;
        
        memset(occ,0,sizeof occ);
        
        for(int i = 0;i < n;++i){
            for(int j = 1,k = 0;j < LP[i];++j){
                while(k > 0 && P[i][j] != P[i][k]) k = f[k - 1];
                if(P[i][j] == P[i][k]) ++k;
                f[j] = k;
            }
            
            
            for(int j = 0,k = 0;j < LT;++j){
                while(k > 0 && T[j] != P[i][k]) k = f[k - 1];
                if(T[j] == P[i][k]) ++k;
                
                if(k == LP[i]){
                    occ[j - k + 1][i] = true;
                    k = f[k - 1];
                }
            }
        }
        
        memset(dp,0,sizeof dp);
        
        int M = (1 << n) - 1;
        dp[LT][0] = 1;
        
        for(int i = LT - 1;i >= 0;--i){
            dp[i][0] = 1;
            
            for(int mask = 1;mask <= M;++mask){
                int aux = mask;
                
                while(aux && !dp[i][mask]){
                    int j = __builtin_ctz(aux);
                    aux ^= (1 << j);
                    
                    if(occ[i][j]) dp[i][mask] = dp[i][mask] || dp[i + LP[j]][mask ^ (1 << j)];
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 0;i < LT;++i)
            if(dp[i][M]) ++ans;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
