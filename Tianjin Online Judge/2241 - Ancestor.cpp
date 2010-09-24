#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_V 10000

int N,ancestor[MAX_V][14],level[MAX_V];
vector<int> L[MAX_V];
bool visited[MAX_V];

void search(int l, int pos){
	visited[pos] = true;
	level[pos] = l;
	
	for(int i = L[pos].size()-1;i>=0;--i){
		int next = L[pos][i];
		
		if(!visited[next]){
			ancestor[next][0] = pos;
			search(l+1,next);
		}
	}
}

void initialize(){
	for(int i = 1;(1<<i)<N;++i)
		for(int j = 0;j<N;++j)
			if(ancestor[j][i-1]!=-1)
				ancestor[j][i] = ancestor[ancestor[j][i-1]][i-1];
}

bool is_ancestor(int p, int q){
	if(level[p]>=level[q]) return false;
	
	int log = 1;
	while((1<<log)<=level[q]) ++log;
	--log;
	
	for(int i = log;i>=0;--i)
		if(level[q]-(1<<i)>=level[p])
			q = ancestor[q][i];
	
	return p==q;
}

int main(){
	int T,Q,u,v;
	scanf("%d",&T);
	
	for(int tc = 1;tc<=T;++tc){
		scanf("%d",&N);
		
		for(int i = 0;i<N;++i) L[i].clear();
		
		for(int i = 1;i<N;++i){
			scanf("%d %d",&u,&v);
			L[u].push_back(v);
			L[v].push_back(u);
		}
		
		memset(visited,false,sizeof(visited));
		memset(ancestor,-1,sizeof(ancestor));
		ancestor[0][0] = -1;
		
		search(0,0);
		initialize();
		
		scanf("%d",&Q);
		
		for(int q = 0;q<Q;++q){
			scanf("%d %d",&u,&v);
			printf("%s\n",is_ancestor(u,v)? "Yes":"No");
		}
		
		printf("\n");
	}
	
	return 0;
}
