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
    
    void clear(){
        fill(last,last+MAX_V,-1);
        E = 0;
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
    int T,n,m,k;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&n,&m,&k);
        
        int *U,*V,*house;
        
        U = new int[m];
        V = new int[m];
        house = new int[k];
        
        flow_graph G(n+1,m+n);
        
        for(int i = 0;i<k;++i) scanf("%d",&house[i]);
        
        for(int i = 0;i<m;++i) scanf("%d %d",&U[i],&V[i]);
        
        int lo = 0,hi = n,mi;
        
        while(lo!=hi){
            mi = (lo+hi)>>1;
            
            G.clear();
            
            for(int i = 0;i<k;++i)
                G.add_edge(house[i]-1,n,1);
            
            for(int i = 0;i<m;++i)
                G.add_edge(U[i]-1,V[i]-1,mi,mi);
            
            if(G.max_flow(0,n)==k) hi = mi;
            else lo = mi+1;
        }
        
        printf("%d\n",lo);
    }
    
    return 0;
}
