#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

void read_int(int &n){
    char c;
    bool found = false;
    n = 0;
    
    while(true){
      c = getc(stdin);
      
        switch(c){
            case ' ':
                if(found) goto jump;
                break;
            case '\n':
                if(found) goto jump;
                break;
            default:
                if(c>='0' && c<='9'){
                    n = n*10+c-'0';
                    found = true;
                }else goto jump;
                break;
        }
    }
    
    jump:;
}

#define MAXN 100001
#define MAXE 500000

int last[MAXN],nxt[2 * MAXE],to[2 * MAXE],ne = 0;

void add_edge(int &u, int &v){
    to[ne] = v; nxt[ne] = last[u]; last[u] = ne++;
    to[ne] = u; nxt[ne] = last[v]; last[v] = ne++;
}

int low[MAXN],parent[MAXN],level[MAXN],comp[MAXN];

void dfs(int r){
    int u,v;
        
    stack<int> S;
    
    S.push(r);
    comp[r] = r;
    low[r] = level[r] = 0;
    parent[r] = -1;

    while(!S.empty()){
        u = S.top();
        
        for(int &e = last[u];e != -1;e = nxt[e]){
            v = to[e];
            
            if(comp[v] != -1 && v != parent[u] && level[u] > level[v]){
                low[u] = min(low[u],level[v]);
            }else if(comp[v] == -1){
                S.push(v);
                comp[v] = r;
                low[v] = level[v] = level[u] + 1;
                parent[v] = u;
                break;
            }
        }
        
        if(last[u] == -1){
            S.pop();
            if(u != r)
                low[ parent[u] ] = min(low[ parent[u] ],low[u]);
        }
    }
}

int p[17][MAXN];

int lca(int u, int v){
    if(level[u] < level[v]) swap(u,v);
    
    int diff = level[u] - level[v];
    
    while(diff){
        int z = __builtin_ctz(diff);
        diff ^= (1 << z);
        u = p[z][u];
    }
    
    if(u == v) return u;
    
    for(int i = 16;i >= 0;--i)
        if(p[i][u] != p[i][v]){
            u = p[i][u];
            v = p[i][v];
        }
    
    return p[0][u];
}

int up(int u, int n){
    while(n){
        int z = __builtin_ctz(n);
        n ^= (1 << z);
        u = p[z][u];
    }
    
    return u;
}

int main(){
    int V,E,Q;
    
    read_int(V); read_int(E);
    memset(last,-1,sizeof last);
    
    for(int i = 0,u,v;i < E;++i){
        read_int(u); read_int(v);
        add_edge(u,v);
    }
    
    memset(comp,-1,sizeof comp);
    
    for(int i = 1;i <= V;++i)
        if(comp[i] == -1)
            dfs(i);
    
    for(int i = 1;i <= V;++i)
        p[0][i] = parent[i];
    
    for(int i = 1;i <= 16;++i){
        for(int j = 1;j <= V;++j){
            if(p[i - 1][j] == -1) p[i][j] = -1;
            else p[i][j] = p[i - 1][ p[i - 1][j] ];
        }
    }
    
    read_int(Q);
    int op,A,B,C,D;
    
    while(Q--){
        read_int(op);
        read_int(A); read_int(B);
        
        if(op == 1){
            read_int(C); read_int(D);
            
            if(comp[A] != comp[B]) puts("ne");
            else{
                int r = lca(A,B);
                bool ok = true;
                
                if(level[C] < level[D]) swap(C,D);
                
                if(level[A] >= level[C] && level[C] > level[r]){
                    int x = up(A,level[A] - level[C]);
                    if(x == C && parent[x] == D && low[x] == level[x]) ok = false;
                }
                
                if(level[B] >= level[C] && level[C] > level[r]){
                    int x = up(B,level[B] - level[C]);
                    if(x == C && parent[x] == D && low[x] == level[x]) ok = false;
                }
                
                puts(ok? "da" : "ne");
            }
        }else{
            read_int(C);
            
            if(C == A || C == B || comp[A] != comp[B]) puts("ne");
            else if(A == B) puts("da");
            else{
                int r = lca(A,B);
                bool ok = true;
                
                if(level[A] > level[C] && level[C] >= level[r]){
                    int x = up(A,level[A] - level[C] -  1);
                    if(parent[x] == C && low[x] >= level[C]) ok = false;
                }
                if(level[B] > level[C] && level[C] >= level[r]){
                    int x = up(B,level[B] - level[C] - 1);
                    if(parent[x] == C && low[x] >= level[C]) ok = false;
                }
                
                puts(ok? "da" : "ne");
            }
        }
    }
    
    return 0;
}
