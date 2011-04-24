#include <cstdio>
#include <cstring>

using namespace std;

int dp[901][8101],aux;

int main(){
    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;
    
    for(int i = 1;i <= 900;++i){
        for(int j = 0;j <= 8100;++j){
            for(int d = 1;d <= 9;++d){
                if(i >= d && j >= d*d && dp[i-d][j-d*d] != -1){
                    aux = 1 + dp[i-d][j-d*d];
                    if(aux <= 100 && (dp[i][j] == -1 || aux < dp[i][j])) dp[i][j] = aux;
                }
            }
        }
    }
    
    int T,s1,s2,cont[10];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&s1,&s2);
        
        if(s1 > 900 || s2 > 8100 || dp[s1][s2] == -1) puts("No solution");
        else{
            
            while(s1 != 0 || s2 != 0){
                for(int i = 1;i <= 9;++i){
                    if(s1 >= i && s2 >= i*i && 1 + dp[s1-i][s2-i*i] == dp[s1][s2]){
                        putchar('0'+i);
                        s1 -= i;
                        s2 -= i * i;
                        ++cont[i];
                        break;
                    }
                }
            }
            
            putchar('\n');
        }
    }
    
    return 0;
}
