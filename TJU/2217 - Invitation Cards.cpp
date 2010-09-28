#include <cstdio>
#include <queue>
#include <vector>

#include <iostream>

using namespace std;

struct edge{
    int v,d;
    
    edge(){
    }
    
    edge(int _v, int _d){
        v=_v;
        d=_d;
    }
};

vector< vector<edge> > L,L_rev;

struct node{
    int v,cost;
    
    node(){
    }
    
    node(int _v, int _cost){
        v=_v;
        cost=_cost;
    }
    
    bool operator < (node X) const{
        return cost>X.cost;
    }
}aux;

bool reached[1000000];

int dijkstra(int &N, vector< vector<edge> > &L){
    int ans=0,cont=N,v;
    
    priority_queue<node> Q;
    Q.push(node(0,0));
    fill(reached,reached+N,false);
    
    while(cont){
        aux=Q.top();
        Q.pop();
        
        if(reached[aux.v]) continue;
        reached[aux.v]=true;
        ans+=aux.cost;
        cont--;
        
        for(int i=L[aux.v].size()-1;i>=0;i--){
            v=L[aux.v][i].v;
            if(reached[v]) continue;
            Q.push(node(v,aux.cost+L[aux.v][i].d));
        }
    }
    
    return ans;
}

int main(){
    int T,P,Q,u,v,cost;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&P,&Q);
        
        L.clear();
        L.resize(P);
        L_rev.clear();
        L_rev.resize(P);
        
        for(int i=0;i<Q;i++){
            scanf("%d %d %d",&u,&v,&cost);
            u--; v--;
            L[u].push_back(edge(v,cost));
            L_rev[v].push_back(edge(u,cost));
        }
        
        printf("%d\n",dijkstra(P,L)+dijkstra(P,L_rev));
    }
    
    return 0;
}
