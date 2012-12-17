#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXK 9

int M[(1 << MAXK)][(1 << MAXK)];
int memo[(1 << MAXK)][(1 << MAXK)];

int solve(int pos, int last){
    if(pos == 0) return 0;
    
    int &ret = memo[pos][last];
    
    if(ret == -1){
        ret = 1e9;
        
        int nb = __builtin_ctz(pos);
        int mn = ((last ^ (1 << nb)) >> nb) << nb;
        int mx = mn + (1 << nb) - 1;
        
        for(int i = mn;i <= mx;++i)
            ret = min(ret,M[i][last] + solve(pos - 1,i));
    }
    
    return ret;
}

int main(){
    int K;
    
    scanf("%d",&K);
    
    int N = (1 << K);
    
    for(int i = 0;i < N;++i)
        for(int j = 0;j < N;++j)
            scanf("%d",&M[i][j]);
    
    int ans = 1e9;
    memset(memo,-1,sizeof memo);
    
    for(int i = 0;i < N;++i)
        ans = min(ans,solve(N - 1,i));
    
    printf("%d\n",ans);
    
    return 0;
}
