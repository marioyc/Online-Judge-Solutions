#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 3000
#define MAXM 10

int n,m;
long long error[MAXN][MAXN],memo[MAXN][MAXM];

long long solve(int pos, int done){
    if(pos == n) return 0;
    if(done == m - 1) return error[pos][n - 1];
    
    long long &ret = memo[pos][done];
    
    if(ret == -1){
        ret = error[pos][n - 1];
        
        for(int i = pos;i < n;++i)
            ret = min(ret,error[pos][i] + solve(i + 1,done + 1));
    }
    
    return ret;
}

int main(){
    int T,a[MAXN];
    long long sum[MAXN + 1];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&n,&m);
        
        for(int i = 0;i < n;++i)
            scanf("%d",&a[i]);
        
        sort(a,a + n);
        sum[0] = 0;
        
        for(int i = 0;i < n;++i)
            sum[i + 1] = sum[i] + a[i];
        
        for(int i = 0;i < n;++i){
            error[i][i] = 0;
            
            for(int j = i + 1;j < n;++j){
                int mi = (i + j) >> 1;
                
                error[i][j] = sum[j + 1] - sum[mi + 1];
                error[i][j] -= sum[mi + 1] - sum[i];
                if((j - i + 1) & 1) error[i][j] += a[mi];
            }
        }
        
        memset(memo,-1,sizeof memo);
        
        printf("%lld\n",solve(0,0));
    }
    
    return 0;
}
