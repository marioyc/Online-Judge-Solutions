#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int T,n,m,in[100],ans[100];
    vector<int> L[100];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&n,&m);
        
        for(int i = 0;i < n;++i)
            L[i].clear();
        memset(in,0,sizeof in);
        
        for(int i = 0,x,y;i < m;++i){
            scanf("%d %d",&x,&y);
            --x; --y;
            L[x].push_back(y);
            ++in[y];
        }
        
        priority_queue<int> Q;
        
        for(int i = 0;i < n;++i)
            if(in[i] == 0)
                Q.push(-i);
        
        int cont = 0;
        
        while(!Q.empty()){
            int aux = -Q.top();
            Q.pop();
            ans[cont++] = aux + 1;
            
            for(int i = L[aux].size() - 1,to;i >= 0;--i){
                to = L[aux][i];
                --in[to];
                
                if(in[to] == 0) Q.push(-to);
            }
        }
        
        if(cont != n) printf("Low IQ\n");
        else{
            for(int i = 0;i < n;++i)
                printf("%d ",ans[i]);
            printf("\n");
        }
    }
    
    return 0;
}
