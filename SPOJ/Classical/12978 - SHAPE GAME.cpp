#include <cstdio>
#include <cstring>

using namespace std;

int parent[301];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
}

int main(){
    int T,n,deg[301],u,v;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        memset(deg,0,sizeof deg);
        int r;
        
        while(true){
            scanf("%d %d",&u,&v);
            if(u == -1 && v == -1) break;
            ++deg[u];
            ++deg[v];
            r = u;
        }
        
        bool ok = true;
        
        for(int i = 1;i <= 300;++i){
            if(deg[i])
                if(deg[i] & 1 || Find(i) != Find(r)) ok = false;
        }
        
        puts(ok? "YES" : "NO");
    }
    
    return 0;
}
