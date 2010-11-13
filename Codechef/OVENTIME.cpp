#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

#define MAX_V 51
#define MAX_E 2*150

const int INF = INT_MAX;

int V,E,prev[MAX_V],last[MAX_V],to[MAX_E],next[MAX_E];
int pre[MAX_V],ptr[MAX_V],path[MAX_V];
bool visited[MAX_V];
int cap[MAX_E],flow[MAX_E];
int cost[MAX_E],dist[MAX_V];

void init(int _V){
    memset(last,-1,sizeof(last));
    V = _V; E = 0;
}

void add_edge(int u, int v, int _cap, int _cost){
    to[E] = v, cap[E] = _cap, flow[E] = 0;
    cost[E] = _cost, next[E] = last[u];
    last[u] = E++;
    to[E] = u, cap[E] = 0, flow[E] = 0;
    cost[E] = -_cost, next[E] = last[v];
    last[v] = E++;
}

int min_cost_circulation(){
    while(true){
        memset(pre,-1,sizeof(pre));
        for(int i = 1;i<V;++i) dist[i] = INF/2;
        
        for(int it = 1;it<=V;++it){
            for(int e = 0;e<E;++e){
                if(flow[e]>=cap[e]) continue;
                if(dist[to[e]]+cost[e]<dist[to[e^1]]){
                    dist[to[e^1]] = dist[to[e]]+cost[e];
                    pre[to[e^1]] = to[e];
                    ptr[to[e^1]] = e;
                }
            }
        }
        
        int start = -1;
        
        for(int e = 0;e<E;++e){
            if(flow[e]>=cap[e]) continue;
            if(dist[to[e]]+cost[e]<dist[to[e^1]]){
                start = to[e];
                break;
            }
        }
        
        if(start==-1) break;
        
        int len = 0,nxt = start,fmin = INT_MAX;
        memset(visited,false,sizeof(visited));
        
        do{
            path[len] = nxt; ++len;
            visited[nxt] = true;
            nxt = pre[nxt];
        }while(!visited[nxt]);
        
        for(int i = 0;i<len;++i){
            if(path[i]==nxt){
                start = i;
                break;
            }
        }
        
        for(int i = start;i<len;++i)
            fmin = min(fmin,cap[ptr[path[i]]]-flow[ptr[path[i]]]);
        
        for(int i = start;i<len;++i){
            flow[ptr[path[i]]] += fmin;
            flow[ptr[path[i]]^1] -= fmin;
        }
    }
    
    int flowCost = 0;
    for(int e = 0;e<E;e += 2) flowCost += flow[e]*cost[e];
    
    return flowCost;
}

int main(){
    int T,n,m;
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&n,&m);
        
        init(m+1);
        
        for(int i = 0,s,e,val;i<n;++i){
            scanf("%d %d %d",&s,&e,&val);
            add_edge(e,s,1,-val);
        }
        
        for(int i = 0,c;i<m;++i){
            scanf("%d",&c);
            add_edge(i,i+1,c,0);
        }
        
        printf("%d\n",-min_cost_circulation());
    }
    
    return 0;
}
