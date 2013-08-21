#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 305

int n;
long long memo1[MAXN][MAXN];
long long memo2[MAXN][MAXN];
int cost[MAXN][MAXN];

long long solve1(int l, int r){
    if(l > r) return 0;
    
    long long &ret = memo1[l][r];
    
    if(ret == -1){
        ret = -2;
        
        for(int i = l;i <= r;++i){
            if(cost[i][r] != -1 && solve1(l,i - 1) != -2){
                long long aux = solve1(l,i - 1) + cost[i][r];
                if(ret == -2 || aux < ret) ret = aux;
            }
        }
    }
    
    return ret;
}

long long solve2(int pos, int k){
    if(pos == n + 1) return (k > 0? -2 : 0);
    
    long long &ret = memo2[pos][k];
    
    if(ret == -1){
        ret = solve2(pos + 1,k);
        
        for(int i = pos;i <= n;++i){
            int k2 = max(0,k - (i - pos + 1));
            
            if(solve1(pos,i) != -2 && solve2(i + 1,k2) != -2){
                long long aux = solve1(pos,i) + solve2(i + 1,k2);
                if(ret == -2 || aux < ret) ret = aux;
            }
        }
    }
    
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    
    int m,k;
    cin >> n >> m >> k;
    
    memset(memo1,-1,sizeof memo1);
    memset(memo2,-1,sizeof memo2);
    memset(cost,-1,sizeof cost);
    
    for(int i = 0,l,r,c;i < m;++i){
        cin >> l >> r >> c;
        if(cost[l][r] == -1) cost[l][r] = c;
        else cost[l][r] = min(cost[l][r],c);
    }
    
    for(int i = 1;i <= n;++i)
        for(int j = n - 1;j >= i;--j)
            if(cost[i][j + 1] != -1 && (cost[i][j] == -1 || cost[i][j + 1] < cost[i][j]))
                cost[i][j] = cost[i][j + 1];
    
    long long ret = solve2(0,k);
    
    if(ret == -2) cout << -1 << '\n';
    else cout << ret << '\n';
    
    return 0;
}
