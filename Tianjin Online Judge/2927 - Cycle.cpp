#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

#define abs(x) (x)>0? (x):-(x)

struct node{
    int v;
    long long dist;
    
    node(){}
    
    node(int _v, int _dist){
        v = _v; dist = _dist;
    }
    
    bool operator < (node X)const{
        return dist>X.dist;
    }
}aux;

#define MAX_V 100

int n,H[MAX_V],dist[MAX_V][MAX_V];
bool visited[MAX_V];

int calcDist(int diff){
    int ans = -1;
    
    for(int ind=0;ind<n;++ind){
        for(int i=0;i<n;++i)
            visited[i] = (H[i]<H[ind] || H[i]>H[ind]+diff);
        
        if(visited[0]) continue;
        
        priority_queue<node> Q;
        Q.push(node(0,0));
        
        while(!Q.empty()){
            aux = Q.top();
            Q.pop();
            
            if(visited[aux.v]) continue;
            visited[aux.v] = true;
            
            if(aux.v==n-1){
                if(ans==-1 || aux.dist<ans) ans = aux.dist;
                break;
            }
            
            for(int i=0;i<n;++i){
                if(dist[aux.v][i]==-1 || visited[i]) continue;
                Q.push(node(i,aux.dist+dist[aux.v][i]));
            }
        }
    }
    
    return ans;
}

int S[MAX_V*MAX_V];

void solve(){
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            S[i*n+j] = abs(H[i]-H[j]);
    
    sort(S,S+(n*n));
    
    int lo = 0,hi = n*n-1,mi,length = -1;
    
    while(lo<hi){
        mi = (lo+hi)/2;
        length = calcDist(S[mi]);
        if(length==-1) lo = mi+1;
        else hi = mi;
    }
    
    printf("%d %d\n",S[lo],calcDist(S[lo]));
    
    return;
}

int main(){
    int T,m,u,v,w;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d %d",&n,&m);
        
        for(int i=0;i<n;++i) scanf("%d",&H[i]);
        
        memset(dist,-1,sizeof(dist));
        
        for(int i=0;i<m;++i){
            scanf("%d %d %d",&u,&v,&w);
            --u; --v;
            if(dist[u][v]!=-1) w = min(w,dist[u][v]);
            dist[u][v] = dist[v][u] = w;
        }
        
        solve();
    }
    
    return 0;
}
