#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_V 100000
#define MAX_E 100000

int V,E,indeg[MAX_V],topo_pos[MAX_V];
int last[MAX_V],next[MAX_E],to[MAX_E];
int Q[MAX_V],head,tail;
bool done[MAX_V];

void init(){
    memset(indeg,0,sizeof(indeg));
    memset(last,-1,sizeof(last));
}

void add_edge(int u, int v){
    to[E] = v, next[E] = last[u], last[u] = E; ++E;
    ++indeg[v];
}

void topological_sort(){
    head = tail = 0;
    
    for(int i = 0;i<V;++i){
        if(indeg[i]==0){
            topo_pos[i] = tail;
            Q[tail++] = i;
        }
    }
    
    while(head!=tail){
        int u = Q[head++];
        
        for(int e = last[u],v;e!=-1;e = next[e]){
            v = to[e];
            --indeg[v];
            
            if(indeg[v]==0){
                topo_pos[v] = tail;
                Q[tail++] = v;
            }
        }
    }
}

int main(){
    int M1,M2,u,v;
    scanf("%d %d %d",&V,&M1,&M2);
    
    init();
    
    for(int i = 0;i<M1;++i){
        scanf("%d %d",&u,&v);
        add_edge(u-1,v-1);
    }
    
    topological_sort();
    
    for(int i = 0;i<M2;++i){
        scanf("%d %d",&u,&v);
        if(topo_pos[u-1]<topo_pos[v-1]) printf("%d %d\n",u,v);
        else printf("%d %d\n",v,u);
    }
    
    return 0;
}
