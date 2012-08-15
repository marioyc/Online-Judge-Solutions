#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int N;
vector<int> L[50000];
int cont[50000];
long long ans = 0;

void dfs(int cur, int prev = -1){
    cont[cur] = 1;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(to != prev){
            dfs(to,cur);
            cont[cur] += cont[to];
        }
    }
    
    if(cur != 0) ans += cont[cur] * (N - cont[cur]);
}

int main(){
    int R;
    
    scanf("%d %d",&N,&R);
    
    for(int i = 1,u,v;i < N;++i){
        scanf("%d %d",&u,&v);
        --u; --v;
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    dfs(0);
    
    ans *= R;
    
    long long den = ans != 0? (long long)N * (N - 1) / 2 : 1LL;
    
    if(ans != 0){
        long long g = __gcd(ans,den);
        
        ans /= g;
        den /= g;
    }
    
    printf("%lld/%lld\n",ans,den);
    
    return 0;
}
