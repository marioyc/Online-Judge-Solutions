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

struct node{
    int u,t;
    
    node(){
    }
    
    node(int _u, int _t){
        u=_u;
        t=_t;
    }
    
    bool operator < (node X) const{
        return t>X.t;
    }
};

vector<int> dijkstra(vector< vector<edge> > &L, int &start){
    priority_queue<node> Q;
    Q.push(node(start,0));
    
    int n=L.size();
    bool reached[n];
    fill(reached,reached+n,false);
    int T[n];
    
    node aux;
    int u,t;
    
    while(!Q.empty()){
        aux=Q.top();
        Q.pop();
        
        u=aux.u; t=aux.t;
        
        if(reached[u]) continue;
        reached[u]=true;
        T[u]=t;
        
        for(int i=L[u].size()-1;i>=0;i--){
            if(reached[L[u][i].v]) continue;
            Q.push(node(L[u][i].v,aux.t+L[u][i].t));
        }
    }
    
    vector<int> v(T,T+n);
    
    return v;
}

int main(){
    int N,M,X;
    
    scanf("%d %d %d",&N,&M,&X);
    X--;
    
    int u,v,t;
    vector< vector<edge> > L1(N);
    vector< vector<edge> > L2(N);
    
    for(int i=0;i<M;i++){
        scanf("%d %d %d",&u,&v,&t);
        u--; v--;
        L1[u].push_back(edge(v,t));
        L2[v].push_back(edge(u,t));
    }
    
    vector<int> T1=dijkstra(L1,X);
    vector<int> T2=dijkstra(L2,X);
    
    int ans=0;
    
    for(int i=0;i<N;i++) ans=max(ans,T1[i]+T2[i]);
    
    printf("%d\n",ans);
    
    return 0;
}
