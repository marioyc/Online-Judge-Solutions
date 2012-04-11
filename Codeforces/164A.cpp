#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

#define MAXN 100001

vector<int> L[MAXN],L2[MAXN];
int f[MAXN];
bool done1[MAXN],done2[MAXN];

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    for(int i = 1;i <= n;++i)
        scanf("%d",&f[i]);
    
    for(int i = 0,u,v;i < m;++i){
        scanf("%d %d",&u,&v);
        
        L[u].push_back(v);
        L2[v].push_back(u);
    }
    
    queue<int> Q;
    
    for(int i = 1;i <= n;++i)
        if(f[i] == 1){
            done1[i] = true;
            Q.push(i);
        }
    
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        
        for(int j = L[cur].size() - 1;j >= 0;--j){
            int to = L[cur][j];
            
            if(!done1[to] && f[to] != 1){
                done1[to] = true;
                Q.push(to);
            }
        }
    }
    
    for(int i = 1;i <= n;++i)
        if(f[i] == 2){
            done2[i] = true;
            Q.push(i);
        }
    
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        
        for(int j = L2[cur].size() - 1;j >= 0;--j){
            int to = L2[cur][j];
            
            if(!done2[to] && f[to] != 1){
                done2[to] = true;
                Q.push(to);
            }else if(f[to] == 1) done2[to] = true;
        }
    }
    
    for(int i = 1;i <= n;++i)
        puts(done1[i] && done2[i]? "1" : "0");
    
    return 0;
}
