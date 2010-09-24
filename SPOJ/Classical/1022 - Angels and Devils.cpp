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
}G(150*300,150*300);

int main(){
	int T,R,C;
	scanf("%d",&T);
	
	char M[300][600];
	int hor[300][300],ver[300][300],V1,V2;
	
	for(int tc = 1;tc<=T;++tc){
		scanf("%d %d",&R,&C);
		
		for(int i = 0;i<R;++i) for(int j = 0;j<C;++j){
			scanf(" %c",&M[i][j]);
			hor[i][j] = ver[i][j] = -1;
		}
		
		V1 = V2 = 0;
		
		for(int i = 0;i<R;++i) for(int j = 0;j<C;++j){
			if(M[i][j]!='A'){
				if(j==0 || M[i][j-1]=='A')
					hor[i][j] = V1++;
				else
					hor[i][j] = hor[i][j-1];
				
				if(i==0 || M[i-1][j]=='A')
					ver[i][j] = V2++;
				else
					ver[i][j] = ver[i-1][j];
			}
		}
		
		G.clear(V1,V2);
		
		for(int i = 0;i<R;++i)
			for(int j = 0;j<C;++j)
				if(M[i][j]=='H')
					G.add_edge(hor[i][j],ver[i][j]);
		
		printf("%d\n",G.maximum_matching());
	}
	
	return 0;
}
