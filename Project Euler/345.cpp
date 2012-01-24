#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 15;
int a[N][N];
int memo[N][(1 << N)];

int solve(int r, int mask){
    if(r == -1) return 0;
    
    int &ret = memo[r][mask];
    
    if(ret == -1){
        ret = 0;
        
        for(int c = 0;c < N;++c)
            if(mask & (1 << c))
                ret = max(ret,a[r][c] + solve(r - 1,mask ^ (1 << c)));
    }
    
    return ret;
}

int main(){
    for(int i = 0;i < N;++i)
        for(int j = 0;j < N;++j)
            scanf("%d",&a[i][j]);
    
    memset(memo,-1,sizeof memo);
    
    printf("%d\n",solve(N - 1,(1 << N) - 1));
    
    return 0;
}
