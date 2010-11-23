#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    int N,root;
    scanf("%d %d",&N,&root);
    --root;
    
    vector<int> L[1000];
    
    for(int i = 1,u,v;i<N;++i){
        scanf("%d %d",&u,&v);
        --u; --v;
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    int Q[1000],tail = 0,parent[1000];
    memset(parent,-1,sizeof(parent));
    
    Q[tail] = root; ++tail;
    parent[root] = -2;
    
    for(int i = 0;i<N;++i){
        int cur = Q[i];
        
        for(int j = L[cur].size()-1;j>=0;--j){
            int next = L[cur][j];
            
            if(parent[next]==-1){
                Q[tail] = next; ++tail;
                parent[next] = cur;
            }
        }
    }
    
    bool win[1000];
    
    for(int i = N-1;i>=0;--i){
        int cur = Q[i];
        win[cur] = false;
        
        for(int j = L[cur].size()-1;j>=0;--j){
            int next = L[cur][j];
            
            if(parent[next]==cur && !win[next])
                win[cur] = true;
        }
    }
    
    if(!win[root]) printf("First player loses\n");
    else{
        int choose = N+1;
        
        for(int i = L[root].size()-1;i>=0;--i){
            int next = L[root][i];
            
            if(parent[next]==root && !win[next] && next<choose)
                choose = next;
        }
        
        printf("First player wins flying to airport %d\n",choose+1);
    }
    
    return 0;
}
