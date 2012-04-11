#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

#define MAX_V 2003
#define MAX_E 2*3003

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

void add_edge(int u, int v, cap_type _cap, cost_type _cost){
    to[E] = v, cap[E] = _cap;
    cost[E] = _cost, next[E] = last[u];
    last[u] = E++;
    to[E] = u, cap[E] = 0;
    cost[E] = -_cost, next[E] = last[v];
    last[v] = E++;
}

// only if there is initial negative cycle
void BellmanFord(int s, int t){
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
}

void mcmf(int s, int t){
    flowVal = flowCost = 0;
    memset(pot,0,sizeof(pot));
    
    BellmanFord(s,t);
    
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
    int n,k;
    
    scanf("%d %d",&n,&k);
    
    int a[n],b[n],c[n];
    vector<int> t;
    
    for(int i = 0;i < n;++i){
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
        b[i] = a[i] + b[i];
        
        t.push_back(a[i]);
        t.push_back(b[i]);
    }
    
    int sz = t.size();
    sort(t.begin(),t.end());
    
    map<int, int> id;
    int cont = 0;
    id[ t[0] ] = cont++;
    
    for(int i = 1;i < sz;++i)
        if(t[i] != t[i - 1])
            id[ t[i] ] = cont++;
    
    init(3 + cont);
    
    for(int i = 0;i <= 1 + cont;++i)
        add_edge(i,1 + i,k,0);
    
    for(int i = 0;i < n;++i){
        int u = id[ a[i] ],v = id[ b[i] ];
        add_edge(2 + u,2 + v,1,-c[i]);
    }
    
    mcmf(0,2 + cont);
    
    for(int i = 0;i < n;++i)
        printf("%d ",cap[2 * (2 + cont + i)] == 0? 1 : 0);
    
    return 0;
}
