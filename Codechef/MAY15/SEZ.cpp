#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 200

int le[MAXN],ri[MAXN];
bool visited[MAXN];
vector<int> L[MAXN];

bool dfs(int cur){
    if(visited[cur]) return false;
    visited[cur] = true;

    for(int i = (int)L[cur].size() - 1;i >= 0;--i){
        int to  = L[cur][i];

        if(le[to] == -1 || dfs(le[to])){
            le[to] = cur;
            ri[cur] = to;
            return true;
        }
    }

    return false;
}

int main(){
    int n,m;

    scanf("%d %d",&n,&m);

    for(int i = 0,u,v;i < m;++i){
        scanf("%d %d",&u,&v);
        --u; --v;
        L[u].push_back(v);
        L[v].push_back(u);
    }

    int ans = n;
    memset(le,-1,sizeof le);
    memset(ri,-1,sizeof ri);
    bool found = true;

    while(found){
        memset(visited,false,sizeof visited);
        found = false;

        for(int i = 0;i < n;++i){
            if(ri[i] == -1 && dfs(i)){
                found = true;
                --ans;
            }
        }
    }

    printf("%d\n",ans);

    return 0;
}