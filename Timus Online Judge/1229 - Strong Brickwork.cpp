#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int N,M,G[100][100],id[100][100];
int dr[] = {-1,1,0,0},dc[] = {0,0,-1,1};

int V1,V2,le[5000],ri[5000];
vector<int> L[5000];
bool visited[5000];

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

int max_match(){
    int ret = 0;
    memset(le,-1,sizeof le);
    memset(ri,-1,sizeof ri);
    bool found = true;
    
    while(found){
        memset(visited,false,sizeof visited);
        found = false;
        
        for(int i = 0;i < V1;++i)
            if(ri[i] == -1) found |= dfs(i);
    }
    
    for(int i = 0;i < V1;++i)
        if(ri[i] != -1) ++ret;
    
    return ret;
}

int main(){
    scanf("%d %d",&N,&M);
    
    for(int i = 0;i < N;++i)
        for(int j = 0;j < M;++j)
            scanf("%d",&G[i][j]);
    
    V1 = V2 = 0;
    
    for(int i = 0;i < N;++i){
        for(int j = 0;j < M;++j){
            if((i + j) & 1) id[i][j] = V1++;
            else id[i][j] = V2++;
        }
    }
    
    for(int i = 0;i < N;++i){
        for(int j = 0;j < M;++j){
            if((i + j) & 1){
                for(int k = 0;k < 4;++k){
                    int r = i + dr[k],c = j + dc[k];
                    
                    if(r >= 0 && r < N && c >= 0 && c < M && G[r][c] != G[i][j])
                        L[ id[i][j] ].push_back(id[r][c]);
                }
            }
        }
    }
    
    if(max_match() < V1) printf("-1\n");
    else{
        for(int i = 0,cont = 0;i < N;++i){
            for(int j = 0;j < M;++j){
                if((i + j) & 1){
                    for(int k = 0;k < 4;++k){
                        int r = i + dr[k],c = j + dc[k];
                        
                        if(r >= 0 && r < N && c >= 0 && c < M && id[r][c] == ri[ id[i][j] ]){
                            ++cont;
                            G[i][j] = cont;
                            G[r][c] = cont;
                        }
                    }
                }
            }
        }
        
        for(int i = 0;i < N;++i){
            for(int j = 0;j < M;++j){
                if(j) putchar(' ');
                printf("%d",G[i][j]);
            }
            putchar('\n');
        }
    }
    
    return 0;
}
