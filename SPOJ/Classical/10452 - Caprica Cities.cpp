#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int X[1000],Y[1000],A,B;
bool inY[1000],visited[1000];
vector<int> L[1000],W[1000];

int dijkstra(){
    memset(visited,false,sizeof visited);
    priority_queue< pair<int, int> > Q;
    
    for(int i = 0;i < A;++i)
        Q.push(make_pair(0,X[i]));
    
    while(!Q.empty()){
        pair<int, int> cur = Q.top();
        Q.pop();
        
        if(visited[cur.second]) continue;
        visited[cur.second] = true;
        
        if(inY[cur.second]) return -cur.first;
        
        for(int i = L[cur.second].size() - 1;i >= 0;--i){
            int to = L[cur.second][i];
            int w = W[cur.second][i];
            
            if(!visited[to])
                Q.push(make_pair(cur.first - w,to));
        }
    }
    
    return -1;
}

int main(){
    int N,M;
    
    while(true){
        scanf("%d %d %d %d",&N,&M,&A,&B);
        if(N == 0 && M == 0 && A == 0 && B == 0) break;
        
        for(int i = 0;i < A;++i)
            scanf("%d",&X[i]);
        for(int i = 0;i < B;++i)
            scanf("%d",&Y[i]);
        
        for(int i = 0;i < N;++i){
            L[i].clear();
            W[i].clear();
        }
        
        for(int i = 0,u,v,w;i < M;++i){
            scanf("%d %d %d",&u,&v,&w);
            
            L[u].push_back(v);
            W[u].push_back(w);
            
            L[v].push_back(u);
            W[v].push_back(w);
        }
        
        memset(inY,false,sizeof inY);
        
        for(int i = 0;i < B;++i)
            inY[ Y[i] ] = true;
        
        printf("%d\n",dijkstra());
    }
    
    return 0;
}

