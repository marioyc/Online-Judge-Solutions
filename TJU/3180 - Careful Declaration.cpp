#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int n1,n2;
char s1[2001][11],s2[2001][11];
int dp[2001][2001],choice[2001][2001];

int main(){
    while(true){
        n1 = n2 = 0;
        
        while(true){
            scanf("%s",s1[n1]);
            if(s1[n1][0] == '.') break;
            ++n1;
        }
        
        if(n1 == 0) break;
        
        while(true){
            scanf("%s",s2[n2]);
            if(s2[n2][0] == '.') break;
            ++n2;
        }
        
        for(int i = n1;i >= 0;--i){
            for(int j = n2;j >= 0;--j){
                if(i == n1 && j == n2) dp[i][j] = 0;
                else if(i == n1){
                    dp[i][j] = 1 + dp[i][j + 1];
                    choice[i][j] = 2;
                }else if(j == n2){
                    dp[i][j] = 1 + dp[i + 1][j];
                    choice[i][j] = 1;
                }else{
                    dp[i][j] = 1 + min(dp[i][j + 1],dp[i + 1][j]);
                    bool eq = (strcmp(s1[i],s2[j]) == 0);
                    if(eq) dp[i][j] = min(dp[i][j],1 + dp[i + 1][j + 1]);
                    
                    if(eq && 1 + dp[i + 1][j + 1] == dp[i][j]) choice[i][j] = 0;
                    else if(dp[i][j] == 1 + dp[i][j + 1] && (dp[i][j] < 1 + dp[i + 1][j] || strcmp(s1[i],s2[j]) > 0)) choice[i][j] = 2;
                    else choice[i][j] = 1;
                }
            }
        }
        
        int pos1 = 0,pos2 = 0;
        
        while(pos1 + pos2 != n1 + n2){
            if(choice[pos1][pos2] == 0){
                printf("%s ",s1[pos1]);
                ++pos1; ++pos2;
            }else if(choice[pos1][pos2] == 1){
                printf("%s ",s1[pos1]);
                ++pos1;
            }else{
                printf("%s ",s2[pos2]);
                ++pos2;
            }
        }
        
        puts(".");
    }
    
    return 0;
}
