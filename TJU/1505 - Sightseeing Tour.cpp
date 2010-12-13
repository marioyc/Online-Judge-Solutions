#include <cstdio>
#include <climits>
#include <algorithm>

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
    
    void add_edge(int u, int v, int uv, int vu = 0){
        to[E] = v, cap[E] = uv, next[E] = last[u]; last[u] = E++;
        to[E] = u, cap[E] = vu, next[E] = last[v]; last[v] = E++;
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
};

int main(){
    int T,V,E,deg[200];
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&V,&E);
        flow_graph G(E+V+2,E+V+2*E);
        
        for(int i = 0;i<E;++i) G.add_edge(0,1+i,1);
        
        fill(deg,deg+V,0);
        
        for(int i = 0,u,v,d;i<E;++i){
            scanf("%d %d %d",&u,&v,&d);
            ++deg[--u]; ++deg[--v];
            
            G.add_edge(1+i,1+E+v,1);
            if(d==0) G.add_edge(1+i,1+E+u,1);
        }
        
        bool possible = true;
        
        for(int i = 0;i<V;++i)
            if(deg[i] & 1)
                possible = false;
        
        if(!possible){
            puts("impossible");
            continue;
        }
        
        for(int i = 0;i<V;++i) G.add_edge(1+E+i,1+E+V,(deg[i]>>1));
        
        if(G.max_flow(0,1+E+V)==E) puts("possible");
        else puts("impossible");
    }
    
    return 0;
}
