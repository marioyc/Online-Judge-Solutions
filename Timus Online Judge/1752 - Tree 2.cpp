#include <cstdio>
#include <vector>
#include <map>

using namespace std;

#define MAXN 20001

vector<int> L[MAXN];
bool visited[MAXN];

pair<int, int> down[MAXN][2],best[MAXN][2];

int to[MAXN],D[MAXN],D2[MAXN];
int P[15][MAXN],level[MAXN];

void dfs(int cur, int prev, int lvl){
    down[cur][0] = make_pair(cur,0);
    down[cur][1] = make_pair(0,0);
    
    P[0][cur] = prev;
    level[cur] = lvl;
    
    for(int i = L[cur].size() - 1,nxt;i >= 0;--i){
        nxt = L[cur][i];
        
        if(nxt != prev){
            dfs(nxt,cur,lvl + 1);
            
            if(1 + down[nxt][0].second > down[cur][1].second){
                down[cur][1] = down[nxt][0];
                ++down[cur][1].second;
                
                if(down[cur][1].second > down[cur][0].second)
                    swap(down[cur][0],down[cur][1]);
            }
        }
    }
}

void dfs2(int cur, int prev){
    best[cur][0] = down[cur][0];
    best[cur][1] = down[cur][1];
    
    if(prev != -1){
        for(int i = 0;i < 2;++i){
            if(best[prev][i].first != down[cur][0].first){
                if(1 + best[prev][i].second > best[cur][1].second){
                    best[cur][1] = best[prev][i];
                    ++best[cur][1].second;
                }
                
                if(best[cur][1].second > best[cur][0].second)
                    swap(best[cur][0],best[cur][1]);
                
                break;
            }
        }
    }
    
    for(int i = L[cur].size() - 1,nxt;i >= 0;--i){
        nxt = L[cur][i];
        if(nxt != prev) dfs2(nxt,cur);
    }
}

void init_lca(int N){
    for(int i = 1;(1 << i) < N;++i)
        for(int j = 1;j <= N;++j)
            if(P[i - 1][j] != -1)
                P[i][j] = P[i - 1][ P[i - 1][j] ];
}

pair<int, int> get_lca(int x, int y){
    if(level[x] < level[y]) swap(x,y);
    
    int dist = level[x] - level[y];
    
    for(int i = 14;i >= 0;--i)
        if(dist & (1 << i))
            x = P[i][x];
    
    for(int i = 14;i >= 0;--i){
        if(P[i][x] != P[i][y]){
            dist += (1 << (i + 1));
            x = P[i][x];
            y = P[i][y];
        }
    }
    
    if(x != y){
        x = P[0][x];
        y = P[0][y];
        dist += 2;
    }
    
    return make_pair(x,dist);
}

int go_up(int x, int d){
    for(int i = 0;i <= 14;++i,d >>= 1)
        if(d & 1) x = P[i][x];
    
    return x;
}

int main(){
    int N,Q;
    
    scanf("%d %d",&N,&Q);
    
    for(int i = 1,u,v;i < N;++i){
        scanf("%d %d",&u,&v);
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    dfs(1,-1,0);
    dfs2(1,-1);
    init_lca(N);
    
    for(int i = 1;i <= N;++i)
        to[i] = best[i][0].first;
    
    for(int i = 1;i <= N;++i){
        pair<int,int> aux = get_lca(i,to[i]);
        
        D[i] = level[i] - level[aux.first];
        D2[i] = level[ to[i] ] - level[aux.first];
    }
    
    for(int i = 0,x,d;i < Q;++i){
        scanf("%d %d",&x,&d);
        
        if(d > D[x] + D2[x]) puts("0");
        else if(d <= D[x]) printf("%d\n",go_up(x,d));
        else printf("%d\n",go_up(to[x],D2[x] + D[x] - d));
    }
    
    return 0;
}
