#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    int tc = 1,T,N;
    vector<int> L[100];
    bool dom[100][100],conn[100],visited[100];
    int Q[100],head,tail;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        for(int i = 0;i<N;++i) L[i].clear();
        
        for(int i = 0,adj;i<N;++i) for(int j = 0;j<N;++j){
            scanf("%d",&adj);
            if(adj==1) L[i].push_back(j);
        }
        
        memset(conn,false,sizeof(conn));
        head = tail = 0;
        
        conn[0] = true;
        Q[tail] = 0; ++tail;
        
        while(head<tail){
            int cur = Q[head]; ++head;
            for(int i = L[cur].size()-1,nxt;i>=0;--i){
                nxt = L[cur][i];
                
                if(!conn[nxt]){
                    conn[nxt] = true;
                    Q[tail] = nxt; ++tail;
                }
            }
        }
        
        memset(dom,false,sizeof(dom));
        for(int j = 0;j<N;++j) dom[0][j] = conn[j];
        
        for(int i = 1;i<N;++i){
            if(!conn[i]) continue;
            
            memset(visited,false,sizeof(visited));
            head = tail = 0;
            
            visited[0] = true;
            Q[tail] = 0; ++tail;
            
            while(head<tail){
                int cur = Q[head]; ++head;
                for(int j = L[cur].size()-1,nxt;j>=0;--j){
                    nxt = L[cur][j];
                    
                    if(nxt!=i && !visited[nxt]){
                        visited[nxt] = true;
                        Q[tail] = nxt; ++tail;
                    }
                }
            }
            
            for(int j = 0;j<N;++j)
                if(!visited[j] && conn[j])
                    dom[i][j] = true;
        }
        
        printf("Case %d:\n",tc++);
        
        putchar('+');
        for(int j = 2*N-2;j>=0;--j) putchar('-');
        putchar('+');
        putchar('\n');
        
        for(int i = 0;i<N;++i){
            putchar('|');
            for(int j = 0;j<N;++j){
                putchar(dom[i][j]? 'Y' : 'N');
                putchar('|');
            }
            putchar('\n');
            
            putchar('+');
            for(int j = 2*N-2;j>=0;--j) putchar('-');
            putchar('+');
            putchar('\n');
        }
    }
    
    return 0;
}
