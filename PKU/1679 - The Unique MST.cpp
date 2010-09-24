#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_V 100

struct edge{
	int u,v,w;
	
	edge(){}
	
	edge(int u, int v, int w) : u(u), v(v), w(w){}
	
	bool operator < (edge X)const{
		return w<X.w;
	}
	
	bool operator != (edge X)const{
		return (u!=X.u || v!=X.v);
	}
}L[MAX_V*MAX_V],MST[MAX_V];

int parent[MAX_V],rank[MAX_V];

void Make_Set(int x){
	parent[x] = x; rank[x] = 0;
}

int Find(int x){
	if(parent[x]!=x) parent[x] = Find(parent[x]);
	return parent[x];
}

void Union(int x, int y){
	int PX = Find(x), PY = Find(y);
	
	if(rank[PX]>rank[PY]) parent[PY] = PX;
	else{
		parent[PX] = PY;
		if(rank[PX]==rank[PY]) ++rank[PY];
	}
}

int V,E;

int erase(edge &e){
	int ret = 0, cont = V;
	
	for(int i = 0;i<V;++i) Make_Set(i);
	
	for(int i = 0,j = 0;i<E;++i){
		if(e!=L[i] && Find(L[i].u)!=Find(L[i].v)){
			Union(L[i].u,L[i].v);
			ret += L[i].w;
			--cont;
		}
	}
	
	if(cont!=1) return -1;
	return ret;
}

int main(){
	int T,u,v,w;
	
	scanf("%d",&T);
	
	while(T--){
		scanf("%d %d",&V,&E);
		
		for(int i = 0;i<E;++i){
			scanf("%d %d %d",&u,&v,&w);
			--u; --v;
			L[i] = edge(u,v,w);
		}
		
		sort(L,L+E);
		
		int MST_W = 0;
		
		for(int i = 0;i<V;++i) Make_Set(i);
		
		for(int i = 0,j = 0;i<E;++i){
			if(Find(L[i].u)!=Find(L[i].v)){
				Union(L[i].u,L[i].v);
				MST_W += L[i].w;
				MST[j++] = L[i];
			}
		}
		
		bool unique = true;
		
		for(int i = 0;i+1<V;++i){
			int aux = erase(MST[i]);
			
			if(aux!=-1 && aux==MST_W)
				unique = false;
		}
		
		if(unique) printf("%d\n",MST_W);
		else printf("Not Unique!\n");
	}
	
	return 0;
}
