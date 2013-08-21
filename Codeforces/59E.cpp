#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define MAXN 3001
#define MAXM 20001

int id[MAXN][MAXN];
int e[2 * MAXM];

struct edge{
    int id,to;
    
    edge(){}
    edge(int _id, int _to):
        id(_id),to(_to){}
};

struct node{
    int id,pos,dist;
    
    node(){}
    node(int _id, int _pos, int _dist):
        id(_id),pos(_pos),dist(_dist){}
};

vector<edge> L[MAXN];
bool visited[2 * MAXM];
set< pair<int, int> > S;
int par[2 * MAXM];

int main(){
    int N,M,K;
    
    scanf("%d %d %d",&N,&M,&K);
    
    for(int i = 0,u,v;i < M;++i){
        scanf("%d %d",&u,&v);
        id[u][v] = 2 * (i + 1) + 1;
        id[v][u] = 2 * (i + 1);
        
        e[2 * (i + 1)] = u;
        e[2 * (i + 1) + 1] = v;
        
        L[u].push_back(edge(2 * (i + 1) + 1,v));
        L[v].push_back(edge(2 * (i + 1),u));
    }
    
    for(int i = 0,a,b,c;i < K;++i){
        scanf("%d %d %d",&a,&b,&c);
        
        int e1 = id[a][b],e2 = id[b][c];
        
        if(e1 && e2) S.insert(make_pair(e1,e2));
    }
    
    queue<node> Q;
    Q.push(node(1,1,0));
    visited[1] = true;
    par[1] = -1;
    
    while(!Q.empty()){
        node cur = Q.front();
        Q.pop();
        
        if(cur.pos == N){
            printf("%d\n",cur.dist);
            
            int pos = cur.id;
            vector<int> path;
            
            while(pos != 1){
                path.push_back(e[pos]);
                pos = par[pos];
            }
            
            path.push_back(1);
            
            int sz = cur.dist + 1;
            for(int i = sz - 1;i >= 0;--i) printf("%d ",path[i]);
            printf("\n");
            
            return 0;
        }
        
        for(int i = L[cur.pos].size() - 1,e;i >= 0;--i){
            e = L[cur.pos][i].id;
            
            if(!visited[e] && S.find(make_pair(cur.id,e)) == S.end()){
                Q.push(node(e,L[cur.pos][i].to,cur.dist + 1));
                visited[e] = true;
                par[e] = cur.id;
            }
        }
    }
    
    printf("-1\n");
    
    return 0;
}
