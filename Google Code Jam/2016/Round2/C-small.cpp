#include <cassert>
#include <iostream>

using namespace std;

#define MAXN 100

int R,C;
int parent[4 * MAXN];
int a[4 * MAXN];

int get_id(int r, int c, int k){
    return 4 * C * r + 4 * c + k;
}

int get_id(int x){
    int idx;
    if(x < C) idx = get_id(0,x,0);
    else if(x < C + R) idx = get_id(x - C,C - 1,1);
    else if(x < C + R + C) idx = get_id(R - 1,C - 1 - (x - C - R),2);
    else idx = get_id(R - 1 - (x - C - R - C),0,3);
    assert(idx >= 0 && idx < 4 * R * C);
    return idx;
}

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    parent[x] = y;
}

int main(){
    ios::sync_with_stdio(0);

    int T;

    cin >> T;

    for(int tc = 1;tc <= T;++tc){
        cin >> R >> C;

        for(int i = 0;i < 2 * (R + C);++i)
            cin >> a[i];

        int n = R * C;
        bool solved = false;

        cout << "Case #" << tc << ":\n";

        for(int mask = 0;mask < (1 << n);++mask){
            for(int i = 0;i < 4 * n;++i)
                parent[i] = i;

            for(int i = 0;i < n;++i){
                int r = i / C;
                int c = i % C;
                if(mask >> i & 1){
                    Union(get_id(r,c,0),get_id(r,c,3));
                    Union(get_id(r,c,1),get_id(r,c,2));
                }else{
                    Union(get_id(r,c,0),get_id(r,c,1));
                    Union(get_id(r,c,2),get_id(r,c,3));
                }
            }

            for(int i = 0;i + 1 < R;++i){
                for(int j = 0;j < C;++j){
                    Union(get_id(i,j,2),get_id(i + 1,j,0));
                }
            }

            for(int i = 0;i < R;++i){
                for(int j = 0;j + 1 < C;++j){
                    Union(get_id(i,j,1),get_id(i,j + 1,3));
                }
            }

            bool ok = true;

            for(int i = 0;i < 2 * (R + C) && ok;i += 2){
                int x = a[i] - 1,y = a[i + 1] - 1;
                int idx = get_id(x),idy = get_id(y);
                if(Find(idx) != Find(idy)) ok = false;

                for(int j = 0;j < 2 * (R + C) && ok;++j){
                    if(j != x && j != y){
                        int idz = get_id(j);
                        if(Find(idz) == Find(idx)) ok = false;
                    }
                }
            }

            if(ok){
                solved = true;

                for(int i = 0;i < R;++i){
                    for(int j = 0;j < C;++j){
                        int id = i * C + j;
                        if(mask >> id & 1) cout << "/";
                        else cout << "\\";
                    }
                    cout << "\n";
                }

                break;
            }
        }

        if(!solved) cout << "IMPOSSIBLE\n";
    }

    return 0;
}
