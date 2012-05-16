#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[500001];
int sd[10][50];

int main(){
    int S,D,M;
    
    scanf("%d %d %d",&S,&D,&M);
    
    for(int i = 0;i < S;++i)
        for(int j = 0;j < D;++j)
            scanf("%d",&sd[j][i]);
    
    for(int d = 0;d + 1 < D;++d){
        memset(dp,0,sizeof dp);
        
        for(int i = 0;i < S;++i){
            int p1 = sd[d][i],p2 = sd[d + 1][i];
            p2 -= p1;
            
            if(p2 > 0)
                for(int j = p1;j <= M;++j)
                    dp[j] = max(dp[j],p2 + dp[j - p1]);
        }
        
        M += dp[M];
    }
    
    printf("%d\n",M);
    
    return 0;
}
