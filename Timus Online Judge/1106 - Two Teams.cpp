#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    vector<int> L[100];
    int deg[100];
    
    memset(deg,0,sizeof(deg));
    
    for(int i = 0,v;i < N;++i){
        while(true){
            scanf("%d",&v);
            if(v == 0) break;
            L[i].push_back(v-1);
            ++deg[i];
        }
    }
    
    int Q[100],head,tail,color[100],first = 0;
    bool visited[100],possible = true;
    
    memset(visited,false,sizeof(visited));
    
    for(int i = 0;i < N && possible;++i){
        if(deg[i] == 0) possible = false;
        else if(!visited[i]){
            head = tail = 0;
            
            visited[i] = true;
            Q[tail++] = i;
            color[i] = 0;
            
            while(head < tail){
                int cur = Q[head++];
                if(color[cur] == 0) ++first;
                
                for(int j = deg[cur] - 1;j >= 0;--j){
                    int nxt = L[cur][j];
                    
                    if(!visited[nxt]){
                        visited[nxt] = true;
                        Q[tail++] = nxt,
                        color[nxt] = 1 - color[cur];
                    }
                }
            }
        }
    }
    
    if(!possible) puts("0");
    else{
        printf("%d\n",first);
        
        for(int i = 0;i < N;++i)
            if(color[i] == 0)
                printf("%d ",i + 1);
        
        printf("\n");
    }
    
    return 0;
}
