#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 55

int parent[MAXN],comp;

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
    
    int d[MAXN];
    memset(d,0,sizeof d);
    
    for(int i = 1;i <= n;++i)
        parent[i] = i;
    
    for(int i = 0,u,v;i < m;++i){
        scanf("%d %d",&u,&v);
        Union(u,v);
        ++d[u]; ++d[v];
    }
    
    for(int i = 1;i <= n;++i)
        if(d[i] > 2){
            printf("NO\n");
            return 0;
        }
    
    if(m == n){
        if(comp > 1) printf("NO\n");
        else printf("YES\n0\n");
        return 0;
    }
    
    if(n == 1){
        printf("YES\n1\n1 1\n");
        return 0;
    }
    
    int u[n - m],v[n - m];
    
    for(int e = 0;e < n - m - 1;++e){
        bool found = false;
        
        for(int i = 1;i <= n && !found;++i)
            if(d[i] < 2)
                for(int j = i + 1;j <= n && !found;++j)
                    if(d[j] < 2 && Find(i) != Find(j)){
                        found = true;
                        u[e] = i; v[e] = j;
                        ++d[i]; ++d[j];
                        Union(i,j);
                    }
        
        if(!found){
            printf("NO\n");
            return 0;
        }
    }
    
    if(comp > 1){
        printf("NO\n");
        return 0;
    }
    
    for(int i = 1;i <= n;++i)
        for(int j = i + 1;j <= n;++j)
            if(d[i] == 1 && d[j] == 1){
                printf("YES\n");
                printf("%d\n",n - m);
                
                for(int e = 0;e < n - m - 1;++e)
                    printf("%d %d\n",u[e],v[e]);
                
                printf("%d %d\n",i,j);
                return 0;
            }
    
    printf("NO\n");
    
    return 0;
}
