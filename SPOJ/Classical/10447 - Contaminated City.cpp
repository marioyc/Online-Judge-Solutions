#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

const int INF = 100000000;

struct flow_graph{
    int MAX_V,E,s,t,head,tail;
    int *cap,*to,*next,*last,*dist,*q,*now;
    
    flow_graph(){}
    
    flow_graph(int V, int MAX_E){
        MAX_V = V; E = 0;
        cap = new int[2*MAX_E], to = new int[2*MAX_E], next = new int[2*MAX_E];
        last = new int[MAX_V], q = new int[MAX_V];
        dist = new int[MAX_V], now = new int[MAX_V];
        fill(last,last+MAX_V,-1);
    }
    
    void clear(){
        fill(last,last+MAX_V,-1);
        E = 0;
    }
    
    void add_edge(int u, int v, int uv){
        to[E] = v, cap[E] = uv, next[E] = last[u]; last[u] = E++;
        to[E] = u, cap[E] = 0, next[E] = last[v]; last[v] = E++;
    }
  
    bool bfs(){
        fill(dist,dist+MAX_V,-1);
        head = tail = 0;
    
        q[tail] = t; ++tail;
        dist[t] = 0;
    
        while(head<tail){
            int v = q[head]; ++head;
            
            for(int e = last[v];e!=-1;e = next[e]){
                if(cap[e^1]>0 && dist[to[e]]==-1){
                    q[tail] = to[e]; ++tail;
                    dist[to[e]] = dist[v]+1;
                }
            }
        }
        
        return dist[s]!=-1;
    }
  
    int dfs(int v, int f){
        if(v==t) return f;
    
        for(int &e = now[v];e!=-1;e = next[e]){
            if(cap[e]>0 && dist[to[e]]==dist[v]-1){
                int ret = dfs(to[e],min(f,cap[e]));
        
                if(ret>0){
                    cap[e] -= ret;
                    cap[e^1] += ret;
                    return ret;
                }
            }
        }
    
        return 0;
    }
  
    int max_flow(int source, int sink){
        s = source; t = sink;
        int f = 0,df;
    
        while(bfs()){
            for(int i = 0;i<MAX_V;++i) now[i] = last[i];
      
            while(true){
                df = dfs(s,INT_MAX);
                if(df==0) break;
                f += df;
            }
        }
    
        return f;
    }
}G(102,50 + 50 * 50 + 50);

int main(){
    int T,N,M,H;
    int surv[50];
    int d[50],p[50],cap[50];
    double dist[50][50],c;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&N,&M,&H);
        assert(N >= 1 && N <= 50 && M >= 1 && M <= 1500 && H >= 1 && H <= 50);
        
        int total = 0;
        
        for(int i = 0;i < N;++i){
            scanf("%d",&surv[i]);
            total += surv[i];
        }
        
        for(int i = 0;i < N;++i){
            dist[i][i] = 0;
            
            for(int j = i + 1;j < N;++j)
                dist[i][j] = dist[j][i] = INF;
        }
        
        for(int i = 0,a,b;i < M;++i){
            scanf("%d %d %lf",&a,&b,&c);
            --a; --b;
            
            dist[a][b] = min(dist[a][b],c);
            dist[b][a] = dist[a][b];
        }
        
        for(int k = 0;k < N;++k)
            for(int i = 0;i < N;++i)
                for(int j = 0;j < N;++j)
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
        
        for(int i = 0;i < H;++i){
            scanf("%d %d %d",&d[i],&p[i],&cap[i]);
            --p[i];
        }
        
        int lo = 0,hi = 10000000,mi;
        
        while(lo < hi){
            mi = (lo + hi) >> 1;
            
            G.clear();
            
            for(int i = 0;i < N;++i)
                G.add_edge(0,1 + i,surv[i]);
            
            for(int i = 0;i < N;++i){
                for(int j = 0;j < H;++j){
                    if(d[j] <= mi && dist[i][ p[j] ] <= mi + 1e-7)
                        G.add_edge(1 + i,1 + N + j,INF);
                }
            }
            
            for(int i = 0;i < H;++i)
                G.add_edge(1 + N + i,1 + N + H,cap[i]);
            
            if(G.max_flow(0,1 + N + H) == total) hi = mi;
            else lo = mi + 1;
        }
        
        G.clear();
        
        for(int i = 0;i < N;++i)
            G.add_edge(0,1 + i,surv[i]);
        
        for(int i = 0;i < N;++i){
            for(int j = 0;j < H;++j){
                if(d[j] <= lo && dist[i][ p[j] ] <= lo + 1e-7)
                    G.add_edge(1 + i,1 + N + j,INF);
            }
        }
        
        for(int i = 0;i < H;++i)
            G.add_edge(1 + N + i,1 + N + H,cap[i]);
        
        int save = G.max_flow(0,1 + N + H);
        
        if(save == total) printf("All people can be rescued in %d day(s).\n",lo);
        else printf("%d survivor(s) can be rescued.\n",save);
    }
    
    return 0;
}
