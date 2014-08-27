#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100000

int val[MAXN],sum = 0,ans;
vector<int> L[MAXN];

int dfs(int cur, int par){
    int ret = val[cur];
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(to != par) ret += dfs(to,cur);
    }
    
    ans = min(ans,abs(ret - (sum - ret)));
    return ret;
}

int main(){
    int N;
    
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i){
        scanf("%d",&val[i]);
        sum += val[i];
    }
    
    for(int i = 1,u,v;i < N;++i){
        scanf("%d %d",&u,&v);
        --u; --v;
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    ans = 100100000;
    dfs(0,-1);
    
    printf("%d\n",ans);
    
    return 0;
}
