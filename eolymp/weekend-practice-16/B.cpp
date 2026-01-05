#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    for(int i = 1;i + 1 < n;i += 2) swap(p[i], p[i + 1]);
    for(int i = 0;i < n;++i) cout << p[i] << ' ';
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