#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 20001
#define MAXE 200000

int E = 0,to[MAXE],nxt[MAXE],last[MAXN];

void add_edge(int u, int v){
    to[E] = v; nxt[E] = last[u]; last[u] = E++;
    to[E] = u; nxt[E] = last[v]; last[v] = E++;
}

int parent[MAXN],level[MAXN];
vector<int> in[MAXN];

void dfs(int pos, int lvl){
    level[pos] = lvl;
    bool back = true;
    
    for(int e = last[pos];e != -1;e = nxt[e]){
        int x = to[e];
        
        if(x == parent[pos]){
            if(!back) in[x].push_back(pos);
            back = false;
        }else if(parent[x] != -1){
            if(level[x] < lvl)
                in[x].push_back(pos);
        }else{
            parent[x] = pos;
            
            dfs(x,lvl + 1);
        }
    }
    
    int sz = in[pos].size();
    bool odd = false;
    
    for(int i = 0;i < sz;i += 2){
        if(i + 1 < sz){
            printf("%d %d %d\n",in[pos][i],pos,in[pos][i + 1]);
        }else{
            odd = true;
            printf("%d %d %d\n",in[pos][i],pos,parent[pos]);
        }
    }
    
    if(!odd)
        in[ parent[pos] ].push_back(pos);
}

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    memset(last,-1,sizeof last);
    
    for(int i = 0,u,v;i < m;++i){
        scanf("%d %d",&u,&v);
        add_edge(u,v);
    }
    
    memset(parent,-1,sizeof parent);
    parent[1] = 0;
    
    dfs(1,0);
    
    return 0;
}
