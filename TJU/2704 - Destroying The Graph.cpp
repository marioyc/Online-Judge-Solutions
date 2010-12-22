#include <cstdio>
#include <cstring>
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
    int V,E;
    scanf("%d %d",&V,&E);
    flow_graph G(2+2*V,2*V+E);
    
    for(int i = 0,Win;i<V;++i){
        scanf("%d",&Win);
        G.add_edge(1+V+i,1+2*V,Win);
    }
    
    for(int i = 0,Wout;i<V;++i){
        scanf("%d",&Wout);
        G.add_edge(0,1+i,Wout);
    }
    
    for(int i = 0,u,v;i<E;++i){
        scanf("%d %d",&u,&v);
        --u; --v;
        G.add_edge(1+u,1+V+v,INT_MAX);
    }
    
    printf("%d\n",G.max_flow(0,1+2*V));
    
    bool visited[2+2*V];
    memset(visited,false,sizeof(visited));
    
    int Q[2+2*V],tail = 1;
    
    visited[0] = true;
    Q[0] = 0;
    
    for(int head = 0;head<tail;++head){
        int cur = Q[head];
        
        for(int e = G.last[cur];e!=-1;e = G.next[e]){
            if(G.cap[e]>0){
                int nxt = G.to[e];
                
                if(!visited[nxt]){
                    visited[nxt] = true;
                    Q[tail] = nxt; ++tail;
                }
            }
        }
    }
    
    int cont = 0;
    
    for(int e = 0;e<G.E;e += 2){
        if(G.cap[e]==0){
            int u = G.to[e ^ 1],v = G.to[e];
            if(visited[u] && !visited[v]) ++cont;
        }
    }
    
    printf("%d\n",cont);
    
    for(int e = 0;e<G.E;e += 2){
        if(G.cap[e]==0){
            int u = G.to[e ^ 1],v = G.to[e];
            
            if(visited[u] && !visited[v]){
                if(u==0) printf("%d -\n",v);
                else printf("%d +\n",u-V);
            }
        }
    }
    
    return 0;
}
