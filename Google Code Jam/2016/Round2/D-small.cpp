#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N,memo[1 << 4][1 << 4];
string s[4];
bool knows[4][4];

int solve(int maskw, int maskm){
    assert(__builtin_popcount(maskw) == __builtin_popcount(maskm));
    int &ret = memo[maskw][maskm];

    if(ret == -1){
        ret = 1;

        for(int i = 0;i < N;++i){
            if(maskw >> i & 1){
                bool found = false;

                for(int j = 0;j < N;++j){
                    if((maskm >> j & 1) && knows[i][j]){
                        int aux = solve((maskw ^ (1 << i)),(maskm ^ (1 << j)));
                        if(aux == 0) ret = 0;
                        found = true;
                    }
                }

                if(!found) ret = 0;
            }
        }
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(0);

    int T;

    cin >> T;

    for(int tc = 1;tc <= T;++tc){
        cin >> N;

        memset(knows,false,sizeof knows);
        vector<int> w,m;

        for(int i = 0;i < N;++i){
            cin >> s[i];
            for(int j = 0;j < N;++j)
                if(s[i][j] == '1')
                    knows[i][j] = true;
                else{
                    w.push_back(i);
                    m.push_back(j);
                }
        }

        int sz = w.size();
        int ans = N * N;

        for(int mask = 0;mask < (1 << sz);++mask){
            if(__builtin_popcount(mask) < ans){
                for(int i = 0;i < sz;++i){
                    if(mask >> i & 1)
                        knows[ w[i] ][ m[i] ] = true;
                }

                memset(memo,-1,sizeof memo);
                if(solve((1 << N) - 1,(1 << N) - 1) == 1){
                    ans = __builtin_popcount(mask);
                }

                for(int i = 0;i < sz;++i){
                    if(mask >> i & 1)
                        knows[ w[i] ][ m[i] ] = false;
                }
            }
        }

        cout << "Case #" << tc << ": " << ans << '\n';
    }

    return 0;
}
