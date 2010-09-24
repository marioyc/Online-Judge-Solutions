#include <cstdio>
#include <cstring>

#define min(a,b) a<b? a:b

using namespace std;

int main(){    
    char fruit1[101],fruit2[101];
    int l1,l2,dp[101][101],next[101][101];
    
    while(scanf("%s %s",fruit1,fruit2)==2){
        l1=strlen(fruit1);
        l2=strlen(fruit2);
        
        for(int i=l1;i>=0;i--){
            for(int j=l2;j>=0;j--){
                if(i==l1 && j==l2){
                    dp[i][j]=0;
                    continue;
                }else if(i==l1){
                    dp[i][j]=1+dp[i][j+1];
                    next[i][j]=1;
                    continue;
                }else if(j==l2){
                    dp[i][j]=1+dp[i+1][j];
                    next[i][j]=2;
                    continue;
                }
                
                if(fruit1[i]==fruit2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                    next[i][j]=0;
                }else{
                    if(dp[i][j+1]<=dp[i+1][j]){
                        dp[i][j]=1+dp[i][j+1];
                        next[i][j]=1;
                    }else{
                        dp[i][j]=1+dp[i+1][j];
                        next[i][j]=2;
                    }
                }
            }
        }
        
        int pos1=0,pos2=0;
        
        while(dp[pos1][pos2]!=0){
            if(next[pos1][pos2]==0){
                printf("%c",fruit1[pos1]);
                pos1++;
                pos2++;
            }else if(next[pos1][pos2]==1){
                printf("%c",fruit2[pos2]);
                pos2++;
            }else{
                printf("%c",fruit1[pos1]);
                pos1++;
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
