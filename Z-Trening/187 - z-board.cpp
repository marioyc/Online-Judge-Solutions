#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char M[500][501];
int R,C;
int dp[500][500];

const int MAX_K = 1000000000;

int main(){
    int K;
    scanf("%d %d %d",&R,&C,&K);
    
    for(int i = 0;i<R;++i) scanf("%s",M[i]);
    
    dp[R-1][C-1] = 1;
    
    int r,c;
    
    for(int d = 1;d<=R+C-2;++d){
        for(int i = 0;i<=d;++i){
            r = R-1-i; c = C-1-d+i;
            
            if(r>=0 && r<R && c>=0 && c<C){
                dp[r][c] = 0;
                
                if(M[r][c]=='.'){
                    if(r+1<R && M[r+1][c]=='.') dp[r][c] += dp[r+1][c];
                    if(c+1<C && M[r][c+1]=='.') dp[r][c] += dp[r][c+1];
                    dp[r][c] = min(dp[r][c],MAX_K);
                }
            }
        }
    }
    
    if(dp[0][0]<K) printf("impossible\n");
    else{
        for(int r = 0,c = 0;r+c<R+C-2;){
            if(r+1<R && M[r+1][c]=='.' && dp[r+1][c]>=K){
                printf("D");
                ++r;
            }else{
                printf("R");
                if(r+1<R) K -= dp[r+1][c];
                ++c;
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
