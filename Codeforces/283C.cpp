#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 305
#define MOD 1000000007

int n,q,t;
int a[MAXN],in[MAXN],out[MAXN],h[MAXN];
int cont = 0;

void dfs(int cur, int curh){
    t = max(-1,t - a[cur] * curh);
    ++cont;
    
    if(out[cur]){
        dfs(out[cur],curh + 1);
        a[cur] += a[ out[cur] ];
    }
}

int dp[100001];

int main(){
    scanf("%d %d %d",&n,&q,&t);
    
    for(int i = 1;i <= n;++i)
        scanf("%d",&a[i]);
    
    for(int i = 0,u,v;i < q;++i){
        scanf("%d %d",&u,&v);
        in[u] = v;
        out[v] = u;
    }
    
    for(int i = 1;i <= n;++i)
        if(in[i] == 0)
            dfs(i,0);
    
    if(t < 0 || cont != n) printf("0\n");
    else{
        dp[0] = 1;
        
        for(int i = 1;i <= n;++i)
            for(int j = 0;j <= t - a[i];++j)
                dp[ j + a[i] ] = (dp[ j + a[i] ] + dp[j]) % MOD;
        
        printf("%d\n",dp[t]);
    }
    
    return 0;
}
