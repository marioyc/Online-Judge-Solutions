#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

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
}G(2+50+50,50+50*50+50);

int main(){
    int N,M,K;
    bool adj[50][50];
    
    while(scanf("%d %d %d",&N,&M,&K)==3){
        if(N==0) break;
        
        memset(adj,false,sizeof(adj));
        
        for(int i = 0,sz,x;i<N;++i){
            scanf("%d",&sz);
            
            for(int j = 0;j<sz;++j){
                scanf("%d",&x);
                adj[i][--x] = true;
            }
        }
        
        int ans = 0;
        
        for(int i = 1;i<=K;++i){
            G.clear();
            
            for(int j = 0;j<N;++j) G.add_edge(0,1+j,i);
            
            for(int j = 0;j<N;++j)
                for(int k = 0;k<M;++k)
                    if(adj[j][k])
                        G.add_edge(1+j,1+N+k,1);
            
            for(int j = 0;j<M;++j) G.add_edge(1+N+j,1+N+M,K);
            
            int f = G.max_flow(0,1+N+M);
            
            if(f==i*N) ++ans;
            else break;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
