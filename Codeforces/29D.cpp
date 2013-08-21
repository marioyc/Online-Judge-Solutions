#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 305

vector<int> L[MAXN];
int K,id[MAXN],mn[MAXN],mx[MAXN],cont[MAXN];

void dfs(int cur, int par){
    if(id[cur] != -1){
        mn[cur] = mx[cur] = id[cur];
        cont[cur] = 1;
    }else{
        mn[cur] = MAXN;
        mx[cur] = -1;
        cont[cur] = 0;
        
        for(int i = L[cur].size() - 1,to;i >= 0;--i){
            to = L[cur][i];
            
            if(to != par){
                dfs(to,cur);
                mn[cur] = min(mn[cur],mn[to]);
                mx[cur] = max(mx[cur],mx[to]);
                cont[cur] += cont[to];
            }
        }
    }
}

void dfs2(int cur, int par){
    printf("%d ",cur);
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(to != par){
            dfs2(to,cur);
            printf("%d ",cur);
        }
    }
}

int main(){
    int n;
    
    scanf("%d",&n);
    
    for(int i = 1,u,v;i < n;++i){
        scanf("%d %d",&u,&v);
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    memset(id,-1,sizeof id);
    K = 0;
    int aux;
    
    while(scanf("%d",&aux) == 1)
        id[aux] = K++;
    
    dfs(1,0);
    
    bool ok = true;
    
    for(int i = 1;i <= n;++i)
        if(mx[i] - mn[i] + 1 != cont[i])
            ok = false;
    
    if(!ok) printf("-1\n");
    else{
        for(int i = 1;i <= n;++i){
            int sz = L[i].size();
            
            for(int j = 0;j < sz;++j)
                for(int k = j + 1;k < sz;++k)
                    if(mn[ L[i][k] ] > mn[ L[i][j] ])
                        swap(L[i][k],L[i][j]);
        }
        
        dfs2(1,0);
        printf("\n");
    }
    
    return 0;
}
