#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
int first[100001][26],dp[100000];

int main(){
    int T;
    scanf("%d",&T);
    
    char s[100000];
    bool used[26];
    
    for(int tc=1;tc<=T;++tc){
        scanf("%s",s);
        
        int n = strlen(s);
        
        for(int i=0;i<26;++i) first[n][i] = -1;
        
        for(int i=n-1;i>=0;--i){
            for(int j=0;j<s[i]-'A';++j) first[i][j] = first[i+1][j];
            first[i][s[i]-'A'] = i;
            for(int j=s[i]-'A'+1;j<26;++j) first[i][j] = first[i+1][j];
        }
        
        for(int i=n-1;i>=0;--i){
            dp[i] = 1;
            
            for(int j=0;j<26;++j){
                if(first[i+1][j]==-1) continue;
                dp[i] += dp[first[i+1][j]];
                if(dp[i]>MOD) dp[i] -= MOD;
            }
        }
        
        int ans = 1;
        
        for(int i=0;i<26;++i) used[i] = false;
        
        for(int i=0;i<n;++i){
            if(!used[s[i]-'A']){
                used[s[i]-'A'] = true;
                ans += dp[i];
                if(ans>MOD) ans -= MOD;
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
