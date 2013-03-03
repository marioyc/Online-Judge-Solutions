#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 50005

struct edge{
    int to,w;
    
    edge(){}
    edge(int _to, int _w):
        to(_to), w(_w){}
};

vector<edge> L[MAXN];
bool visited[MAXN];
int dist[MAXN];

int main(){
    int N,M,B;
    
    scanf("%d %d %d",&N,&M,&B);
    
    for(int i = 0,u,v,w;i < M;++i){
        scanf("%d %d %d",&u,&v,&w);
        L[u].push_back(edge(v,w));
        L[v].push_back(edge(u,w));
    }
    
    priority_queue< pair<int, int>, vector< pair<int,int> >, greater< pair<int, int> > > Q;
    Q.push(make_pair(0,1));
    
    while(!Q.empty()){
        pair<int, int> cur = Q.top();
        Q.pop();
        
        if(visited[cur.second]) continue;
        visited[cur.second] = true;
        dist[cur.second] = cur.first;
        
        for(int i = L[cur.second].size() - 1,to,w;i >= 0;--i){
            to = L[cur.second][i].to;
            w = cur.first + L[cur.second][i].w;
            
            if(!visited[to])
                Q.push(make_pair(w,to));
        }
    }
    
    for(int i = 0,u,v;i < B;++i){
        scanf("%d %d",&u,&v);
        printf("%d\n",dist[u] + dist[v]);
    }
    
    return 0;
}
