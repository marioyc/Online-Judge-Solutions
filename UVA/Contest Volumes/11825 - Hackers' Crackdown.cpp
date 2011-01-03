#include <cstdio>

using namespace std;

int main(){
    int tc = 1,N,affects[16],dp[(1<<16)];
    bool covers[(1<<16)];
    
    while(true){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i = 0,m,v;i<N;++i){
            affects[i] = (1<<i);
            scanf("%d",&m);
            
            for(int j = 0;j<m;++j){
                scanf("%d",&v);
                affects[i] |= (1<<v);
            }
        }
        
        for(int mask = (1<<N)-1,aux;mask>=0;--mask){
            aux = 0;
            
            for(int i = 0;i<N;++i)
                if(mask & (1<<i))
                    aux |= (affects[i]);
            
            covers[mask] = (aux==(1<<N)-1);
        }
        
        dp[0] = 0;
        
        for(int mask = 1;mask<(1<<N);++mask){
            dp[mask] = 0;
            
            for(int sub = mask;sub>0;sub = (sub-1)&mask)
                if(covers[sub] && 1+dp[mask & ~sub]>dp[mask])
                    dp[mask] = 1+dp[mask & ~sub];
        }
        
        printf("Case %d: %d\n",tc++,dp[(1<<N)-1]);
    }
    
    return 0;
}
