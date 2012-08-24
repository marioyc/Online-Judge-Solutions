#include <cstdio>
#include <vector>

using namespace std;

vector<int> L[20001];
int N,balance[20001],dp[20001];

void dfs(int cur, int p){
    dp[cur] = 1;
    balance[cur] = 0;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(to != p){
            dfs(to,cur);
            dp[cur] += dp[to];
            balance[cur] = max(balance[cur],dp[to]);
        }
    }
    
    if(cur != 1) balance[cur] = max(balance[cur],N - dp[cur]);
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        for(int i = 1;i <= N;++i)
            L[i].clear();
        
        for(int i = 1,u,v;i < N;++i){
            scanf("%d %d",&u,&v);
            L[u].push_back(v);
            L[v].push_back(u);
        }
        
        dfs(1,0);
        
        int best = N + 1,ans = 0;
        
        for(int i = 1;i <= N;++i){
            if(balance[i] < best){
                best = balance[i];
                ans = i;
            }
        }
        
        printf("%d %d\n",ans,best);
    }
    
    return 0;
}
