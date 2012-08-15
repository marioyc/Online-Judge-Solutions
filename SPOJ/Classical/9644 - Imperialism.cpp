#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> L[10000];
int dist[10000];

pair<int,int> bfs(int s){
    queue<int> Q;
    memset(dist,-1,sizeof dist);
    int last = s;
    
    Q.push(s);
    dist[s] = 0;
    
    while(!Q.empty()){
        int cur = Q.front();
        last = cur;
        Q.pop();
        
        for(int i = L[cur].size() - 1,to;i >= 0;--i){
            to = L[cur][i];
            
            if(dist[to] == -1){
                Q.push(to);
                dist[to] = 1 + dist[cur];
            }
        }
    }
    
    return make_pair(last,dist[last]);
}

int main(){
    int N;
    
    while(true){
        scanf("%d",&N);
        if(N == -1) break;
        
        for(int i = 0;i < N;++i)
            L[i].clear();
        
        for(int i = 1,x;i < N;++i){
            scanf("%d",&x);
            --x;
            
            L[i].push_back(x);
            L[x].push_back(i);
        }
        
        pair<int,int> P = bfs(0);
        P = bfs(P.first);
        
        printf("%d\n",(P.second + 1) / 2);
    }
    
    return 0;
}
