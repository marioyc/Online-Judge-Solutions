#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_V 1+2*1500
#define MAX_E 2*1500
#define NIL 0
 
int E,to[MAX_E],next[MAX_E],last[MAX_V];
 
void init(){
	fill(last,last+MAX_V,-1);
	E = 0;
}
 
void add_edge(int u, int v){
	to[E] = v, next[E] = last[u]; last[u] = E; ++E;
	to[E] = u, next[E] = last[v]; last[v] = E; ++E;
}
 
int n,m,match[MAX_V],dist[MAX_V];
int head,tail,q[MAX_V];
 
bool BFS(){
    head = tail = 0;	
	
    for(int i = 1;i<=n;++i){
        if(match[i]==NIL){
            q[tail] = i; ++tail;
            dist[i] = 0;
        }
        else dist[i] = INT_MAX;
    }
	
	dist[NIL] = INT_MAX;
	
    int u,v;
	
	while(head<tail) {
		u = q[head]; ++head;
		
		for(int e = last[u];e!=-1;e = next[e]){
			v = to[e];
			
			if(dist[match[v]]==INT_MAX){
				dist[match[v]] = dist[u]+1;
				
				if(match[v]!=NIL){
					q[tail] = match[v];
					++tail;
				}
			}
		}
    }
    
    return dist[NIL]!=INT_MAX;
}
 
bool DFS(int u) {
    if(u!=NIL){
        for(int e = last[u];e!=-1;e = next[e]){
			int v = to[e];
			
            if(dist[match[v]]==dist[u]+1) {
                if(DFS(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        
        dist[u] = INT_MAX;
        return false;
    }
    return true;
}
 
int hopcroft_karp() {
	int ret = 0;
	fill(match,match+(n+m+1),NIL);
	
	while(BFS())
		for(int i=1;i<=n;++i)
			if(match[i]==NIL && DFS(i))
				++ret;
	
	return ret;
}

int main(){
	bool visited[1500],V1[1500];
	
	while(scanf("%d",&n)==1){
		vector<int> L[n];
		
		for(int i = 0;i<n;++i){
			int u,v,e;
			scanf("%d:(%d)",&u,&e);
			
			for(int j = 0;j<e;++j){
				scanf("%d",&v);
				L[u].push_back(v);
				L[v].push_back(u);
			}
		}
		
		memset(visited,false,sizeof(visited));
		memset(V1,false,sizeof(V1));
		
		for(int i = 0;i<n;++i){
			if(!visited[i]){
				queue<int> Q;
				Q.push(i);
				visited[i] = true;
				V1[i] = true;
				
				while(!Q.empty()){
					int aux = Q.front();
					Q.pop();
					
					for(int j = L[aux].size()-1;j>=0;--j){
						int v = L[aux][j];
						
						if(!visited[v]){
							Q.push(v);
							visited[v] = true;
							V1[v] = !V1[aux];
						}
					}
				}
			}
		}
		
		m = n;
		init();
		
		for(int i = 0;i<n;++i){
			if(V1[i]){
				for(int j = L[i].size()-1;j>=0;--j){
					int v = L[i][j];
					if(!V1[v]) add_edge(1+i,1+n+v);
				}
			}
		}
		
		printf("%d\n",hopcroft_karp());
	}
	
	return 0;
}
