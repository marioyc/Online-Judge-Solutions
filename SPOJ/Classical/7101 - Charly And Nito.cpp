#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int nE,last[5000],nxt[300000],to[300000],W[300000];

void add_edge(int u, int v, int w){
    nxt[nE] = last[u]; to[nE] = v; W[nE] = w; last[u] = nE; ++nE;
    nxt[nE] = last[v]; to[nE] = u; W[nE] = w; last[v] = nE; ++nE;
}

struct node{
    int pos,dist;
    
    node(){}
    
    node(int _pos, int _dist){
        pos = _pos; dist = _dist;
    }
    
    bool operator < (node X)const{
        return dist > X.dist;
    }
};

int dist[3][5000];

void dijkstra(int id, int s){
    //printf("id = %d, s = %d\n",id,s);
    priority_queue<node> Q;
    memset(dist[id],-1,sizeof(dist[id]));
    
    Q.push(node(s,0));
    
    while(!Q.empty()){
        node aux = Q.top();
        Q.pop();
        
        int u = aux.pos;
        
        if(dist[id][u] != -1) continue;
        dist[id][u] = aux.dist;
        //printf("u = %d, dist = %d\n",u,dist[id][u]);
        
        for(int e = last[u],v;e != -1;e = nxt[e]){
            v = to[e];
            if(dist[id][v] == -1) Q.push(node(v,aux.dist + W[e]));
        }
    }
}

int main(){
    int V,B,C,N,E;
    
    while(true){
        scanf("%d %d %d %d %d",&V,&B,&C,&N,&E);
        if(V == -1) break;
        --B; --C; --N;
        
        memset(last,-1,sizeof(last));
        nE = 0;
        
        for(int i = 0,u,v,w;i < E;++i){
            scanf("%d %d %d",&u,&v,&w);            
            add_edge(u - 1,v - 1,w);
        }
        
        dijkstra(0,B);
        dijkstra(1,C);
        dijkstra(2,N);
        
        int best = 0,dC = dist[0][C],dN = dist[0][N];
        
        for(int i = 0,j;i < V;++i){
            for(int e = last[i];e != -1;e = nxt[e]){
                j = to[e];
                
                if(dist[0][i] + W[e] + dist[1][j] == dist[0][C] && dist[0][i] + W[e] + dist[2][j] == dist[0][N] && dist[0][i] + W[e] > best){
                    best = dist[0][i] + W[e];
                    dC = dist[1][j];
                    dN = dist[2][j];
                }
            }
        }
        
        printf("%d %d %d\n",best,dC,dN);
    }
    
    return 0;
}
