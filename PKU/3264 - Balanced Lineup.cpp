#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,Q;
    
    scanf("%d %d",&N,&Q);
    
    int h[N],rmq1[16][N],rmq2[16][N];
    
    for(int i = 0;i < N;++i){
        scanf("%d",&h[i]);
        rmq1[0][i] = rmq2[0][i] = h[i];
    }
    
    for(int i = 1,sz = 2;sz <= N;++i,sz <<= 1){
        for(int j = 0;j + sz <= N;++j){
            rmq1[i][j] = min(rmq1[i - 1][j],rmq1[i - 1][j + sz / 2]);
            rmq2[i][j] = max(rmq2[i - 1][j],rmq2[i - 1][j + sz / 2]);
        }
    }
    
    int l,r;
    
    while(Q--){
        scanf("%d %d",&l,&r);
        --l; --r;
        
        int lg = 0;
        
        while((1 << lg) <= r - l + 1) ++lg;
        --lg;
        
        printf("%d\n",max(rmq2[lg][l],rmq2[lg][r + 1 - (1 << lg)]) - min(rmq1[lg][l],rmq1[lg][r + 1 - (1 << lg)]));
    }
    
    return 0;
}
