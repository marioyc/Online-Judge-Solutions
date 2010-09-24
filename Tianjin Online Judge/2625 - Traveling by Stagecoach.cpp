#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct node{
    int mask,pos;
    double t;
    
    node(){
    }
    
    node(int _mask, int _pos, double _t){
        mask=_mask;
        pos=_pos;
        t=_t;
    }
    
    bool operator < (node X) const{
        return t>X.t;
    }
}aux;

int M[30][30];
int horses[8];
bool visited[30][(1<<8)];
vector< vector<int> > L;

void dijkstra(int &s, int &e, int &V, int &m){
    for(int i=0;i<V;i++) fill(visited[i],visited[i]+(1<<m),false);
    
    priority_queue<node> Q;
    Q.push(node(0,s,0));
    
    while(!Q.empty()){
        aux=Q.top();
        Q.pop();
        
        if(visited[aux.pos][aux.mask]) continue;
        visited[aux.pos][aux.mask]=true;
        
        if(aux.pos==e){
            printf("%.6f\n",aux.t);
            return;
        }
        
        for(int i=L[aux.pos].size()-1;i>=0;i--){
            int v=L[aux.pos][i];
            
            for(int j=0;j<m;j++){
                if(aux.mask & (1<<j)) continue;
                if(visited[v][aux.mask|(1<<j)]) continue;
                Q.push(node(aux.mask|(1<<j),v,aux.t+(double)M[aux.pos][v]/horses[j]));
            }
        }
    }
    
    printf("Impossible\n");
}

int main(){
    int m,V,E,s,e,u,v,t;
    
    while(1){
        scanf("%d %d %d %d %d",&m,&V,&E,&s,&e);
        if(V<=0) break;
        s--; e--;
        
        for(int i=0;i<m;i++) scanf("%d",&horses[i]);
        L.clear(); L.resize(V);
        for(int i=0;i<E;i++){
            scanf("%d %d %d",&u,&v,&t);
            u--; v--;
            M[u][v]=M[v][u]=t;
            L[u].push_back(v);
            L[v].push_back(u);
        }
        
        dijkstra(s,e,V,m);
    }
    
    return 0;
}
