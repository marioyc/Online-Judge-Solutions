#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

const long long MOD = 4207849484LL;

int main(){
    int T;
    
    scanf("%d",&T);
    
    int M;
    char s[1001];
    long long dp[1001];
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d %s",&M,s);
        
        int L = strlen(s);
        
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        
        for(int i = 0;i < L;++i){
            int aux = 0;
            
            if(s[i] != '0')
            for(int j = i;j < L;++j){
                aux = aux * 10 + s[j] - '0';
                
                if(aux > M) break;
                else dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
            }
        }
        
        printf("Case #%d: ",tc);
        cout << dp[L];
        printf("\n");
    }
    
    return 0;
}
