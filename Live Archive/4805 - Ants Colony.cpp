#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAX_N 100000
#define LOG2_MAXN 16

int N,parent[MAX_N],L[MAX_N];
int P[MAX_N][LOG2_MAXN + 1];
long long dist[MAX_N][LOG2_MAXN + 1],to_parent[MAX_N];

void init(){
    memset(P,-1,sizeof(P));
    memset(dist,-1,sizeof(dist));
    
    for(int i = 0;i < N;++i){
        P[i][0] = parent[i];
        dist[i][0] = to_parent[i];
    }
    
    for(int j = 1;(1<<j) < N;++j){
        for(int i = 0;i < N;++i)
            if(P[i][j-1] != -1)
                P[i][j] = P[P[i][j-1]][j-1];
        
        for(int i = 0;i < N;++i)
            if(P[i][j] != -1)
                dist[i][j] = dist[i][j-1] + dist[P[i][j-1]][j-1];
    }
}

long long LCA(int p, int q){
    if(L[p] < L[q]) swap(p,q);
    
    long long ret = 0;
    int log = 1;
    while((1<<log) <= L[p]) ++log;
    --log;
    
    for(int i = log;i >= 0;--i){
        if(L[p] - (1<<i) >= L[q]){
            ret += dist[p][i];
            p = P[p][i];
        }
    }
    
    if(p == q) return ret;
    
    for(int i = log;i >= 0;--i){
        if(P[p][i] != -1 && P[p][i] != P[q][i]){
            ret += dist[p][i] + dist[q][i];
            p = P[p][i];
            q = P[q][i];
        }
    }
    
    ret += to_parent[p] + to_parent[q];
    return ret;
}

vector<int> adj[MAX_N],W[MAX_N];
int Q[MAX_N],head,tail;
bool visited[MAX_N];

void BFS(){
    memset(visited,false,sizeof(visited));
    head = tail = 0;
    Q[0] = 0; ++tail;
    visited[0] = true;
    parent[0] = -1;
    to_parent[0] = 0;
    L[0] = 0;
    
    while(head < tail){
        int pos = Q[head]; ++head;
        
        for(int i = adj[pos].size()-1;i >= 0;--i){
            int next = adj[pos][i];
            
            if(!visited[next]){
                visited[next] = true;
                Q[tail] = next; ++tail;
                parent[next] = pos;
                to_parent[next] = W[pos][i];
                L[next] = L[pos] + 1;
            }
        }
    }
    
    return;
}

int main(){
    int tc = 0;    
    
    while(true){
        scanf("%d",&N);
        if(N == 0) break;
        ++tc;
        
        for(int i = 0;i < N;++i){
            adj[i].clear();
            W[i].clear();
        }
        
        for(int i = 1,v,w;i < N;++i){
            scanf("%d %d",&v,&w);
            adj[i].push_back(v);
            W[i].push_back(w);
            adj[v].push_back(i);
            W[v].push_back(w);
        }
        
        BFS();
        init();
        
        int q,u,v;
        scanf("%d",&q);
        
        while(q--){
            scanf("%d %d",&u,&v);
            
            printf("%lld",LCA(u,v));
            if(q == 0) putchar('\n');
            else putchar(' ');
        }
    }
    
    return 0;
}
