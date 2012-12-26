#include <cstdio>

using namespace std;

#define MAXN 1001

int R,C,M[MAXN][MAXN];
long long suml[MAXN][MAXN],sumr[MAXN][MAXN],sum[MAXN][MAXN];

int main(){
    scanf("%d %d",&R,&C);
    
    for(int i = 0;i < R;++i){
        for(int j = 0;j < C;++j){
            scanf("%d",&M[i][j]);
            suml[i][j] = (i > 0 && j > 0? suml[i - 1][j - 1] : 0LL) + M[i][j];
            sumr[i][j] = (i > 0 && j + 1 < C? sumr[i - 1][j + 1] : 0LL) + M[i][j];
            sum[i][j] = (i > 0 && j > 0? suml[i - 1][j - 1] : 0LL) + (i > 0 && j + 1 < C? sumr[i - 1][j + 1] : 0LL) +
                (i > 0? sum[i - 1][j] : 0LL) + M[i][j];
        }
    }
    
    int Q,x,y,r;
    
    scanf("%d",&Q);
    
    while(Q--){
        scanf("%d %d %d",&x,&y,&r);
        
        long long ans = sum[x + r][y] + (x > r? sum[x - r - 1][y] : 0LL);
        ans -= (x > 0? sum[x - 1][y - r] : 0LL) + (x > 0? sum[x - 1][y + r] : 0LL);
        ans -= (x > 0 && y > r? suml[x - 1][y - r - 1] : 0LL) + (x > 0 && y + r + 1 < C? sumr[x - 1][y + r + 1] : 0LL);
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
