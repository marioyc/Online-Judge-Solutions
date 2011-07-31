#include <cstdio>
#include <map>

using namespace std;

int parent[10000],uf_rank[10000],dist[10000];

void init(int x){
	parent[x] = x;
	uf_rank[x] = 0;
	dist[x] = 0;
}

int Find(int x){
	if(parent[x] != x){
		int PX = parent[x];
		parent[x] = Find(PX);
		dist[x] ^= dist[PX];
	}
	
	return parent[x];
}

void Union(int u, int v, int d){
	int PU = Find(u),PV = Find(v);
	
	if(uf_rank[PU] < uf_rank[PV]){
		parent[PU] = PV;
		dist[PU] = d ^ dist[u] ^ dist[v];
	}else{
		parent[PV] = PU;
		dist[PV] = d ^ dist[u] ^ dist[v];
		if(uf_rank[u] == uf_rank[v]) ++uf_rank[u];
	}
}

int main(){
	int L,Q,u,v;
	map<int, int> id;
	char s[5];
	
	while(true){
		scanf("%d",&L);
		if(L == -1) break;
		
		scanf("%d",&Q);
		
		int ans = 0,cont = 0;
		bool valid = true;
		id.clear();
		
		while(Q--){
			scanf("%d %d %s",&u,&v,s);
			
			if(valid){
				if(u <= 0 || u > L || v <= 0 || v > L || u > v) valid = false;
				else{
					--u;
					
					if(id.find(u) == id.end()){
						init(cont);
						id[u] = cont++;
					}
					
					if(id.find(v) == id.end()){
						init(cont);
						id[v] = cont++;
					}
					
					u = id[u]; v = id[v];
					
					int PU = Find(u),PV = Find(v),d = (s[0] == 'e'? 0 : 1);
					
					if(PU == PV && (dist[u] ^ dist[v] ^ d) == 1) valid = false;
					else if(PU != PV) Union(u,v,d);
					
					if(valid) ++ans;
				}
			}
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
