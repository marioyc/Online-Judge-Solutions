#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
long long dp[100001];
int L,last[26];
char s[100001];

int main(){
    int T;
    scanf("%d",&T);
    
    dp[0] = 1;
    
    while(T--){
        scanf("%s",s);
        L = strlen(s);
        
        memset(last,-1,sizeof(last));
        
        for(int i = 0;i < L;++i){
            dp[i+1] = dp[i] << 1;
            if(dp[i+1] >= MOD) dp[i+1] -= MOD;
            
            if(last[s[i]-'A'] != -1){
                dp[i+1] -= dp[last[s[i]-'A'] - 1];
                if(dp[i+1] < 0) dp[i+1] += MOD;
            }
            
            last[s[i]-'A'] = i+1;
        }
        
        printf("%lld\n",dp[L]);
    }
    
    return 0;
}
