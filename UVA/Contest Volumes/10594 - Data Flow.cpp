#include <cstdio>
#include <climits>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

#define MAX_V 1+2*100
#define MAX_E 2*10001
typedef long long edge_type;
const edge_type INF = LLONG_MAX;

int V,E,prev[MAX_V],last[MAX_V];
edge_type flowVal,flowCost,cap[MAX_E],cost[MAX_E],to[MAX_E],next[MAX_E],dist[MAX_V],pot[MAX_V];

void init(){
   memset(last,-1,sizeof(last));
   E = 0;
}

void add_edge(int u, int v, edge_type capacity, edge_type cst){
	to[E] = v, cap[E] = capacity;
	cost[E] = cst, next[E] = last[u];
	last[u] = E++;
	
	to[E] = u, cap[E] = 0;
	cost[E] = -cst, next[E] = last[v];
	last[v] = E++;
}

void mcmf(int s, int t){
	flowVal = flowCost = 0;
	memset(pot,0,sizeof(pot));
	
	while(true){
		memset(prev,-1,sizeof(prev));
		for(int i = 0;i<V;++i) dist[i] = INF;
		
		set< pair<edge_type, int> > Q;
		Q.insert(make_pair(0,s));
		dist[s] = prev[s] = 0;
      	
		while(!Q.empty()){
			int aux = Q.begin()->second; Q.erase(Q.begin());
			
			for(int e = last[aux];e!=-1;e = next[e]){
				if(cap[e]<=0) continue;
				
				edge_type new_dist = dist[aux]+cost[e]+pot[aux]-pot[to[e]];
				
				if(new_dist<dist[to[e]]){
					Q.erase(make_pair(dist[to[e]],to[e]));
					dist[to[e]] = new_dist;
					prev[to[e]] = e;
					Q.insert(make_pair(new_dist,to[e]));
				}
			}
		}
		
		if (prev[t]==-1) break;
		
		edge_type f = INF;
		
		for(int i = t;i!=s;i = to[prev[i]^1]) f = min(f,cap[prev[i]]);
		
		for(int i = t;i!=s;i = to[prev[i]^1]){
			cap[prev[i]] -= f;
			cap[prev[i]^1] += f;
		}
		
		flowVal += f;
		flowCost += f*(dist[t]-pot[s]+pot[t]);
		
		for(int i = 0;i<V;++i) if (prev[i]!=-1) pot[i] += dist[i];
	}
}

int main(){
	int N,M,u[5000],v[5000];
	long long cst[5000],D,K;
	
	while(scanf("%d %d",&N,&M)==2){
		V = 2*N+1;
		
		for(int i = 0;i<M;++i){
			scanf("%d %d %lld",&u[i],&v[i],&cst[i]);
			--u[i]; --v[i];
		}
		scanf("%lld %lld",&D,&K);
		
		init();
		add_edge(0,1,D,0);
		
		for(int i = 0;i<N;++i) add_edge(1+2*i,1+2*i+1,INF,0);
		
		for(int i = 0;i<M;++i){
			add_edge(1+2*u[i]+1,1+2*v[i],K,cst[i]);
			add_edge(1+2*v[i]+1,1+2*u[i],K,cst[i]);
		}
		
		mcmf(0,2*N-1);
		
		if(flowVal!=D) printf("Impossible.\n");
		else printf("%lld\n",flowCost);
	}
	
	return 0;
}
