#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 205

int n,c[MAXN];
int u[MAXN * MAXN],v[MAXN * MAXN];
int m = 0;
vector<int> L[MAXN];
int in[MAXN];

void init(){
    memset(in,0,sizeof in);
    for(int i = 0;i < m;++i)
        ++in[ u[i] ];
}

bool done[MAXN];
int a[MAXN];
int pos = 0;

void topological(){
    queue<int> Q;
    
    for(int i = 1;i <= n;++i)
        if(in[i] == 0)
            Q.push(i);
    
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        a[pos++] = cur;
        
        for(int i = L[cur].size() - 1,to;i >= 0;--i){
            to = L[cur][i];
            --in[to];
            if(in[to] == 0) Q.push(to);
        }
    }
}

int solve(int s){
    memset(done,false,sizeof done);
    int have = n,cont = 0;
    
    while(have > 0){
        for(int i = 0;i < n;++i){
            if(!done[ a[i] ] && in[ a[i] ] == 0 && c[ a[i] ] == s){
                done[ a[i] ] = true;
                --have;
                
                for(int j = L[ a[i] ].size() - 1,to;j >= 0;--j){
                    to = L[ a[i] ][j];
                    --in[to];
                }
            }
        }
        
        s = (s + 1) % 3;
        ++cont;
    }
    
    return n + cont - 1;
}

int main(){
    scanf("%d",&n);
    
    for(int i = 1;i <= n;++i){
        scanf("%d",&c[i]);
        --c[i];
    }
    
    for(int i = 1,k;i <= n;++i){
        scanf("%d",&k);
        
        for(int j = 0;j < k;++j){
            u[m] = i;
            scanf("%d",&v[m]);
            L[ v[m] ].push_back(u[m]);
            ++m;
        }
    }
    
    init();
    topological();
    
    init();
    int ans = solve(0);
    init();
    ans = min(ans,solve(1));
    init();
    ans = min(ans,solve(2));
    
    printf("%d\n",ans);
    
    return 0;
}
