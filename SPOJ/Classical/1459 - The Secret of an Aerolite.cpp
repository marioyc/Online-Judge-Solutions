#include <cstdio>
#include <cstring>

using namespace std;

int MOD = 11380,memo[11][11][11][31];

int solve(int L1, int L2, int L3, int D){
    if(D < 0) return 0;
    if(L1+L2+L3 == 0) return 1;
    
    int &ret = memo[L1][L2][L3][D];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = 0;i < L1;++i)
            for(int j = 0;j <= L2; ++j)
                for(int k = 0;k <= L3;++k)
                    ret = (ret + solve(i,j,k,D-1)*solve(L1-1-i,L2-j,L3-k,D)) % MOD;
        
        for(int i = 0;i < L2;++i)
            for(int j = 0;j <= L3; ++j)
                ret = (ret + solve(0,i,j,D-1)*solve(L1,L2-1-i,L3-j,D)) % MOD;
        
        for(int i = 0;i < L3;++i)
            ret = (ret + solve(0,0,i,D-1)*solve(L1,L2,L3-1-i,D)) % MOD;
    }
    
    return ret;
}

int main(){
    int L1,L2,L3,D;
    
    memset(memo,-1,sizeof(memo));
    
    while(scanf("%d %d %d %d",&L1,&L2,&L3,&D) == 4){
        int ans = solve(L1,L2,L3,D)-solve(L1,L2,L3,D-1);
        if(ans < 0) ans += MOD;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
