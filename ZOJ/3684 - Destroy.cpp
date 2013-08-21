#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 10005

struct edge{
    int id,to,l,p;
    
    edge(){}
    edge(int _id, int _to, int _l, int _p):
        id(_id), to(_to), l(_l), p(_p){}
};

vector<edge> L[MAXN];

int memo[MAXN][2];

int solve(int cur, int p, int id){
    int &ret = memo[id][(cur < p? 0 : 1)];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = L[cur].size() - 1,to;i >= 0;--i){
            to = L[cur][i].to;
            if(to != p) ret = max(ret,L[cur][i].l + solve(to,cur,L[cur][i].id));
        }
    }
    
    return ret;
}

int d[MAXN];
bool visited[MAXN];
int mi;

bool dfs(int cur){
    if(visited[cur]) return false;
    if(d[cur] == 1) return true;
    visited[cur] = true;
    
    for(int i = L[cur].size() - 1;i >= 0;--i)
        if(L[cur][i].p > mi && dfs(L[cur][i].to))
            return true;
    
    return false;
}

int main(){
    int n;
    
    while(scanf("%d",&n) == 1){
        for(int i = 1;i <= n;++i) L[i].clear();
        memset(d,0,sizeof d);
        
        for(int i = 1,u,v,l,p;i < n;++i){
            scanf("%d %d %d %d",&u,&v,&l,&p);
            L[u].push_back(edge(i,v,l,p));
            L[v].push_back(edge(i,u,l,p));
            ++d[u]; ++d[v];
        }
        
        memset(memo,-1,sizeof memo);
        int r = -1,best;
        
        for(int i = 1;i <= n;++i){
            int cur = 0;
            
            for(int j = L[i].size() - 1,to;j >= 0;--j){
                to = L[i][j].to;
                cur = max(cur,L[i][j].l + solve(to,i,L[i][j].id));
            }
            
            if(r == -1 || cur < best){
                best = cur;
                r = i;
            }
        }
        
        int lo = 0,hi = 100000000;
        
        while(lo < hi){
            mi = (lo + hi) >> 1;
            
            memset(visited,false,sizeof visited);
            
            if(dfs(r)) lo = mi + 1;
            else hi = mi;
        }
        
        printf("%d\n",lo);
    }
    
    return 0;
}
