#include <cstdio>
#include <climits>
#include <cstring>
#include <queue>

using namespace std;

#define MAX_V 64
#define MAX_E 2*10000

typedef int cap_type;
typedef int cost_type;
const cost_type INF = INT_MAX;

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
    int tc = 1,N,M,u,v,c;
    
    while(true){
        scanf("%d %d",&N,&M);
        if(N==0 && M==0) break;
        
        init(N+1);
        
        for(int i = 0;i<M;++i){
            scanf("%d %d %d",&u,&v,&c);
            add_edge(1+u,1+v,1,c);
        }
        
        add_edge(0,1,2,0);
        
        printf("Instance #%d:  ",tc++);
        
        mcmf(0,N);
        if(flowVal==2) printf("%d\n",flowCost);
        else printf("Not possible\n");
    }
    
    return 0;
}
