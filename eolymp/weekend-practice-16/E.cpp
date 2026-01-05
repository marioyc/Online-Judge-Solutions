#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 1000005;
const int maxq = 1000005;
int ql[maxq],qr[maxq],qx[maxq];

struct DSU{
    int par[2 * maxn];

    void init(int sz){
        iota(par, par + sz, 0);
    }

    int Find(int x){
        if(par[x] != x) par[x] = Find(par[x]);
        return par[x];
    }

    void Union(int x, int y){
        int px = Find(x);
        int py = Find(y);
        par[px] = py;
    }
}dsu[20];

bool check(int k, int l, int r){
    if(dsu[k].Find(l) == dsu[k].Find(r)) return true;
    if(k == 0) return false;
    if(!check(k - 1, l, r)) return false;
    if(!check(k - 1, l + (1 << (k - 1)), r + (1 << (k - 1)))) return false;
    dsu[k].Union(l, r);
    return true;
}

bool query(int l, int r, int len){
    assert(len > 0);
    int lg = 0;
    while((1 << lg) <= len) ++lg;
    --lg;
    return check(lg, l, r) && check(lg, l + len - (1 << lg), r + len - (1 << lg));
}

void solve(){
    int n,q;
    cin >> n >> q;
    for(int i = 0;i < q;++i){
        cin >> ql[i] >> qr[i] >> qx[i];
        --ql[i]; --qr[i];
    }
    for(int i = 0;i < 20;++i){
        dsu[i].init(2 * (n - 1));
    }
    for(int i = 0;i < n - 1;++i){
        dsu[0].Union(i, 2 * (n - 1) - 1 - i);
    }
    for(int i = 0;i < q;++i){
        if(qx[i] == 1){
            int p1 = ql[i];
            int p2 = n - 1 + (n - 2 - (qr[i] - 1));
            int len = qr[i] - ql[i];
            for(int k = 19;k >= 0;--k){
                if(len >> k & 1){
                    dsu[k].Union(p1, p2);
                    p1 += (1 << k);
                    p2 += (1 << k);
                }
            }
        }
    }
    for(int k = 19;k > 0;--k){
        int szh = (1 << (k - 1));
        for(int i = 0;i < 2 * (n - 1);++i){
            int r = dsu[k].Find(i);
            if(r != i){
                dsu[k - 1].Union(i, r);
                dsu[k - 1].Union(i + szh, r + szh);
            }
        }
    }
    vector<ll> sol(n, 0);
    for(int i = 1;i < n;++i){
        sol[i] = sol[i - 1] + dsu[0].Find(i - 1);
    }
    for(int i = 0;i < q;++i){
        if(qx[i] == 0){
            int p1 = ql[i];
            int p2 = n - 1 + (n - 2 - (qr[i] - 1));
            int len = qr[i] - ql[i];
            if(len == 0 || query(p1, p2, len)){
                cout << -1 << '\n';
                return;
            }
        }
    }
    for(auto x : sol) cout << x << ' ';
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