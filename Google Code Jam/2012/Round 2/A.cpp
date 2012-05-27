#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    
    int T,N,d[10000],l[10000],D;
    int dp[10000];
    
    cin >> T;
    
    for(int tc = 1;tc <= T;++tc){
        cin >> N;
        
        for(int i = 0;i < N;++i)
            cin >> d[i] >> l[i];
        
        cin >> D;
        
        bool found = false;
        
        memset(dp,0,sizeof dp);
        dp[0] = d[0];
        
        for(int i = 0;i < N && !found;++i){
            for(int j = 0;j < i;++j)
                if(d[j] + dp[j] >= d[i])
                    dp[i] = max(dp[i],min(d[i] - d[j],l[i]));
            
            if(d[i] + dp[i] >= D) found = true;
        }
        
        cout << "Case #" << tc <<": " << (found? "YES" : "NO") << '\n';
    }
    
    return 0;
}
