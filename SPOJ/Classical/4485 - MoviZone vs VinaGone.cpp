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
        long long f = 0, df;
		
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
    int N;
    scanf("%d",&N);
    
    flow_graph G(N+2,2*N+N*(N-1)/2);
    G.clear();
    
    int cap;
    
    for(int i = 0;i<N;++i){
        scanf("%d",&cap);
        G.add_edge(0,1+i,cap);
    }
    
    for(int i = 0;i<N;++i){
        scanf("%d",&cap);
        G.add_edge(1+i,1+N,cap);
    }
    
    for(int i = 0;i<N;++i){
        for(int j = 0;j<N;++j){
            scanf("%d",&cap);
            if(i<j) G.add_edge(1+i,1+j,cap,cap);
        }
    }
    
    printf("%d\n",G.max_flow(0,1+N));
    
    return 0;
}
