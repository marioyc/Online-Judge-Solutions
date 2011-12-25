#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct node{
	int pos,par,dist;
	
	node(){}
	
	node(int _pos, int _par, int _dist){
		pos = _pos; par = _par; dist = _dist;
	}
	
	bool operator < (node X)const{
		return dist > X.dist;
	}
};

int M[100][100],dist[100],par[100];
bool visited[100];
vector<int> e_to[100],e_w[100];

int main(){
	int V,E,u,v,w;
	
	while(true){
		scanf("%d",&V);
		if(V == -1) break;
		
		scanf("%d",&E);
		
		memset(M,-1,sizeof(M));
		
		for(int i = 0;i < V;++i){
			e_to[i].clear();
			e_w[i].clear();
		}
		
		while(E--){
			scanf("%d %d %d",&u,&v,&w);
			--u; --v;
			
			if(M[u][v] == -1 || w < M[u][v]) M[u][v] = M[v][u] = w;
			
			e_to[u].push_back(v);
			e_w[u].push_back(w);
			
			e_to[v].push_back(u);
			e_w[v].push_back(w);
		}
		
		int S = -1,E = -1,best = 0;
		vector<int> ans;
		
		for(int s = 0;s < V;++s){
			for(int e = s + 1;e < V;++e){
				if(M[s][e] != -1){
					int W = M[s][e];
					memset(visited,false,sizeof(visited));
					memset(dist,-1,sizeof(dist));
					
					priority_queue<node> Q;
					Q.push(node(s,-1,0));
					
					while(!Q.empty()){
						node cur = Q.top();
						Q.pop();
						
						if(visited[cur.pos]) continue;
						visited[cur.pos] = true;
						
						for(int i = e_to[cur.pos].size() - 1,to;i >= 0;--i){
							to = e_to[cur.pos][i];
							
							if((dist[to] == -1 || cur.dist + e_w[cur.pos][i] < dist[to]) && (cur.pos != s || (cur.pos == s && to != e))){
								Q.push(node(to,cur.pos,cur.dist + e_w[cur.pos][i]));
								dist[to] = cur.dist + e_w[cur.pos][i];
								par[to] = cur.pos;
							}
						}
					}
					
					if(dist[e] != -1 && (S == -1 || dist[e] + W < best)){
						best = dist[e] + W;
						S = s; E = e;
						ans.clear();
						
						int pos = e;
						ans.push_back(pos + 1);
						
						while(pos != s){
							pos = par[pos];
							ans.push_back(pos + 1);
						}
					}
				}
			}
		}
		
		if(S == -1) puts("No solution.");
		else{
			int n = ans.size();
			
			printf("%d",ans.back());
			ans.pop_back();
			
			while(!ans.empty()){
				printf(" %d",ans.back());
				ans.pop_back();
			}
			
			printf("\n");
		}
	}
	
	return 0;
}
