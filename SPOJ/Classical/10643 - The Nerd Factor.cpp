#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 1000000007

int memo[1001][1001];

int solve(int n, int have){
    if(n == 0) return have == 0? 1 : 0;
    
    int &ret = memo[n][have];
    
    if(ret == -1){
        ret = solve(n - 1,have);
        
        if(have >= n){
            ret += solve(n,have - n);
            if(ret >= MOD) ret -= MOD;
        }
    }
    
    return ret;
}

int main(){
    memset(memo,-1,sizeof memo);
    
    int T,n,k;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&n,&k);
        
        int ans = 0;
        
        for(int i = 1;i <= n / k;++i){
            ans += solve(i,n - k * i);
            if(ans >= MOD) ans -= MOD;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
