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
        last = new int[MAX_V], q = new int[MAX_V], dist = new int[MAX_V], now = new int[MAX_V];
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
		int f = 0,x;
		
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
}G(100+3,100*99/2+2*100+1);

int n,m,k,l,g,u[4950],v[4950],cap[4950],s[100],e[100];

void build_graph(int mx){
	G.clear();
	G.add_edge(0,1,g);
	
	for(int i = 0;i<k;++i) G.add_edge(1,2+s[i],g);
	for(int i = 0;i<l;++i) G.add_edge(2+e[i],n+2,g);
	for(int i = 0;i<m;++i) if(cap[i]<=mx) G.add_edge(2+u[i],2+v[i],cap[i],cap[i]);
}

int main(){
	int T,c[4950];
	scanf("%d",&T);
	
	for(int tc = 1;tc<=T;++tc){
		scanf("%d %d %d %d %d",&n,&m,&k,&l,&g);
		
		for(int i = 0;i<m;++i){
			scanf("%d %d %d",&u[i],&v[i],&cap[i]);
			--u[i]; --v[i];
			c[i] = cap[i];
		}
		
		sort(c,c+m);
		
		for(int i = 0;i<k;++i){
			scanf("%d",&s[i]);
			--s[i];
		}
		
		for(int i = 0;i<l;++i){
			scanf("%d",&e[i]);
			--e[i];
		}
		
		int lo = 0,hi = m-1,mi;
		
		while(lo<hi){
			mi = (lo+hi)/2;
			build_graph(c[mi]);
			
			if(G.max_flow(0,n+2)==g) hi = mi;
			else lo = mi+1;
		}
		
		build_graph(c[lo]);
		
		if(G.max_flow(0,n+2)==g) printf("%d\n",c[lo]*100);
		else printf("-1\n");
	}
	
	return 0;
}
