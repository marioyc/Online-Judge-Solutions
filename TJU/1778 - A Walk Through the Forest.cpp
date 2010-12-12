#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<int> L[1000],W[1000];
int dist[1000];

void dijkstra(){
    priority_queue< pair<int, int> > Q;
    memset(dist,-1,sizeof(dist));
    
    Q.push(make_pair(0,1));
    
    while(!Q.empty()){
        int cur = Q.top().second,d = -Q.top().first;
        Q.pop();
        
        if(dist[cur]!=-1) continue;
        dist[cur] = d;
        
        for(int i = L[cur].size()-1;i>=0;--i){
            int next = L[cur][i],w = W[cur][i];
            
            if(dist[next]!=-1) continue;
            Q.push(make_pair(-d-w,next));
        }
    }
}

long long memo[1000];

long long count(int cur){
    if(cur==1) return 1;
    
    long long &ret = memo[cur];
    
    if(ret==-1){
        ret = 0;
        
        for(int i = L[cur].size()-1;i>=0;--i){
            int next = L[cur][i];
            
            if(dist[next]!=-1 && dist[next]<dist[cur])
                ret += count(next);
        }
    }
    
    return ret;
}

int main(){
    int N,M;
    
    while(true){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i = 0;i<N;++i){
            L[i].clear();
            W[i].clear();
        }
        
        scanf("%d",&M);
        
        for(int i = 0,u,v,w;i<M;++i){
            scanf("%d %d %d",&u,&v,&w);
            --u; --v;
            
            L[u].push_back(v);
            W[u].push_back(w);
            L[v].push_back(u);
            W[v].push_back(w);
        }
        
        dijkstra();
        
        memset(memo,-1,sizeof(memo));
        printf("%lld\n",count(0));
    }
    
    return 0;
}
