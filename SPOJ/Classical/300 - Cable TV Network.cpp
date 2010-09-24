#include <cstdio>
#include <climits>
#include <cstring>
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
}G(2*50,50*49/2+50);

int main(){
	int T,n,m,cont[50][50],u,v,ans;
	char s[8];
	
	scanf("%d",&T);
	
	for(int tc = 1;tc<=T;++tc){
		scanf("%d %d",&n,&m);
		
		memset(cont,0,sizeof(cont));
		
		for(int i = 0;i<m;++i){
			scanf("%s",s);
			sscanf(s,"(%d,%d)",&u,&v);
			++cont[u][v];
			++cont[v][u];
		}
		
		ans = n;
		
		for(int i = 0;i<n;++i){
			for(int j = i+1;j<n;++j){
				G.clear();
				for(int k = 0;k<n;++k) G.add_edge(2*k,2*k+1,1);
				
				for(int a = 0;a<n;++a) for(int b = 0;b<n;++b){
					if(cont[a][b]==0) continue;
					G.add_edge(2*a+1,2*b,n+1);
				}
				
				ans = min(ans,G.max_flow(2*i+1,2*j));
			}
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
