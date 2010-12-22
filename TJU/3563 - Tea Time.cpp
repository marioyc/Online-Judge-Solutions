#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int V,E,T;
    scanf("%d %d %d",&V,&E,&T);
    
    vector<int> L[V];
    
    for(int i = 0,u,v;i<E;++i){
        scanf("%d %d",&u,&v);
        --u; --v;
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    bool visited[V];
    int Q[V],head,tail;
    
    for(int tc = 0,u,v;tc<T;++tc){
        scanf("%d %d",&u,&v);
        --u; --v;
        
        fill(visited,visited+V,false);
        
        head = tail = 0;
        visited[u] = true;
        Q[tail] = u; ++tail;
        
        while(head<tail){
            int cur = Q[head]; ++head;
            
            for(int i = L[cur].size()-1;i>=0;--i){
                int nxt = L[cur][i];
                
                if(!visited[nxt]){
                    visited[nxt] = true;
                    Q[tail] = nxt; ++tail;
                }
            }
        }
        
        if(visited[v]) puts("Y");
        else puts("N");
    }
    
    return 0;
}
