#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MOD 1000000007
#define MAXN 100000

int N,W[MAXN];
vector<int> L[MAXN];

long long dfs(int pos, int par){
    long long ret = (W[pos] - (par == -1? 0 : W[par])) % MOD;
    if(ret < 0) ret += MOD;
    
    for(int i = L[pos].size() - 1,to;i >= 0;--i){
        to = L[pos][i];
        
        if(to != par)
            ret = (ret * dfs(to,pos)) % MOD;
    }
    
    return ret;
}

int main(){
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i)
        scanf("%d",&W[i]);
    
    for(int i = 1,u,v;i < N;++i){
        scanf("%d %d",&u,&v);
        --u; --v;
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    printf("%lld\n",dfs(0,-1));
    
    return 0;
}
