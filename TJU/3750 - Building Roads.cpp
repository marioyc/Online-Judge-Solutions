#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define maxn 2500

struct edge{
    int to,w,id;
    
    edge(){}
    edge(int _to, int _w, int _id):
        to(_to), w(_w), id(_id){}
};

vector<edge> L[maxn];
int u[maxn],v[maxn],w[maxn],parent[maxn],dist[maxn],blocked;

pair<int, int> bfs(int pos){
    pair<int, int> ret(0,pos);
    queue< pair<int, int> > Q;
    
    memset(parent,-1,sizeof parent);
    dist[pos] = 0;
    Q.push(make_pair(0,pos));
    
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        
        ret = max(ret,cur);
        
        for(int i = L[cur.second].size() - 1,to;i >= 0;--i){
            to = L[cur.second][i].to;
            
            if(to != parent[cur.second] && L[cur.second][i].id != blocked){
                parent[to] = cur.second;
                dist[to] = L[cur.second][i].w;
                Q.push(make_pair(cur.first + L[cur.second][i].w,to));
            }
        }
    }
    
    return ret;
}

int get_best(int pos, int D){
    int ret = D,sum = 0;
    
    while(pos != -1){
        sum += dist[pos];
        pos = parent[pos];
        ret = min(ret,max(sum,D - sum));
    }
    
    return ret;
}

int main(){
    int T,n;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&n);
        
        for(int i = 0;i < n;++i) L[i].clear();
        
        for(int i = 1;i < n;++i){
            scanf("%d %d %d",&u[i - 1],&v[i - 1],&w[i - 1]);
            L[ u[i - 1] ].push_back(edge(v[i - 1],w[i - 1],i - 1));
            L[ v[i - 1] ].push_back(edge(u[i - 1],w[i - 1],i - 1));
        }
        
        int ans = 3000000;
        
        for(int i = 1;i < n;++i){
            blocked = i - 1;
            
            pair<int, int> ret1 = bfs(u[i - 1]);
            ret1 = bfs(ret1.second);
            int best1 = get_best(ret1.second,ret1.first);
            
            pair<int, int> ret2 = bfs(v[i - 1]);
            ret2 = bfs(ret2.second);
            int best2 = get_best(ret2.second,ret2.first);
            
            ans = min(ans,max(w[i - 1] + best1 + best2,max(ret1.first, ret2.first)));
        }
        
        printf("Case %d: %d\n",tc,ans);
    }
    
    return 0;
}
