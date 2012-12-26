#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 50

int n,M[MAXN][MAXN];
bool visited[MAXN];
int le[MAXN],ri[MAXN];
int min_w,max_w;
vector<int> L[MAXN];

bool dfs(int cur){
    if(visited[cur]) return false;
    visited[cur] = true;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        if(le[to] == -1 || dfs(le[to])){
            ri[cur] = to;
            le[to] = cur;
            return true;
        }
    }
    
    return false;
}

struct edge{
    int u,v,w;
    
    edge(){}
    edge(int _u, int _v, int _w):
        u(_u),v(_v),w(_w){}
    
    bool operator < (edge X)const{
        return w < X.w;
    }
};

int main(){
    int T;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        vector<int> w;
        vector<edge> e;
        
        for(int i = 0;i < n;++i)
            for(int j = 0;j < n;++j){
                scanf("%d",&M[i][j]);
                w.push_back(M[i][j]);
                e.push_back(edge(i,j,M[i][j]));
            }
        
        sort(w.begin(),w.end());
        sort(e.begin(),e.end());
        
        int W = unique(w.begin(),w.end()) - w.begin(),E = n*n;
        int ans = w[W - 1] - w[0];
        
        int cont = 0;
        memset(le,-1,sizeof le);
        memset(ri,-1,sizeof ri);
        max_w = 0;
        
        for(int i = 0;i < n;++i)
            L[i].clear();
        
        for(int i = 0,j = 0,add = 0,erase = 0;i < W;++i){
            min_w = w[i];
            
            // improve matching only using previous edges
            memset(visited,false,sizeof visited);
            
            for(int k = 0;k < n;++k)
                if(ri[k] == -1 && dfs(k))
                    ++cont;
            
            // add new edges
            while(cont < n && j < W){
                max_w = w[j];
                
                while(add < E && e[add].w == max_w){
                    L[ e[add].u ].push_back(e[add].v);
                    ++add;
                }
                
                memset(visited,false,sizeof visited);
                
                for(int k = 0;k < n;++k)
                    if(ri[k] == -1 && dfs(k))
                        ++cont;
                
                ++j;
            }
            
            if(cont == n) ans = min(ans,w[j - 1] - w[i]);
            else break;
            
            // erase edges with weight equal to the current minimum
            for(int k = 0;k < n;++k)
                if(ri[k] != -1 && M[k][ ri[k] ] == w[i]){
                    le[ ri[k] ] = -1;
                    ri[k] = -1;
                    --cont;
                }
            
            while(erase < E && e[erase].w == min_w){
                L[ e[erase].u ].erase(L[ e[erase].u ].begin());
                ++erase;
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
