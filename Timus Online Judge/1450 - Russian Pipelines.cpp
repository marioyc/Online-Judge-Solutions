#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

vector<int> L[501],W[501];
int memo[501];
int S,F;

int solve(int pos){
    if(pos == F) return 0;    
    
    int &ret = memo[pos];
    
    if(ret == -1){
        ret = -2;
        
        for(int i = L[pos].size() - 1;i >= 0;--i){
            int aux = solve(L[pos][i]);
            
            if(aux != -2){
                aux += W[pos][i];
                ret = max(ret,aux);
            }
        }
    }
    
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    
    int n,m;
    
    cin >> n >> m;
    
    for(int i = 0,u,v,w;i < m;++i){
        cin >> u >> v >> w;
        
        L[u].push_back(v);
        W[u].push_back(w);
    }
    
    memset(memo,-1,sizeof memo);
    
    cin >> S >> F;
    
    int ret = solve(S);
    
    if(ret == -2) cout << "No solution\n";
    else cout << ret << '\n';
    
    return 0;
}
