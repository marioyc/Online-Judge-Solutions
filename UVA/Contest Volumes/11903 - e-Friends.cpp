#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N,K,memo[(1<<12)][12][12];
bool enemy[12][12];

int solve(int mask, int last, int r){
    if(r<0) return 0;
    if(mask==(1<<N)-1) return 1;
    
    int &ret = memo[mask][last][r];
    
    if(ret==-1){
        ret = 0;
        
        for(int i = 0;i<N;++i)
            if((mask & (1<<i))==0)
                ret += solve(mask | (1<<i),i,enemy[i][last]? r-1 : r);
    }
    
    return ret;
}

int main(){
    int tc = 1,T,Q,r;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&N,&K,&Q);
        
        memset(enemy,false,sizeof(enemy));
        
        for(int i = 0,x,y;i<N;++i){
            scanf("%d",&x);
            
            for(int j = 0;j<x;++j){
                scanf("%d",&y);
                enemy[i][--y] = true;
            }
        }
        
        memset(memo,-1,sizeof(memo));
        
        int fac = 1;
        for(int i = 2;i<=N;++i) fac *= i;
        
        printf("Case %d:\n",tc++);
        
        while(Q--){
            scanf("%d",&r);
            
            if(K==0) printf("%d\n",fac);
            else{
                r /= K;
                
                if(r>=N) printf("%d\n",fac);
                else{
                    int ans = 0;
                    
                    for(int i = 0;i<N;++i)
                        ans += solve((1<<i),i,r);
                    
                    printf("%d\n",ans);
                }
            }
        }
    }
    
    return 0;
}
