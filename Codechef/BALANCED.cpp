#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    int T,N,p1[20000],p2[20000],type[20000];
    vector<int> L[20000];
    int Q[20000],head,tail;
    char ans[20001];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        for(int i = 0;i<N;++i) L[i].clear();
        
        for(int i = 0;i<N;++i) scanf("%d",&p1[i]);
        for(int i = 0;i<N;++i) scanf("%d",&p2[i]);
        
        for(int i = 0;i+1<N;i += 2){
            L[p1[i]].push_back(p1[i+1]);
            L[p1[i+1]].push_back(p1[i]);
            
            L[p2[i]].push_back(p2[i+1]);
            L[p2[i+1]].push_back(p2[i]);
        }
        
        head = tail = 0;
        memset(type,-1,sizeof(type));
        
        for(int i = 0;i<N;++i){
            if(type[i]!=-1) continue;
            
            Q[tail] = i; ++tail;
            type[i] = 0;
            
            while(head<tail){
                int u = Q[head]; ++head;
                
                for(int i = L[u].size()-1;i>=0;--i){
                    int v = L[u][i];
                    if(type[v]!=-1) continue;
                    
                    type[v] = 1-type[u];
                    Q[tail] = v; ++tail;
                }
            }
        }
        
        memset(ans,0,sizeof(ans));
        
        for(int i = 0;i<N;++i){
            if(type[i]==0) ans[i] = 'A';
            else ans[i] = 'B';
        }
        
        puts(ans);
    }
    
    return 0;
}
