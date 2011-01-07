#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct node{
    int cur,dist;
    
    node(){}
    
    node(int _cur, int _dist){
        cur = _cur; dist = _dist;
    }
    
    bool operator < (node X)const{
        return dist>X.dist;
    }
}aux;

int A,B,C;
int dist[1001][1001],adj[1001][1001];
vector<int> L[1001],W[1001],F[1001];
int visited[1001],count[1001];

int solve(){
    memset(visited,-1,sizeof(visited));
    memset(count,0,sizeof(count));
    priority_queue<node> Q;
    
    visited[1] = 1;
    count[1] = 1;
    Q.push(node(1,0));
    
    while(!Q.empty()){
        aux = Q.top();
        Q.pop();
        
        int cur = aux.cur,dist = aux.dist;
        
        if(dist>visited[cur]) continue;
        
        for(int i = L[cur].size()-1,nxt;i>=0;--i){
            nxt = L[cur][i];
            
            if(visited[nxt]==-1 || dist+W[cur][i]<visited[nxt]){
                visited[nxt] = dist+W[cur][i];
                count[nxt] = count[cur]*F[cur][i];
                Q.push(node(nxt,visited[nxt]));
            }else if(visited[nxt]==dist+W[cur][i]){
                count[nxt] += count[cur]*F[cur][i];
            }
        }
    }
    
    return count[B];
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&A,&B,&C);
        
        for(int i = 1;i<=A;++i)
            for(int j = i+1;j<=A;++j)
                dist[i][j] = dist[j][i] = 1001;
        
        memset(adj,0,sizeof(adj));
        
        for(int i = 0,x,y,l;i<C;++i){
            scanf("%d %d %d",&x,&y,&l);
            if(l<dist[x][y]){
                dist[x][y] = dist[y][x] = l;
                adj[x][y] = adj[y][x] = 1;
            }else if(l==dist[x][y]){
                ++adj[x][y];
                ++adj[y][x];
            }
        }
        
        for(int i = 1;i<=A;++i){
            L[i].clear();
            W[i].clear();
            F[i].clear();
        }
        
        for(int i = 1;i<=A;++i) for(int j = i+1;j<=A;++j){
            if(adj[i][j]>0){
                L[i].push_back(j);
                L[j].push_back(i);
                W[i].push_back(dist[i][j]);
                W[j].push_back(dist[i][j]);
                F[i].push_back(adj[i][j]);
                F[j].push_back(adj[i][j]);
            }
        }
        
        printf("%d\n",solve());
    }
    
    return 0;
}
