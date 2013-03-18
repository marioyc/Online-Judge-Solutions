#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn 1000

int n,M[maxn][maxn];
int sum[maxn][maxn + 1];
long long memo[maxn][maxn];
bool done[maxn][maxn];

long long solve(int r, int c){
    if(r == n) return 0;
    long long &ret = memo[r][c];
    
    if(!done[r][c]){
        done[r][c] = true;
        ret = 0;
        
        if(c > 0) ret = max(ret,solve(r,c - 1));
        ret = max(ret,solve(r + 1,min(n - 2 - r,c)) + sum[r][c + 1]);
    }
    
    return ret;
}

int main(){
    while(true){
        scanf("%d",&n);
        if(n == 0) break;
        
        for(int i = 0;i < n;++i)
            for(int j = 0;j <= i;++j)
                scanf("%d",&M[j][i - j]);
        
        for(int i = 0;i < n;++i)
            for(int j = 0;j < n - i;++j)
                sum[i][j + 1] = M[i][j] + sum[i][j];
        
        memset(done,false,sizeof done);
        printf("%lld\n",solve(0,n - 1));
    }
    
    return 0;
}
