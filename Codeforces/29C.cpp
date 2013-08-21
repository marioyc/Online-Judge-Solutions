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

int main(){
    ios::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    map<int, int> id,rev;
    vector<int> L[n + 1];
    
    for(int i = 0,u,v,cont = 0;i < n;++i){
        cin >> u >> v;
        
        if(id.find(u) == id.end()){
            id[u] = cont;
            rev[cont] = u;
            ++cont;
        }
        
        if(id.find(v) == id.end()){
            id[v] = cont;
            rev[cont] = v;
            ++cont;
        }
        u = id[u];
        v = id[v];
        
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    int pos;
    
    for(int i = 0;i <= n;++i){
        if(L[i].size() == 1){
            pos = i;
            break;
        }
    }
    
    for(int i = 0,prev = -1;i <= n;++i){
        cout << rev[pos] << ' ';
        
        for(int j = L[pos].size() - 1;j >= 0;--j)
            if(L[pos][j] != prev){
                prev = pos;
                pos = L[pos][j];
                break;
            }
    }
    cout << '\n';
    
    return 0;
}
