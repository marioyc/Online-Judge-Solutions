#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>
#include <map>

using namespace std;

#define MAX_V 350
#define MAX_E 2*12500

typedef int cap_type;
typedef long long cost_type;
const cost_type INF = LLONG_MAX;

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

bool BellmanFord(int s, int t){
	bool stop = false;
	for(int i = 0;i<V;++i) dist[i] = INF;
	dist[s] = 0;
	
	for(int i = 1;i<=V && !stop;++i){
		stop = true;
		
		for(int j = 0;j<E;++j){
			int u = to[j^1], v = to[j];
			
			if(cap[j]>0 && dist[u]!=INF && dist[u]+cost[j]<dist[v]){
				stop = false;
				dist[v] = dist[u]+cost[j];
			}
		}
	}
	
	for(int i = 0;i<V;++i) if (dist[i]!=INF) pot[i] = dist[i];
	
	return stop;
}

void mcmf(int s, int t){
    flowVal = flowCost = 0;
    memset(pot,0,sizeof(pot));
	
	if(!BellmanFord(s,t)){
		printf("Ciclo negativo de capacidad infinita");
		return;
	}
    
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
	freopen("fmcm.in","r",stdin);
	freopen("fmcm.out","w",stdout);	
	
	int M,S,D,u,v,c,z;
	scanf("%d %d %d %d",&V,&M,&S,&D);
	--S; --D;
	
	init(V);
	
	for(int i = 0;i<M;++i){
		scanf("%d %d %d %d",&u,&v,&c,&z);
		--u; --v;
		add_edge(u,v,c,z);
	}
	
	mcmf(S,D);
	
	if(!BellmanFord(S,D)) return 0;
	printf("%lld\n",flowCost);
	
	return 0;
}
