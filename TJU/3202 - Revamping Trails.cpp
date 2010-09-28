#include <cstdio>
#include <queue>

using namespace std;

struct edge{
    int v,t;
    
    edge(int _v, int _t){
        v=_v;
        t=_t;
    }
};


struct nodo{
    int v,k,dist;
    
    nodo(){
    }
    
    nodo(int _v, int _k, int _dist){
        v=_v;
        k=_k;
        dist=_dist;
    }
    
    bool operator < (nodo X) const{
        return dist>X.dist;
    }
};

int main(){    
    int N,M,K;
    
    scanf("%d %d %d",&N,&M,&K);
    
    vector< vector<edge> > L(N);
    
    for(int i=0;i<N;i++)
        L[i].push_back(edge(i,0));    
    
    int v1,v2,dist;
    
    for(int i=0;i<M;i++){
        scanf("%d %d %d",&v1,&v2,&dist);
        v1--; v2--;
        
        L[v1].push_back(edge(v2,dist));
        L[v2].push_back(edge(v1,dist));
    }
    
    priority_queue<nodo> Q;
    
    bool visited[N][K+1];
    for(int i=0;i<N;i++) fill(visited[i],visited[i]+(K+1),false);
    
    Q.push(nodo(0,0,0));
    
    nodo aux;
    
    while(true){
        aux=Q.top();
        Q.pop();
        
        if(aux.v==N-1 && aux.k==K){
            printf("%d\n",aux.dist);
            break;
        }
        
        if(visited[aux.v][aux.k]) continue;
        visited[aux.v][aux.k]=true;
        
        for(int i=0;i<L[aux.v].size();i++){
            if(!visited[L[aux.v][i].v][aux.k]) Q.push(nodo(L[aux.v][i].v,aux.k,aux.dist+L[aux.v][i].t));
            if(aux.k<K && !visited[L[aux.v][i].v][aux.k+1]) Q.push(nodo(L[aux.v][i].v,aux.k+1,aux.dist));
        }
    }
    
    return 0;
}
