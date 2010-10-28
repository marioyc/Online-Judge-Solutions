#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    vector<int> L[100];
    int in[100];
    memset(in,0,sizeof(in));
    
    for(int i = 0,u;i<N;++i){
        while(true){
            scanf("%d",&u);
            if(u==0) break;
            L[i].push_back(--u);
            ++in[u];
        }
    }
    
    int Q[100],tail = 0;
    bool visited[100];
    memset(visited,false,sizeof(visited));
    
    for(int i = 0;i<N;++i){
        if(in[i]==0){
            visited[i] = true;
            Q[tail++] = i;
        }
    }
    
    for(int i = 0;i<N;++i){
        int pos = Q[i];
        printf("%d ",pos+1);
        
        for(int j = L[pos].size()-1;j>=0;--j){
            int next = L[pos][j];
            --in[next];
            
            if(in[next]==0 && !visited[next]){
                visited[next] = true;
                Q[tail++] = next;
            }
        }
    }
    
    printf("\n");
    
    return 0;
}
