#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n,k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0;i < n;++i){
        cin >> v[i];
    }
    for(int j = 0;j < k;++j){
        for(int i = n - 1;i > 0;--i){
            v[i] -= v[i - 1];
        }
    }
    for(int i = 0;i < n;++i){
        cout << v[i] << ' ';
    }
    cout << '\n';
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}