#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n,m;
string dp[301][301];

void add(string &a, string &b){
    string c;
    
    int La = a.size(),Lb = b.size();
    
    for(int i = 0,s = 0;i < La || i < Lb || s != 0;++i){
        if(i < La) s += a[i] - '0';
        if(i < Lb) s += b[i] - '0';
        
        c += '0' + s % 10;
        s /= 10;
    }
    
    a = c;
}

int main(){
    for(int i = 0;i <= 300;++i){
        for(int j = 0;j <= 300;++j){
            if(i == 0 && j == 0) dp[i][j] = "1";
            else{
                dp[i][j] = "0";
                
                if(i > 0) dp[i][j] = dp[i - 1][j];
                if(j > 0 && i >= j) add(dp[i][j],dp[i][j - 1]);
            }
        }
    }
    
    while(true){
        scanf("%d %d",&n,&m);
        if(n == 0 && m == 0) break;
        
        string ans = dp[n][m];
        reverse(ans.begin(),ans.end());
        
        printf("%s\n",ans.c_str());
    }
    
    return 0;
}
