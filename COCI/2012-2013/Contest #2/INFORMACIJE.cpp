#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 201

int s[MAXN],e[MAXN];
int mn[MAXN],mx[MAXN];

vector<int> L[MAXN];
bool visited[MAXN];
int ri[MAXN],le[MAXN];

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

int main(){
    int N,M;
    
    scanf("%d %d",&N,&M);
    
    for(int i = 1;i <= N;++i){
        s[i] = 1;
        e[i] = N;
        mn[i] = 1;
        mx[i] = N;
    }
    
    for(int i = 0,op,x,y,v;i < M;++i){
        scanf("%d %d %d %d",&op,&x,&y,&v);
        
        s[v] = max(s[v],x);
        e[v] = min(e[v],y);
        
        if(op == 1){
            for(int j = x;j <= y;++j)
                mx[j] = min(mx[j],v);
        }else{
            for(int j = x;j <= y;++j)
                mn[j] = max(mn[j],v);
        }
    }
    
    for(int i = 1;i <= N;++i)
        for(int j = 1;j <= N;++j)
            if(s[j] <= i && i <= e[j] && mn[i] <= j && j <= mx[i])
                L[i].push_back(j);
    
    int match = 0;
    bool found = true;
    memset(ri,-1,sizeof ri);
    memset(le,-1,sizeof le);
    
    while(found){
        found = false;
        memset(visited,false,sizeof visited);
        
        for(int i = 1;i <= N;++i)
            if(ri[i] == -1 && dfs(i))
                ++match,found = true;
    }
    
    if(match < N) puts("-1");
    else{
        for(int i = 1;i <= N;++i){
            printf("%d",ri[i]);
            if(i == N) printf("\n");
            else printf(" ");
        }
    }
    
    return 0;
}
