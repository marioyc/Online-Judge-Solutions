#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<int> p(n),pos(n);
    for(int i = 0;i < n;++i){
        cin >> p[i];
        --p[i];
        pos[ p[i] ] = i;
    }
    vector<bool> used(n, false);
    vector<int> c[2];
    for(int i = 0;i < n;++i){
        if(used[i]) continue;
        used[i] = true;
        int cur = p[i];
        int sz = 1;
        while(cur != i){
            used[cur] = true;
            cur = p[cur];
            ++sz;
        }
        c[sz % 2].push_back(sz);
    }
    if(c[0].size() % 2 == 1){
        cout << -1 << '\n';
        return;
    }
    int ans = 0;
    for(int x : c[0]) ans += x;
    ans /= 2;
    for(int x : c[1]) ans += (x - 1) / 2;
    cout << ans << '\n';
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