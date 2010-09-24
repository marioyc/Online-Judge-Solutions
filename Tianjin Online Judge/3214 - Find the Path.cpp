#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct nodo{
    int v,dist;
    
    nodo(){
    }
    
    nodo(int _v, int _dist){
        v=_v;
        dist=_dist;
    }
    
    bool operator < (nodo X)const{
        return dist>X.dist;
    }
};

struct edge{
    int v,w;
    
    edge(int _v, int _w){
        v=_v;
        w=_w;
    }
};

int main(){    
    int T,N,M,C[200],u,v,w,queries,start,end,k;    
    bool visited[200],found;
    nodo aux;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&N,&M);
        
        vector< vector<edge> > L(N);
        
        for(int i=0;i<N;i++) scanf("%d",&C[i]);
        
        for(int i=0;i<M;i++){
            scanf("%d %d %d",&u,&v,&w);
            L[u].push_back(edge(v,w));
            L[v].push_back(edge(u,w));
        }
        
        scanf("%d",&queries);
        
        for(int i=0;i<queries;i++){
            scanf("%d %d %d",&start,&end,&k);
            
            priority_queue<nodo> Q;            
            Q.push(nodo(start,0));
            found=false;
            
            fill(visited,visited+N,false);
            
            while(!Q.empty()){
                aux=Q.top();
                Q.pop();
                
                if(visited[aux.v]) continue;
                visited[aux.v]=true;
                
                if(aux.v==end){
                    printf("%d\n",aux.dist);
                    found=true;
                    break;
                }
                
                for(int j=0;j<L[aux.v].size();j++){
                    if(visited[L[aux.v][j].v]) continue;
                    if(C[L[aux.v][j].v]>k && L[aux.v][j].v!=end) continue;
                    
                    Q.push(nodo(L[aux.v][j].v,aux.dist+L[aux.v][j].w));
                }
            }
            
            if(!found) printf("-1\n");
        }
        
        printf("\n");
    }
    
    return 0;
}
