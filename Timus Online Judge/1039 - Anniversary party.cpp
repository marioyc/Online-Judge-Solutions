#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    int rating[6000];
    for(int i = 0;i<N;++i) scanf("%d",&rating[i]);
    
    vector<int> L[6000];
    int in[6000];
    memset(in,0,sizeof(in));
    
    for(int i = 1,u,v;i<N;++i){
        scanf("%d %d",&u,&v);
        --u; --v;
        L[v].push_back(u);
        ++in[u];
    }
    
    int root = -1;
    for(int i = 0;i<N;++i) if(in[i]==0) root = i;
    
    int Q[6000],tail = 0;
    bool visited[6000];
    memset(visited,false,sizeof(visited));
    
    Q[tail] = root; ++tail;
    visited[root] = true;
    
    for(int i = 0;i<N;++i){
        int cur = Q[i];
        
        for(int j = L[cur].size()-1;j>=0;--j){
            int next = L[cur][j];
            
            if(!visited[next]){
                Q[tail] = next; ++tail;
                visited[next] = true;
            }
        }
    }
    
    int dp1[6000],dp2[6000];
    
    for(int i = N-1;i>=0;--i){
        int cur = Q[i];
        dp1[cur] = rating[cur];
        dp2[cur] = 0;
        
        for(int j = L[cur].size()-1;j>=0;--j){
            int next = L[cur][j];
            
            dp1[cur] += dp2[next];
            dp2[cur] += max(dp1[next],dp2[next]);
        }
    }
    
    printf("%d\n",max(dp1[root],dp2[root]));
    
    return 0;
}
