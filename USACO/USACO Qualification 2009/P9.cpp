/*
ID:zion_ba1
LANG:C++
TASK:heatwv
*/

#include <iostream>
#include <queue>

using namespace std;

struct edge{
    int v,cost;
    
    edge(){
    }
    
    edge(int _v, int  _cost){
        v=_v;
        cost=_cost;
    }
    
    bool operator < (const edge &X) const{
        return cost>X.cost;
    }
};

int T,C,Ts,Te;
vector< vector<edge> > L;

int solve(){
    bool visited[T];
    for(int i=0;i<T;i++) visited[i]=false;
    
    priority_queue<edge> Q;
    edge aux;
    
    Q.push(edge(Ts,0));
    
    while(!Q.empty()){
        aux=Q.top();
        Q.pop();
        
        if(visited[aux.v]) continue;
        visited[aux.v]=true;
        
        if(aux.v==Te) return aux.cost;
        
        for(int i=L[aux.v].size()-1;i>=0;i--){
            int v=L[aux.v][i].v;
            if(visited[v]) continue;
            Q.push(edge(v,aux.cost+L[aux.v][i].cost));
        }
    }
    
    return -1;
}

int main(){
    freopen("heatwv.in","r",stdin);
    freopen("heatwv.out","w",stdout);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    
    scanf("%d %d %d %d",&T,&C,&Ts,&Te);
    Ts--; Te--;
    
    L.resize(T);
    
    for(int i=0,a,b,c;i<C;i++){
        scanf("%d %d %d",&a,&b,&c);
        a--; b--;
        
        L[a].push_back(edge(b,c));
        L[b].push_back(edge(a,c));
    }
    
    int ans=solve();
    
    printf("%d\n",ans);
    
    return 0;
}
