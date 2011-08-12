#include <cstdio>
#include <cstring>

using namespace std;

int R,C;
int dr[] = {-1,-1,-1,0,0,1,1,1};
int dc[] = {-1,0,1,-1,1,-1,0,1};
int memo[4][4][(1 << 16)];

int solve(int mask, int n){
    if(n == 1) return 1;
    
    int &ret = memo[R-1][C-1][mask];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = 0;i < R;++i){
            for(int j = 0;j < C;++j){
                if((mask & (1 << (i * C + j))) != 0){
                    for(int k = 0;k < 8;++k){
                        int r2 = i + dr[k],c2 = j + dc[k];
                        int r3 = r2 + dr[k],c3 = c2 + dc[k];
                        
                        if(r3 >= 0 && r3 < R && c3 >= 0 && c3 < C && (mask & (1 << (r2 * C + c2))) != 0 && (mask & (1 << (r3 * C + c3))) == 0)
                                ret += solve(mask ^ (1 << (i * C + j)) ^ (1 << (r2 * C + c2)) ^ (1 << (r3 * C + c3)),n-1);
                    }
                }
            }
        }
    }
    
    return ret;
}

int main(){
    int T,N,r,c;
    
    scanf("%d",&T);
    memset(memo,-1,sizeof(memo));
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d %d %d",&R,&C,&N);
        
        int mask = 0;
        
        for(int i = 0;i < N;++i){
            scanf("%d %d",&r,&c);
            mask |= (1 << ((r-1) * C + c - 1));
        }
        
        printf("Case %d: %d\n",tc,solve(mask,N));
    }
    
    return 0;
}
