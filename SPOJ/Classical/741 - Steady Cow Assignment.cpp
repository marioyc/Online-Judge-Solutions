#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

struct flow_graph{
    int f,MAX_V,E,s,t,head,tail;
    int *cap,*to,*next,*last,*dist,*q,*now;
    
    flow_graph(){}
    
    flow_graph(int V, int MAX_E){
        MAX_V = V; E = f = 0;
        cap = new int[2*MAX_E], to = new int[2*MAX_E], next = new int[2*MAX_E];
        last = new int[MAX_V], q = new int[MAX_V];
        dist = new int[MAX_V], now = new int[MAX_V];
        fill(last,last+MAX_V,-1);
    }
    
    void clear(){
        fill(last,last+MAX_V,-1);
        E = f = 0;
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
        int x;
		
        while(bfs()){
            for(int i = 0;i<MAX_V;++i) now[i] = last[i];
			
            while(true){
                x = dfs(s,INT_MAX);
                if(x==0) break;
                f += x;
            }
        }
		
        return f;
    }
}G(1000+20+2,1000+1000*20+20);

int main(){
	int N,B;
	scanf("%d %d",&N,&B);
	
	int choice[N][B];
	
	for(int i = 0;i<N;++i)
		for(int j = 0;j<B;++j)
			scanf("%d",&choice[i][j]);
	
	int cap[B];
	for(int i = 0;i<B;++i) scanf("%d",&cap[i]);
	
	int ans = B;
	
	for(int i = 0;i<B;++i){
		G.clear();
		for(int j = 0;j<N;++j) G.add_edge(0,1+j,1);
		for(int j = 0;j<B;++j) G.add_edge(1+N+j,1+N+B,cap[j]);
		
		for(int j = i;j<B;++j){
			for(int k = 0;k<N;++k)
				G.add_edge(1+k,N+choice[k][j],1);
			
			if(G.max_flow(0,1+N+B)==N){
				ans = min(ans,j-i+1);
				break;
			}
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}
