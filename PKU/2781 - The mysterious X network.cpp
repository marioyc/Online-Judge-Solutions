#include <cstdio>
#include <cstring>

using namespace std;

#define MAXV 100000
#define MAXE 10000000

int E = 0,to[MAXE],next[MAXE],last[MAXV];
int Q[MAXV],head,tail,dist[MAXV];

void add_edge(int u, int v){
    to[E] = v; next[E] = last[u]; last[u] = E++;
}

int main(){
    int N;
    
    scanf("%d",&N);
    
    memset(last,-1,sizeof last);
    
    for(int i = 0,u,v,m;i < N;++i){
        scanf("%d %d",&u,&m);
        
        for(int j = 0;j < m;++j){
            scanf("%d",&v);
            add_edge(u,v);
        }
    }
    
    head = tail = 0;
    memset(dist,-1,sizeof dist);
    
    int s,t;
    scanf("%d %d",&s,&t);
    
    Q[tail++] = s;
    dist[s] = 0;
    
    while(head < tail){
        int cur = Q[head++];
        
        for(int e = last[cur],x;e != -1;e = next[e]){
            x = to[e];
            
            if(dist[x] == -1){
                Q[tail++] = x;
                dist[x] = 1 + dist[cur];
            }
        }
    }
    
    printf("%d %d %d\n",s,t,dist[t] - 1);
    
    return 0;
}
