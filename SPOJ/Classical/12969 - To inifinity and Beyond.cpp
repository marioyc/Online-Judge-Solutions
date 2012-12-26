#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define MAXN 251

int V;
vector<int> adj[MAXN];
int dfn[MAXN],low[MAXN];
vector< vector<int> > C;
stack< pair<int, int> > stk;

void cache_bc(int x, int y){
    vector<int> com;
    int tx,ty;
    
    do{
        tx = stk.top().first, ty = stk.top().second;
        stk.pop();
        com.push_back(tx), com.push_back(ty);
    }while(tx!=x || ty!=y);
    
    C.push_back(com);
}

void DFS(int cur, int prev, int number){
    dfn[cur] = low[cur] = number;
    
    for(int i = adj[cur].size()-1;i>=0;--i){
        int next = adj[cur][i];
        if(next==prev) continue;
        if(dfn[next]==-1){
            stk.push(make_pair(cur,next));
            DFS(next,cur,number+1);
            low[cur] = min(low[cur], low[next]);
            if(low[next]>=dfn[cur]) cache_bc(cur,next);
        }else low[cur] = min(low[cur],dfn[next]);
    }
}

bool used[MAXN];
int a[MAXN],b[MAXN];
vector<int> c;

void biconn_comp(){
    memset(dfn,-1,sizeof(dfn));
    C.clear();
    
    for(int i = 0;i < V;++i)
        if(dfn[i] == -1) DFS(i,i,0);
    
    int comp = C.size();
    memset(used,false,sizeof used);
    c.clear();
    
    for(int i = 0;i < comp;++i){
        sort(C[i].begin(),C[i].end());
        C[i].erase(unique(C[i].begin(),C[i].end()),C[i].end());
        int m = C[i].size();
        
        if(m > 2){
            int val = 0;
            
            for(int j = 0;j < m;++j){
                val += a[ C[i][j] ];
                used[ C[i][j] ] = true;
            }
            
            c.push_back(val);
        }
    }
    
    for(int i = 0;i < V;++i)
        if(!used[i])
            c.push_back(a[i]);
}

vector<int> L[MAXN];
bool visited[MAXN];
int ri[MAXN],le[MAXN];

bool dfs(int cur){
    if(visited[cur]) return false;
    visited[cur] = true;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(le[to] == -1 || dfs(le[to])){
            le[to] = cur;
            ri[cur] = to;
            return true;
        }
    }
    
    return false;
}

int main(){
    int T,tc = 1,E,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&V,&E,&N);
        
        for(int i = 0;i < V;++i) scanf("%d",&a[i]);
        for(int i = 0;i < N;++i) scanf("%d",&b[i]);
        for(int i = 0;i < V;++i) adj[i].clear();
        
        for(int i = 0,u,v;i < E;++i){
            scanf("%d %d",&u,&v);
            --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        biconn_comp();
        
        int M = c.size();
        
        printf("Buzz Mission %d: %d ",tc++,M);
        
        if(M > N) puts("No");
        else{
            int lo = 0,hi = 1000000,mi;
            
            while(lo < hi){
                mi = (lo + hi) >> 1;
                
                for(int i = 0;i < M;++i){
                    L[i].clear();
                    
                    for(int j = 0;j < N;++j)
                        if(abs(c[i] - b[j]) <= mi)
                            L[i].push_back(j);
                }
                
                int match = 0;
                bool found = true;
                memset(le,-1,sizeof le);
                memset(ri,-1,sizeof ri);
                
                while(found){
                    memset(visited,false,sizeof visited);
                    found = false;
                    
                    for(int i = 0;i < M;++i)
                        if(ri[i] == -1 && dfs(i))
                            ++match, found = true;
                }
                
                if(match < M) lo = mi + 1;
                else hi = mi;
            }
            
            printf("%d\n",lo);
        }
    }
    
    return 0;
}
