#include <cstdio>
#include <algorithm>

using namespace std;

#define MOD 1000000000

struct edge{
    int u,v,w;
    
    edge(){}
    
    bool operator < (edge X)const{
        return w < X.w;
    }
}E[100000];

int parent[100001],cont[100001];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    
    if(x != y){
        cont[x] += cont[y];
        parent[y] = x;
    }
}

int main(){
    int N,M;
    
    scanf("%d %d",&N,&M);
    
    for(int i = 0,u,v,w;i < M;++i)
        scanf("%d %d %d",&E[i].u,&E[i].v,&E[i].w);
    
    for(int i = 1;i <= N;++i){
        parent[i] = i;
        cont[i] = 1;
    }
    
    sort(E,E + M);
    
    for(int i = 1;i < M;++i){
        E[i].w += E[i - 1].w;
        if(E[i].w >= MOD) E[i].w -= MOD;
    }
    
    int ans = 0;
    
    for(int i = M - 1,sum = 0;i >= 0;--i){
        if(Find(E[i].u) != Find(E[i].v)){
            ans = (ans + (long long)E[i].w * cont[ Find(E[i].u) ] * cont[ Find(E[i].v) ]) % MOD;
            Union(E[i].u,E[i].v);
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
