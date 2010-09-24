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
}G(100,100);


int main(){
	int n,m,s,v;
	double x1[100],y1[100],x2[100],y2[100];
	
	while(scanf("%d %d %d %d",&n,&m,&s,&v)==4){
		for(int i = 0;i<n;++i) scanf("%lf %lf",&x1[i],&y1[i]);
		for(int i = 0;i<m;++i) scanf("%lf %lf",&x2[i],&y2[i]);	
		
		G.clear(n,m);
		
		for(int i = 0;i<n;++i)
			for(int j = 0;j<m;++j)
				if((x1[i]-x2[j])*(x1[i]-x2[j])+(y1[i]-y2[j])*(y1[i]-y2[j])<=s*s*v*v+1e-8)
					G.add_edge(i,j);
		
		printf("%d\n",n-G.maximum_matching());
	}
	
	return 0;
}
