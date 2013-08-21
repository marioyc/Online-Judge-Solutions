#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 100005

int d[MAXN];

int parent[MAXN];
int comp;

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    if(x != y){
        parent[x] = y;
        --comp;
    }
}

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    comp = n;
    
    for(int i = 1;i <= n;++i)
        parent[i] = i;
    
    for(int i = 0,u,v;i < m;++i){
        scanf("%d %d",&u,&v);
        ++d[u]; ++d[v];
        Union(u,v);
    }
    
    if(comp == 1 && m == n - 1){
        int cont1 = 0,cont2 = 0,cont3 = 0;
        
        for(int i = 1;i <= n;++i){
            if(d[i] == n - 1) ++cont1;
            else if(d[i] == 1) ++cont2;
            if(d[i] == 2) ++cont3;
        }
        
        if(cont1 == 1 && cont2 == n - 1) printf("star topology\n");
        else if(cont2 == 2 && cont3 == n - 2) printf("bus topology\n");
        else printf("unknown topology\n");
    }else if(comp == 1 && m == n){
        bool ok = true;
        
        for(int i = 1;i <= n;++i)
            if(d[i] != 2) ok = false;
        
        if(ok) printf("ring topology\n");
        else printf("unknown topology\n");
    }else printf("unknown topology\n");
    
    return 0;
}
