#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define MAXV 2000

int V,E;
vector<int> L[MAXV + 1];

int level[MAXV + 1],low[MAXV + 1],num_scc;
bool in_stack[MAXV + 1];
stack<int> S;

void tarjan(int pos, int lvl){
    level[pos] = low[pos] = lvl;
    S.push(pos);
    in_stack[pos] = true;
    
    for(int i = L[pos].size() - 1,to;i >= 0;--i){
        to = L[pos][i];
        
        if(level[to] == -1){
            tarjan(to,lvl + 1);
            low[pos] = min(low[pos],low[to]);
        }else if(in_stack[to]) low[pos] = min(low[pos],low[to]);
    }
    
    if(low[pos] == lvl){
        while(true){
            int cur = S.top();
            S.pop();
            in_stack[cur] = true;
            if(cur == pos) break;
        }
        
        num_scc++;
    }
}

int main(){
    while(true){
        scanf("%d %d",&V,&E);
        if(V == 0) break;
        
        for(int i = 1;i <= V;++i)
            L[i].clear();
        
        for(int i = 0,u,v,t;i < E;++i){
            scanf("%d %d %d",&u,&v,&t);
            
            L[u].push_back(v);
            if(t == 2) L[v].push_back(u);
        }
        
        memset(level,-1,sizeof level);
        memset(in_stack,false,sizeof in_stack);
        num_scc = 0;
        
        for(int i = 1;i <= V;++i)
            if(level[i] == -1)
                tarjan(i,0);
        
        printf("%d\n",(num_scc == 1)? 1 : 0);
    }
    
    return 0;
}
