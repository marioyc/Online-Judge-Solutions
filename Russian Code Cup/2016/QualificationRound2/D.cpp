#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int memo[1 << 13][3];
int n,a[3][13],ranka[13][3];

int solve(int mask, int player, int pos){
    if(pos == n - 1){
        return __builtin_ctz(mask);
    }
    int &ret = memo[mask][player];
    if(ret == -1){
        ret = a[player][n - 1];
        for(int i = 0;i < n;++i){
            if(mask >> i & 1){
                int aux = solve((mask ^ (1 << i)),(player + 1) % 3,pos + 1);
                if(ranka[aux][player] < ranka[ret][player]){
                    ret = aux;
                }
            }
        }
    }
    return ret;
}

int main(){
    int t;

    cin >> t;

    while(t--){
        cin >> n;

        for(int i = 0;i < 3;++i){
            for(int j = 0;j < n;++j){
                cin >> a[i][j];
                --a[i][j];
                ranka[ a[i][j] ][i] = j;
            }
        }

        memset(memo,-1,sizeof memo);
        cout << solve((1 << n) - 1,0,0) + 1 << '\n';
    }

    return 0;
}
