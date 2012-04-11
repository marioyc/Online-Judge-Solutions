#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 1000007

int memo[41][(1 << 5)][6][6][3];

int solve(int pos, int mask, int d1, int d2, int m3){
    if(pos == 0){
        if(mask & 1)
            if(d2 & 1) return 0;
        
        if(mask & 2)
            if(m3) return 0;
        
        if(mask & 4)
            if((d1 * 10 + d2) % 4 != 0) return 0;
        
        if(mask & 8)
            if(d2 != 0 && d2 != 5) return 0;
        
        if(mask & 16){
            if(d2 & 1) return 0;
            if(m3) return 0;
        }
        
        return 1;
    }
    
    int &ret = memo[pos][mask][d1 - 1][d2 - 1][m3];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = 1;i <= 6;++i){
            ret += solve(pos - 1,(mask | (i > 1? (1 << (i - 2)) : 0)),d2,i,(m3 + i) % 3);
            if(ret >= MOD) ret -= MOD;
        }
    }
    
    return ret;
}

int main(){
    int ans[41];
    
    for(int i = 1;i <= 40;++i){
        memset(memo,-1,sizeof memo);
        ans[i] = solve(i,0,0,0,0);
    }
    
    int T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        printf("%d\n",ans[N]);
    }
    
    return 0;
}
