#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> L[100000];
int Q[100000];
bool visited[100000];
int dp[100000],sons[100000];

int main(){
    int N;
    scanf("%d",&N);
    
    for(int i = 0,v;i < N;++i){
        while(true){
            scanf("%d",&v);
            if(v == 0) break;
            --v;
            
            L[i].push_back(v);
            L[v].push_back(i);
        }
    }
    
    int root;
    scanf("%d",&root);
    --root;
    
    int head = 0,tail = 0;
    Q[tail++] = root;
    visited[root] = true;
    
    for(int i = 0,v;i < N;++i){
        v = Q[head++];
        
        for(int j = L[v].size()-1,nxt;j >= 0;--j){
            nxt = L[v][j];
            
            if(!visited[nxt]){
                Q[tail++] = nxt;
                visited[nxt] = true;
            }
        }
    }
    
    memset(dp,-1,sizeof(dp));
    
    for(int i = N-1,v,cont,aux;i >= 0;--i){
        v = Q[i];
        aux = cont = 0;
        
        for(int j = L[v].size()-1;j >= 0;--j)
            if(dp[L[v][j]] != -1) sons[cont++] = dp[L[v][j]];
        
        sort(sons,sons + cont);
        
        dp[v] = 0;
        for(int j = 0;j < cont;++j) dp[v] = max(dp[v],cont - j + sons[j]);
    }
    
    printf("%d\n",dp[root]);
        
    return 0;
}
