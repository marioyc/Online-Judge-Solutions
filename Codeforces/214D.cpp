#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 1000000007

int a[10],C[101][101];
int memo[10][101];

int solve(int d, int have){
    if(d == 10) return (have == 0? 1 : 0);
    
    int &ret = memo[d][have];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = a[d];i <= have;++i){
            ret += (long long)(d == 0? C[have - 1][i] : C[have][i]) * solve(d + 1,have - i) % MOD;
            ret %= MOD;
        }
    }
    
    return ret;
}

int main(){
    int n;
    
    scanf("%d",&n);
    
    for(int i = 0;i < 10;++i)
        scanf("%d",&a[i]);
    
    memset(C,0,sizeof C);
    
    for(int i = 0;i <= 100;++i){
        C[i][0] = C[i][i] = 1;
        
        for(int j = 1;j < i;++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    
    memset(memo,-1,sizeof memo);
    int ans = 0;
    
    for(int i = 1;i <= n;++i)
        ans = (ans + solve(0,i)) % MOD;
    
    printf("%d\n",ans);
    
    return 0;
}
