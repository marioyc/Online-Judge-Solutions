#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct bipartite_graph{
    int V1,V2,*match;
    vector<int> *L;
    bool *visited;
    
    bipartite_graph(int MAX_V1, int MAX_V2){
    	V1 = MAX_V1; V2 = MAX_V2;
        L = new vector<int>[MAX_V1];
        visited = new bool[MAX_V2];
        match = new int[MAX_V2];
    }
    
    void add_edge(int v1, int v2){
        L[v1].push_back(v2);
    }
    
    bool dfs(int u){
        for(int i = L[u].size()-1;i>=0;--i){
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
        
        for(int i = 0;i<V1;++i){
            fill(visited,visited+V2,false);
            ans += dfs(i);
        }
        
        return ans;
    }
};

int main(){
	int n;
	scanf("%d",&n);
	
	int a[n];
	for(int i = 0;i < n;++i) scanf("%d",&a[i]);
	sort(a,a+n);
	
	bipartite_graph G(n,n);
	
	for(int i = 0;i < n;++i)
		for(int j = 0;j < i;++j)
			if(a[i] % a[j] == 0)
				G.add_edge(i,j);
	
	printf("%d\n",n - G.maximum_matching());
	
	bool visited[2 * n],used[2 * n];
	memset(visited,false,sizeof(visited));
	memset(used,false,sizeof(used));
	
	for(int i = 0;i < n;++i)
	    if(G.match[i] != -1)
	        used[G.match[i]] = true;
	
	for(int i = 0;i < n;++i){
		if(!used[i]){
			queue<int> Q;
			
			visited[i] = true,
			Q.push(i);
			
			while(!Q.empty()){
			    int cur = Q.front();
			    Q.pop();
			    
			    if(cur < n){
			        for(int j = 0;j < cur;++j){
			            if(!visited[n + j] && a[cur] % a[j] == 0 && G.match[j] != cur){
			                visited[n + j] = true;
			                Q.push(n + j);
			            }
			        }
			    }else{
			        cur -= n;
			        
			        for(int j = cur + 1;j < n;++j){
			            if(!visited[j] && a[j] % a[cur] == 0 && G.match[cur] == j){
			                visited[j] = true;
			                Q.push(j);
			            }
			        }
			    }
			}
		}
	}
	
	for(int i = 0;i < n;++i)
	    if(visited[i] && !visited[n + i])
	        printf("%d ",a[i]);
	
	printf("\n");
	
	return 0;
}

