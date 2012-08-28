#include <cstdio>
#include <cstring>

using namespace std;

int N,adj[600][26];
int memo[100][600];

int solve(int len, int pos){
    if(len < 0 || pos < 0) return 0;
    if(len == 0) return 1;
    
    int &ret = memo[len][pos];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = 0;i < N;++i)
            ret += solve(len - 1,adj[pos][i]);
    }
    
    return ret;
}

int main(){
    int L,M;
    char s[600][11];
    
    while(true){
        scanf("%d %d %d",&N,&L,&M);
        if(N == 0) break;
        
        for(int i = 0;i < M;++i)
            scanf("%s",s[i]);
        
        int L2 = strlen(s[0]);
        memset(adj,-1,sizeof adj);
        
        for(int i = 0;i < M;++i){
            for(int j = 0;j < M;++j){
                bool ok = true;
                
                for(int k = 1;k < L2;++k)
                    if(s[i][k] != s[j][k - 1])
                         ok = false;
                
                if(ok) adj[i][ s[j][L2 - 1] - 'A' ] = j;
            }
        }
        
        memset(memo,-1,sizeof memo);
        int ans = 0;
        
        for(int i = 0;i < M;++i)
            ans += solve(L - L2,i);
        
        printf("%d\n",ans);
    }
    
    return 0;
}
