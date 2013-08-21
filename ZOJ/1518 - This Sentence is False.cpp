#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 1005

struct edge{
    int to,w;
    
    edge(){}
    edge(int _to, int _w):
        to(_to), w(_w){}
};

bool ok,visited[MAXN],done[MAXN];
vector<edge> L[MAXN];
int h[MAXN],pathxor[MAXN];
int cont[2];

void dfs(int cur, int p, int curh, int val){
    visited[cur] = true;
    h[cur] = curh;
    bool back = true;
    ++cont[val];
    
    for(int i = L[cur].size() - 1,to,w;i >= 0;--i){
        to = L[cur][i].to;
        w = L[cur][i].w;
        
        if(!visited[to]){
            pathxor[curh + 1] = (pathxor[curh] ^ w);
            dfs(to,cur,curh + 1,(val ^ w));
        }else if(!done[to] && (to != p || !back)){
            if((pathxor[curh] ^ pathxor[ h[to] ]) != w)
                ok = false;
        }
        
        if(to == p) back = false;
    }
    
    done[cur] = true;
}

int main(){
    int N;
    char s1[10],s2[10],s3[10];
    
    while(true){
        scanf("%d",&N);
        if(N == 0) break;
        
        for(int i = 1;i <= N;++i)
            L[i].clear();
        
        for(int i = 1,v;i <= N;++i){
            scanf("%s %d %s %s",s1,&v,s2,s3);
            
            if(s3[0] == 'f'){
                L[i].push_back(edge(v,1));
                L[v].push_back(edge(i,1));
            }else{
                L[i].push_back(edge(v,0));
                L[v].push_back(edge(i,0));
            }
        }
        
        memset(visited,false,sizeof visited);
        memset(done,false,sizeof done);
        pathxor[0] = 0;
        ok = true;
        
        int ans = 0;
        
        for(int i = 1;i <= N;++i){
            if(!visited[i]){
                cont[0] = cont[1] = 0;
                dfs(i,0,0,0);
                ans += max(cont[0],cont[1]);
            }
        }
        
        if(!ok) puts("Inconsistent");
        else printf("%d\n",ans);
    }
    
    return 0;
}
