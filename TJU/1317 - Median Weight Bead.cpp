#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int T,N,M,a,b;
    bool adj[99][99];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&M);
        memset(adj,0,sizeof(adj));
        
        for(int i = 0;i<M;++i){
            scanf("%d %d",&a,&b);
            --a; --b;
            adj[a][b] = true;
        }
        
        for(int k = 0;k<N;++k)
            for(int i = 0;i<N;++i)
                for(int j = 0;j<N;++j)
                    adj[i][j] |= (adj[i][k] & adj[k][j]);
        
        int ans = 0;
        
        for(int i = 0;i<N;++i){
            a = b = 0;
            
            for(int j = 0;j<N;++j){
                if(adj[i][j]) ++a;
                if(adj[j][i]) ++b;
            }
            
            if(a>=(N+1)/2 || b>=(N+1)/2) ++ans;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
