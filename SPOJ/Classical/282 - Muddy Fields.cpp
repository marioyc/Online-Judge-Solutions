#include <cstdio>
#include <vector>
#include <cstring>
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
}G(2500,2500);

int main(){
	int T,R,C;
	scanf("%d",&T);
	
	char M[50][51];
	int hor[50][50],ver[50][50],V1,V2;
	
	for(int tc = 1;tc<=T;++tc){
		scanf("%d %d",&R,&C);
		for(int i = 0;i<R;++i) scanf("%s",M[i]);
		
		memset(hor,-1,sizeof(hor));
		memset(ver,-1,sizeof(ver));
		
		V1 = V2 = -1;
		
		for(int i = 0;i<R;++i){
			for(int j = 0;j<C;++j){
				if(M[i][j]=='*'){
					if(j==0 || hor[i][j-1]==-1)
						hor[i][j] = ++V1;
					else
						hor[i][j] = hor[i][j-1];
					
					if(i==0 || ver[i-1][j]==-1)
						ver[i][j] = ++V2;
					else
						ver[i][j] = ver[i-1][j];
				}
			}
		}
		
		if(V1==-1) printf("0\n");
		else{
			++V1; ++V2;
			G.clear(V1,V2);
		
			for(int i = 0;i<R;++i)
				for(int j = 0;j<C;++j)
					if(M[i][j]=='*')
						G.add_edge(hor[i][j],ver[i][j]);
		
			printf("%d\n",G.maximum_matching());
		}
	}
	
	return 0;
}
