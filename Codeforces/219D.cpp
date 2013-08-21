#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 200001

vector<int> L[MAXN],W[MAXN];
int C[MAXN];

void dfs(int pos, int p){
    for(int i = L[pos].size() - 1,to;i >= 0;--i){
        to = L[pos][i];
        
        if(to != p){
            dfs(to,pos);
            C[pos] += C[to] + W[pos][i];
        }
    }
}

int best;
vector<int> sol;

void dfs2(int pos, int p, int total = 0){
    if(C[pos] + total < best){
        best = C[pos] + total;
        sol.clear();
    }
    
    if(C[pos] + total == best)
        sol.push_back(pos);
    
    for(int i = L[pos].size() - 1,to;i >= 0;--i){
        to = L[pos][i];
        
        if(to != p) dfs2(to,pos,total + C[pos] - C[to] + 1 - 2 * W[pos][i]);
    }
}

int main(){
    int n;
    
    scanf("%d",&n);
    
    for(int i = 1,u,v;i < n;++i){
        scanf("%d %d",&u,&v);
        L[u].push_back(v);
        W[u].push_back(0);
        
        L[v].push_back(u);
        W[v].push_back(1);
    }
    
    dfs(1,0);
    
    best = n + 1;
    
    dfs2(1,0);
    
    printf("%d\n",best);
    
    sort(sol.begin(),sol.end());
    
    for(int i = 0;i < sol.size();++i)
        printf("%d ",sol[i]);
    
    printf("\n");
    
    return 0;
}
