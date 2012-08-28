#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define MAXV 2000

int V;
vector<int> L[MAXV];
stack<int> S;
int low[MAXV],scc[MAXV],cont;
bool in_stack[MAXV];

void dfs(int cur, int p, int lvl){
    low[cur] = lvl;
    S.push(cur);
    in_stack[cur] = true;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(low[to] != -1 && in_stack[to]) low[cur] = min(low[cur],low[to]);
        else if(low[to] == -1){
            dfs(to,cur,lvl + 1);
            low[cur] = min(low[cur],low[to]);
        }
    }
    
    if(low[cur] == lvl){
        while(!S.empty()){
            int x = S.top();
            scc[x] = cont;
            in_stack[x] = false;
            S.pop();
            
            if(x == cur) break;
        }
        
        ++cont;
    }
}

int main(){
    int N,M;
    char s1[2],s2[2],c1,c2;
    int x,y;
    
    while(scanf("%d %d",&N,&M) == 2){
        V = 2 * N;
        
        for(int i = 0;i < V;++i)
            L[i].clear();
        
        for(int i = 0;i < M;++i){
            scanf("%d %d",&x,&y);
            
            c1 = (x > 0? '+' : '-'); x = abs(x);
            c2 = (y > 0? '+' : '-'); y = abs(y);
            
            if(c1 == '+' && c2 == '+'){
                L[2 * x - 2].push_back(2 * y - 1);
                L[2 * y - 2].push_back(2 * x - 1);
            }
            
            if(c1 == '+' && c2 == '-'){
                L[2 * x - 2].push_back(2 * y - 2);
                L[2 * y - 1].push_back(2 * y - 1);
            }
            
            if(c1 == '-' && c2 == '-'){
                L[2 * x - 1].push_back(2 * y - 2);
                L[2 * y - 1].push_back(2 * x - 2);
            }
            
            if(c1 == '-' && c2 == '+'){
                L[2 * x - 1].push_back(2 * y - 1);
                L[2 * y - 2].push_back(2 * x - 2);
            }
        }
        
        memset(in_stack,false,sizeof in_stack);
        memset(low,-1,sizeof low);
        cont = 0;
        
        for(int i = 0;i < V;++i)
            if(low[i] == -1)
                dfs(i,-1,0);
        
        int ans = 1;
        
        for(int i = 0;i < V;i += 2)
            if(scc[i] == scc[i + 1])
                ans = 0;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
