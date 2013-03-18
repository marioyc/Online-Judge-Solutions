#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 500
#define MAXC 100

vector<int> conf[MAXN];
vector< pair<int,int> > L[MAXC];
int ncomp = 0;
int low[MAXC],h[MAXC];
bool visited[MAXC],bridge[MAXN];

void dfs(int cur, int p, int curh){
    if(visited[cur]) return;
    visited[cur] = true;
    h[cur] = low[cur] = curh;
    bool back = true;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i].first;
        
        if(to == p){
            if(!back) low[cur] = min(low[cur],curh - 1);
            back = false;
        }else if(visited[to]){
            low[cur] = min(low[cur],h[to]);
        }else{
            dfs(to,cur,curh + 1);
            low[cur] = min(low[cur],low[to]);
            
            if(low[to] > curh) bridge[ L[cur][i].second ] = true;
        }
    }
}

int main(){
    int N,C;
    int deg[MAXC];
    
    while(true){
        scanf("%d %d",&N,&C);
        if(N == 0) break;
        
        for(int i = 0;i < N;++i)
            conf[i].clear();
        
        for(int i = 0,K;i < C;++i){
            scanf("%d",&K);
            
            for(int j = 0,x;j < K;++j){
                scanf("%d",&x);
                conf[x].push_back(i);
            }
        }
        
        for(int i = 0;i < C;++i) L[i].clear();
        memset(deg,0,sizeof deg);
        
        for(int i = 0;i < N;++i){
            int u = conf[i][0],v;
            
            if(conf[i].size() == 1) v = u;
            else v = conf[i][1];
            
            ++deg[u]; ++deg[v];
            L[u].push_back(make_pair(v,i));
            L[v].push_back(make_pair(u,i));
        }
        
        vector<int> odd;
        
        for(int i = 0;i < C;++i)
            if(deg[i] & 1) odd.push_back(i);
        
        memset(visited,false,sizeof visited);
        memset(bridge,false,sizeof bridge);
        ncomp = 0;
        
        for(int i = 0;i < C && ncomp <= 1;++i)
            if(deg[i] != 0 && !visited[i]){
                dfs(i,-1,0);
                ++ncomp;
            }
        
        if(ncomp > 1 || odd.size() > 2) puts("-1");
        else if(odd.size() == 0) puts("0");
        else{
            int ans = N;
            
            for(int i = 0;i <= 1;++i){
                int cur = odd[i];
                
                if(L[cur].size() == 1) ans = min(ans,L[cur][0].second);
                else{
                    for(int j = L[cur].size() - 1;j >= 0;--j)
                        if(!bridge[ L[cur][j].second ])
                            ans = min(ans,L[cur][j].second);
                }
            }
            
            printf("%d\n",ans);
        }
    }
    
    return 0;
}
