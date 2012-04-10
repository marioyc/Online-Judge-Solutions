#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int N,P,T,d[10];
    bool have[10];
    int dp[101][1000];
    
    while(scanf("%d",&N) == 1){
        memset(have,false,sizeof have);
        
        for(int i = 0;i < N;++i){
            scanf("%d",&d[i]);
            have[ d[i] ] = true;
        }
        
        scanf("%d %d",&P,&T);
        
        memset(dp,0,sizeof dp);
        dp[0][0] = 1;
        
        for(int i = 0;i < P;++i){
            for(int j = 0;j < T;++j){
                for(int k = (i > 0? 0 : 1);k < 10;++k){
                    if(have[k]){
                        int m = (j * 10 + k) % T;
                        dp[i + 1][m] += dp[i][j];
                        if(dp[i + 1][m] >= 1000001) dp[i + 1][m] -= 1000001;
                    }
                }
            }
        }
        
        printf("%d\n",dp[P][0]);
    }
    
    return 0;
}
