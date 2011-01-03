#include <cstdio>
#include <climits>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

#define MAX_V 42
#define MAX_E 2*440

typedef int cap_type;
typedef double cost_type;
const cost_type INF = 1e10;

int V,E,prev[MAX_V],last[MAX_V],to[MAX_E],next[MAX_E];
bool visited[MAX_V];
cap_type flowVal, cap[MAX_E];
cost_type flowCost,cost[MAX_E],dist[MAX_V],pot[MAX_V];

void init(int _V){
	memset(last,-1,sizeof(last));
	V = _V; E = 0;
}

void add_edge(int u, int v, cap_type capacity, cost_type cst){
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
		memset(visited,false,sizeof(visited));
		for(int i = 0;i<V;++i) dist[i] = INF;
		
		priority_queue< pair<cost_type, int> > Q;
		Q.push(make_pair(0,s));
		dist[s] = prev[s] = 0;
		
		while(!Q.empty()){
			int aux = Q.top().second;
			Q.pop();
			
			if(visited[aux]) continue;
			visited[aux] = true;
			
			for(int e = last[aux];e!=-1;e = next[e]){
				if(cap[e]<=0) continue;
				cost_type new_dist = dist[aux]+cost[e]+pot[aux]-pot[to[e]];
				if(new_dist<dist[to[e]]){
					dist[to[e]] = new_dist;
					prev[to[e]] = e;
					Q.push(make_pair(-new_dist,to[e]));
				}
			}
		}
		
		if (prev[t]==-1) break;
		
		cap_type f = cap[prev[t]];
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
	int n,m;
	double cst;
	
	while(true){
		scanf("%d %d",&n,&m);
		if(n==0 && m==0) break;
		
		init(n+m+2);
		for(int i = 0;i<n;++i) add_edge(0,1+i,1,0);
		for(int i = 0;i<m;++i) add_edge(1+n+i,1+n+m,1,0);
		
		for(int i = 0;i<n;++i) for(int j = 0;j<m;++j){
			scanf("%lf",&cst);
			add_edge(1+i,1+n+j,1,cst);
		}
		
		mcmf(0,1+n+m);
		flowCost /= n;
		flowCost = floor(flowCost*100.0+0.5+1e-9)/100.0;
		printf("%.2lf\n",flowCost);
	}
	
	return 0;
}
