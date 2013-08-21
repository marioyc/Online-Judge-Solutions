#include <cstdio>
#include <iostream>

using namespace std;

#define MOD 1000000007

int main(){
    ios::sync_with_stdio(0);
    
    string s;
    cin >> s;
    
    int n = s.size();
    
    long long ans = 0;
    long long p2[200];
    
    p2[0] = 1;
    for(int i = 1;i < 200;++i)
        p2[i] = p2[i - 1] * 2 % MOD;
    
    for(int i = 0;i < n;++i)
        if(s[i] == '1')
            ans = (ans + p2[2 * (n - 1 - i)] * p2[i]) % MOD;
    
    cout << ans << endl;
    
    return 0;
}
