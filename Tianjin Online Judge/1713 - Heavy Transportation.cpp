#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

struct nodo{
    int v,w;
    
    nodo(){
    }
    
    nodo(int _v, int _w){
        v=_v;
        w=_w;
    }
    
    bool operator < (nodo X) const{
        return w<X.w;
    }
};

int M[1000][1000];
bool visited[1000];

int solve(int &n){
    priority_queue<nodo> Q;
    Q.push(nodo(0,INT_MAX));
    
    fill(visited,visited+n,false);
    
    nodo aux;
    
    while(1){
        aux=Q.top();
        Q.pop();
        
        if(visited[aux.v]) continue;
        visited[aux.v]=true;
        
        if(aux.v==n-1) return aux.w;
        
        for(int i=0;i<n;i++)
            if(!visited[i] && M[aux.v][i]!=-1) Q.push(nodo(i,min(aux.w,M[aux.v][i])));
    }
}

int main(){    
    int T,n,m;
    int a,b,w;
    
    scanf("%d",&T);
    
    for(int caso=1;caso<=T;caso++){
        scanf("%d %d",&n,&m);
        
        for(int i=0;i<n;i++) fill(M[i],M[i]+n,-1);
        
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&w);
            a--; b--;
            
            M[a][b]=max(M[a][b],w);
            M[b][a]=M[a][b];
        }
        
        printf("Scenario #%d:\n%d\n\n",caso,solve(n));
    }
    
    return 0;
}
