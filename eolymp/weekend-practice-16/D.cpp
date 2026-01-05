#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = (int)(1e9) + 7;
const int maxsz = 1000005;

ll modpow(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

ll fact[maxsz],ifact[maxsz];

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> c(10);
    for(char x : s) ++c[x - '0'];
    vector<ll> p10(n);
    ll sum_p10 = 1;
    p10[0] = 1;
    for(int i = 1;i < n;++i){
        p10[i] = p10[i - 1] * 10 % mod;
        sum_p10 = (sum_p10 + p10[i]) % mod;
    }
    for(int i = 0;i < n;++i){
        int cur = s[i] - '0';
        --c[cur];
        ll den = 1;
        for(int i = 0;i < 10;++i) den = den * ifact[ c[i] ] % mod;
        ll ans = cur * p10[n - 1 - i] % mod * fact[n - 1] % mod * den % mod;
        for(int d = 1;d <= 9;++d){
            if(c[d] == 0) continue;
            ll aux = sum_p10 - p10[n - 1 - i];
            if(aux < 0) aux += mod;
            ll C2 = fact[n - 2] * den % mod * fact[ c[d] ] % mod * ifact[ c[d] - 1 ] % mod;
            ans = (ans + d * C2 % mod * aux) % mod;
        }
        cout << ans << ' ';
        ++c[cur];
    }
    cout << '\n';
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    fact[0] = 1;
    for(int i = 1;i < maxsz;++i) fact[i] = fact[i - 1] * i % mod;
    ifact[maxsz - 1] = modpow(fact[maxsz - 1], mod - 2);
    for(int i = maxsz - 2;i >= 0;--i) ifact[i] = ifact[i + 1] * (i + 1) % mod;

    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}