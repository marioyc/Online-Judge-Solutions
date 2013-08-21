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

#define MAXN 100005

int n,in[MAXN],root[MAXN],comp[MAXN],ncomp;
vector<int> L[MAXN];
bool visited[MAXN],done[MAXN],found;

void dfs(int cur){
    visited[cur] = true;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(!visited[to]) dfs(to);
        else if(!done[to]) root[ncomp] = cur,found = true;
    }
    
    done[cur] = true;
}

int parent[MAXN];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    parent[x] = y;
}

int main(){
    ios::sync_with_stdio(0);
    
    cin >> n;
    
    for(int i = 1;i <= n;++i)
        parent[i] = i;
    
    for(int i = 1,to;i <= n;++i){
        cin >> to;
        L[i].push_back(to);
        Union(i,to);
        ++in[to];
    }
    
    ncomp = 0;
    
    for(int i = 1;i <= n;++i){
        if(!visited[i]){
            found = false;
            dfs(i);
            if(found) ++ncomp;
        }
    }
    
    for(int i = 0;i < ncomp;++i)
        comp[ Find(root[i]) ] = i;
    
    for(int i = 1;i <= n;++i)
        comp[i] = comp[ Find(i) ];
    
    int ans = 0;
    vector<int> solu,solv;
    
    int rep[MAXN];
    memset(rep,-1,sizeof rep);
    
    for(int i = 1;i <= n;++i){
        if(in[i] == 0){
            if(rep[ comp[i] ] != -1){
                solu.push_back(root[ comp[i] ]);
                solv.push_back(rep[ comp[i] ]);
                ++ans;
            }
            
            rep[ comp[i] ] = i;
        }
    }
    
    for(int i = 0;i < ncomp;++i)
        if(rep[i] == -1)
            rep[i] = root[i];
    
    if(ncomp > 1){
        for(int i = 0;i < ncomp;++i){
            solu.push_back(root[i]);
            solv.push_back(rep[(i + 1) % ncomp]);
            ++ans;
        }
    }else if(in[ rep[0] ] == 0){
        solu.push_back(root[0]);
        solv.push_back(rep[0]);
        ++ans;
    }
    
    cout << ans << '\n';
    for(int i = 0;i < ans;++i) cout << solu[i] << ' ' << solv[i] << '\n';
    
    return 0;
}
