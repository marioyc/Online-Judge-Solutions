#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 2001
#define MAXE 2 * 100000

int E = 0,last[MAXN],nxt[MAXE],to[MAXE];

void add_edge(int u, int v){
    to[E] = v; nxt[E] = last[u]; last[u] = E++;
    to[E] = u; nxt[E] = last[v]; last[v] = E++;
}

bool visited[MAXN];
vector<int> path;
int f[MAXN][MAXN];
int parent[MAXN],level[MAXN],low[MAXN],cont = 0;
bool bridge[MAXN];

void dfs(int pos, int lvl){
    visited[pos] = true;
    level[pos] = low[pos] = lvl;
    bool back = true;
    
    path.push_back(pos);
    
    for(int e = last[pos];e != -1;e = nxt[e]){
        if(to[e] == parent[pos]){
            if(!back){
                low[pos] = min(low[pos],lvl - 1);
                ++f[pos][ to[e] ];
            }
            
            back = false;
        }else if(visited[ to[e] ]){
            low[pos] = min(low[pos],level[ to[e] ]);
            ++f[pos][ to[e] ];
        }else{
            parent[ to[e] ] = pos;
            
            dfs(to[e],lvl + 1);
            
            low[pos] = min(low[pos],low[ to[e] ]);
            
            if(low[ to[e] ] > lvl){
                bridge[ to[e] ] = true;
                ++cont;
            }
        }
    }
    
    path.pop_back();
}

void dfs2(int pos, int lvl){
    visited[pos] = true;
    path.push_back(pos);
    
    for(int e = last[pos];e != -1;e = nxt[e]){
        if(!visited[ to[e] ]){
            dfs2(to[e],lvl + 1);
            
            for(int i = lvl - 1;i >= 0;--i)
                f[pos][ path[i] ] += f[ to[e] ][ path[i] ];
        }
    }
    
    path.pop_back();
}

void dfs3(int pos, int lvl){
    visited[pos] = true;
    path.push_back(pos);
    
    for(int i = 1;i < lvl;++i)
        f[pos][ path[i] ] += f[pos][ path[i - 1] ];
    
    for(int e = last[pos];e != -1;e = nxt[e])
        if(!visited[ to[e] ])
            dfs3(to[e],lvl + 1);
    
    path.pop_back();
}

int ans = 0,M;

void dfs4(int pos, int lvl){
    visited[pos] = true;
    path.push_back(pos);
    
    if(bridge[pos]) ans += M - 1;
    else{
        if(lvl > 0 && f[pos][ parent[pos] ] == 1) ++ans;
        
        for(int i = lvl - 1;i > 0;--i){
            if(!bridge[ path[i] ]
                && !(f[ path[i] ][ path[i - 1] ] - f[pos][ path[i - 1] ] > 0 && f[pos][ path[i - 1] ] > 0)
                && !(f[ path[i] ][ path[i - 1] ] - f[pos][ path[i - 1] ] > 0 && f[pos][ parent[pos] ] - f[pos][ path[i - 1] ] > 0)
                && !(f[pos][ path[i - 1] ] > 0 && f[pos][ parent[pos] ] - f[pos][ path[i - 1] ] > 0))
                    ++ans;
        }
    }
    
    for(int e = last[pos];e != -1;e = nxt[e])
        if(!visited[ to[e] ])
            dfs4(to[e],lvl + 1);
    
    path.pop_back();
}

int main(){
    int N;
    
    scanf("%d %d",&N,&M);
    
    memset(last,-1,sizeof last);
    
    for(int i = 0,u,v;i < M;++i){
        scanf("%d %d",&u,&v);
        add_edge(u,v);
    }
    
    dfs(1,0);
    
    memset(visited,0,sizeof visited);
    dfs2(1,0);
    
    memset(visited,0,sizeof visited);
    dfs3(1,0);
    
    memset(visited,0,sizeof visited);
    dfs4(1,0);
    
    ans -= cont * (cont - 1) / 2;
    
    printf("%d\n",ans);
    
    return 0;
}
