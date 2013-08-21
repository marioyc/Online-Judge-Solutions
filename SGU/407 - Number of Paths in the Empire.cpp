#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

string add(string &a, string &b){
    int la = a.size(),lb = b.size();
    string ret;
    
    for(int i = 0,c = 0;i < la || i < lb || c;++i){
        if(i < la) c += a[i] - '0';
        if(i < lb) c += b[i] - '0';
        ret += '0' + c % 10;
        c /= 10;
    }
    
    return ret;
}

string mult(string &a, int b){
    int la = a.size();
    string ret;
    
    for(int i = 0,c = 0;i < la || c;++i){
        if(i < la) c += (a[i] - '0') * b;
        ret += '0' + c % 10;
        c /= 10;
    }
    
    return ret;
}
string dp[2][2];

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    dp[0][0] = "1";
    dp[0][1] = "0";
    
    for(int i = 1,cur = 1;i <= m;++i,cur ^= 1){
        dp[cur][0] = mult(dp[cur ^ 1][1],n);
        dp[cur][1] = mult(dp[cur ^ 1][1],2);
        dp[cur][1] = add(dp[cur][1],dp[cur ^ 1][0]);
    }
    
    string ret = dp[m & 1][0];
    reverse(ret.begin(),ret.end());
    printf("%s\n",ret.c_str());
    
    return 0;
}
