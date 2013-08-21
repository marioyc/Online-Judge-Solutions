#include <cstdio>

using namespace std;

#define MAXN 100005

int parent[MAXN];
int C,cont[MAXN];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    
    if(x != y){
        parent[x] = y;
        cont[y] += cont[x];
        --C;
    }
}

int main(){
    int n,m,k;
    
    scanf("%d %d %d",&n,&m,&k);
    
    C = n;
    
    for(int i = 1;i <= n;++i){
        parent[i] = i;
        cont[i] = 1;
    }
    
    for(int i = 0,u,v;i < m;++i){
        scanf("%d %d",&u,&v);
        Union(u,v);
    }
    
    int ans = 1 % k;
    
    if(C >= 2){
        for(int i = 1;i <= n;++i)
            if(Find(i) == i)
                ans = (long long)ans * cont[i] % k;
        
        for(int i = 1;i <= C - 2;++i)
            ans = (long long)ans * n % k;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
