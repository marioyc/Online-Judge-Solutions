#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXN 100

struct flow_graph{
    static const int MAX_V = 201;
    static const int MAX_E = 10200;
    
    int E,s,t,head,tail;
    int cap[2 * MAX_E],to[2 * MAX_E],next[2 * MAX_E],last[MAX_V],dist[MAX_V],q[MAX_V],now[MAX_V];
    
    flow_graph(){
        E = 0;
        memset(last,-1,sizeof last);
    }
    
    void clear(){
        E = 0;
        memset(last,-1,sizeof last);
    }
    
    void add_edge(int u, int v, int uv){
        to[E] = v, cap[E] = uv, next[E] = last[u]; last[u] = E++;
        to[E] = u, cap[E] = 0, next[E] = last[v]; last[v] = E++;
    }

    bool bfs(){
        memset(dist,-1,sizeof dist);
        head = tail = 0;

        q[tail] = t; ++tail;
        dist[t] = 0;

        while(head < tail){
            int v = q[head]; ++head;
            
            for(int e = last[v];e != -1;e = next[e]){
                if(cap[e^1] > 0 && dist[to[e]] == -1){
                    q[tail] = to[e]; ++tail;
                    dist[to[e]] = dist[v]+1;
                }
            }
        }
        
        return dist[s] != -1;
    }

    int dfs(int v, int f){
        if(v == t) return f;

        for(int &e = now[v];e != -1;e = next[e]){
            if(cap[e] > 0 && dist[to[e]] == dist[v]-1){
                int ret = dfs(to[e],min(f,cap[e]));

                if(ret > 0){
                    cap[e] -= ret;
                    cap[e^1] += ret;
                    return ret;
                }
            }
        }

        return 0;
    }

    int max_flow(int source, int sink, int V){
        s = source; t = sink;
        int f = 0,df;

        while(bfs()){
            for(int i = 0;i < V;++i) now[i] = last[i];

            while(true){
                df = dfs(s,INT_MAX);
                if(df == 0) break;
                f += df;
            }
        }

        return f;
    }
}G;

int main(){
    int N,x[MAXN],y[MAXN],z[MAXN],f[MAXN],l[MAXN],nd;
    int M[MAXN][MAXN],d[MAXN * MAXN],aux;
    
    while(scanf("%d",&N) == 1){
        bool ok = true;
        int totalf = 0;
        
        for(int i = 0;i < N;++i){
            scanf("%d %d %d %d %d",&x[i],&y[i],&z[i],&f[i],&l[i]);
            if(i > 0 && l[i] < f[i]) ok = false;
            totalf += f[i];
        }
        
        if(!ok) printf("-1\n");
        else{
            nd = 0;
            d[nd++] = 0;
            
            for(int i = 0;i < N;++i)
                for(int j = i + 1;j < N;++j){
                    aux = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j]);
                    M[i][j] = M[j][i] = aux;
                    d[nd++] = aux;
                }
            
            sort(d,d + nd);
            
            int lo = 0,hi = nd - 1,mi;
            
            while(lo < hi){
                mi = (lo + hi) >> 1;
                int R2 = d[mi];
                
                G.clear();
                
                for(int i = 0;i < N;++i){
                    G.add_edge(0,2 * i + 1,f[i]);
                    G.add_edge(2 * i + 1,2 * i + 2,l[i]);
                }
                
                for(int i = 0;i < N;++i)
                    for(int j = i + 1;j < N;++j)
                        if(M[i][j] <= R2){
                            G.add_edge(2 * i + 2,2 * j + 1,1000000000);
                            G.add_edge(2 * j + 2,2 * i + 1,1000000000);
                        }
                
                if(G.max_flow(0,1,2 * N + 1) < totalf) lo = mi + 1;
                else hi = mi;
            }
            
            printf("%.7f\n",sqrt(d[lo]));
        }
    }
    
    return 0;
}
