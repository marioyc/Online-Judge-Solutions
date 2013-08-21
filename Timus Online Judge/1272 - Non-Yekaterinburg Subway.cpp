#include <cstdio>

using namespace std;

#define MAXN 10001

int n,k,m,comp;
int parent[MAXN];

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
    scanf("%d %d %d",&n,&k,&m);
    
    comp = n;
    for(int i = 1;i <= n;++i) parent[i] = i;
    
    for(int i = 0,u,v;i < k;++i){
        scanf("%d %d",&u,&v);
        Union(u,v);
    }
    
    printf("%d\n",comp - 1);
    
    return 0;
}
