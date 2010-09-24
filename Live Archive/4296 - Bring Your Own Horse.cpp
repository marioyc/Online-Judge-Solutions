#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

#define MAX_V 3000
#define MAX_E 100000

struct edge{
	int u,v,w;
	
	edge(){}
	
	edge(int _u, int _v, int _w){
		u = _u; v = _v; w = _w;
	}
	
	bool operator < (edge X)const{
		return w<X.w;
	}
}a[MAX_E];

vector< pair<int,int> > L[MAX_V];
int parent[MAX_V],rank[MAX_V];

void Make_Set(int x){
	parent[x] = x;
	rank[x] = 0;
}

int Find(int x){
	if(parent[x]!=x) parent[x] = Find(parent[x]);
	return parent[x];
}

void Union(int x, int y){
	int PX = Find(x),PY = Find(y);
	
	if(rank[PX]>rank[PY]) parent[PY] = PX;
	else{
		parent[PX] = PY;
		if(rank[PX]==rank[PY]) ++rank[PY];
	}
}

bool visited[MAX_V];
int level[MAX_V],ancestor[MAX_V][12],w[MAX_V][12];

void make_tree(int l, int pos){
	visited[pos] = true;
	level[pos] = l;
	
	for(int i = L[pos].size()-1;i>=0;--i){
		int next = L[pos][i].first;
		if(!visited[next]){
			ancestor[next][0] = pos;
			w[next][0] = L[pos][i].second;
			make_tree(l+1,next);
		}
	}
}

void initialize(int V){
	for(int i = 1;(1<<i)<V;++i){
		for(int j = 0;j<V;++j){
			if(ancestor[j][i-1]!=-1){
				ancestor[j][i] = ancestor[ancestor[j][i-1]][i-1];
				w[j][i] = max(w[j][i-1],w[ancestor[j][i-1]][i-1]);
			}
		}
	}
}

int solve(int p, int q){
	if(level[p]<level[q]) swap(p,q);
	
	int log = 1;
	while((1<<log)<=level[p]) ++log;
	--log;
	
	int ans = -1;
	
	for(int i = log;i>=0;--i){
		if(level[p]-(1<<i)>=level[q]){
			ans = max(ans,w[p][i]);
			p = ancestor[p][i];
		}
	}
	
	if(p==q) return ans;
	
	for(int i = log;i>=0;--i){
		if(ancestor[p][i]!=-1 && ancestor[p][i]!=ancestor[q][i]){
			ans = max(ans,max(w[p][i],w[q][i]));
			p = ancestor[p][i]; q = ancestor[q][i];
		}
	}
	
	ans = max(ans,max(w[p][0],w[q][0]));
	return ans;
}

int main(){
	int T,V,E,Q,u,v;
	scanf("%d",&T);
	
	for(int tc = 1;tc<=T;++tc){
		scanf("%d %d",&V,&E);
		
		for(int i = 0;i<E;++i){
			scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
			--a[i].u; --a[i].v;
		}
		
		sort(a,a+E);
		
		for(int i = 0;i<V;++i){
			L[i].clear();
			Make_Set(i);
		}
		
		for(int i = 0;i<E;++i){
			if(Find(a[i].u)!=Find(a[i].v)){
				Union(a[i].u,a[i].v);
				L[a[i].u].push_back(make_pair(a[i].v,a[i].w));
				L[a[i].v].push_back(make_pair(a[i].u,a[i].w));
			}
		}
		
		memset(visited,false,sizeof(visited));
		memset(ancestor,-1,sizeof(ancestor));
		ancestor[0][0] = w[0][0] = -1;
		
		make_tree(0,0);
		initialize(V);
		
		printf("Case %d\n",tc);
		scanf("%d",&Q);
		
		for(int q = 0;q<Q;++q){
			scanf("%d %d",&u,&v);
			--u; --v;
			printf("%d\n",solve(u,v));
		}
		
		printf("\n");
	}
	
	return 0;
}
