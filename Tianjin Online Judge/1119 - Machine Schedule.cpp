#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct bipartite_graph{
    int V1,V2,*match;
    vector<int> *L;
    bool *visited;
    
    bipartite_graph(int MAX_V1, int MAX_V2){
        L = new vector<int>[MAX_V1];
        visited = new bool[MAX_V2];
        match = new int[MAX_V2];
    }
    
    void clear(int _V1, int _V2){
        V1 = _V1; V2 = _V2;
        for(int i=0;i<V1;++i) L[i].clear();
    }
    
    void add_edge(int v1, int v2){
        L[v1].push_back(v2);
    }
    
    bool dfs(int u){
        for(int i=L[u].size()-1;i>=0;--i){
            int v = L[u][i];
            if(!visited[v]){
                visited[v] = true;
                if(match[v]==-1 || dfs(match[v])){
                    match[v] = u;
                    return true;
                }
            }
         }
         return false;
    }

    int maximum_matching(){
        int ans = 0;
        fill(match,match+V2,-1);
        
        for(int i=0;i<V1;++i){
            fill(visited,visited+V2,false);
            ans += dfs(i);
        }
        
        return ans;
    }
};

int main(){
    int V1,V2,K,id,u,v;
    bipartite_graph G(100,100);
    
    while(scanf("%d %d %d",&V1,&V2,&K)==3){
        G.clear(V1,V2);
        
        for(int i=0;i<K;++i){
            scanf("%d %d %d",&id,&u,&v);
            if(u*v==0) continue;
            G.add_edge(u,v);
        }
        
        printf("%d\n",G.maximum_matching());
    }
    
    return 0;
}
