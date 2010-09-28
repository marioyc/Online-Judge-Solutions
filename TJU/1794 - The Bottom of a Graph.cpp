#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

#define MAX_V 5000

vector<int> L[MAX_V];
int V,dfsPos,dfsNum[MAX_V],lowlink[MAX_V],num_scc,scc[MAX_V];
bool in_stack[MAX_V];
stack<int> S;

void tarjan(int v){
	dfsNum[v] = lowlink[v] = dfsPos++;
	S.push(v); in_stack[v] = true;
	
	for(int i = L[v].size()-1;i>=0;--i){
		int w = L[v][i];
		
		if(dfsNum[w]==-1){
			tarjan(w);
			lowlink[v] = min(lowlink[v],lowlink[w]);
		}else if(in_stack[w]) lowlink[v] = min(lowlink[v],lowlink[w]);
	}
	
	if(dfsNum[v]==lowlink[v]){
		int aux;
		
		do{
			aux = S.top(); S.pop();
			scc[aux] = num_scc;
			in_stack[aux] = false;
		}while(aux!=v);
		
		++num_scc;
	}
}

void build_scc(){
	memset(dfsNum,-1,sizeof(dfsNum));
	memset(in_stack,false,sizeof(in_stack));
	dfsPos = num_scc = 0;
	
	for(int i = 0;i<V;++i)
		if(dfsNum[i]==-1)
			tarjan(i);
}

int main(){
	int E,u,v;
	bool bottom[MAX_V];
	
	while(true){
		scanf("%d",&V);
		if(V==0) break;
		
		scanf("%d",&E);
		
		for(int i = 0;i<V;++i) L[i].clear();
		
		for(int i = 0;i<E;++i){
			scanf("%d %d",&u,&v);
			--u; --v;
			L[u].push_back(v);
		}
		
		build_scc();
		memset(bottom,true,sizeof(bottom));
		
		for(int i = 0;i<V;++i){
			for(int j = L[i].size()-1;j>=0;--j){
				int v = L[i][j];
				if(scc[v]!=scc[i]) bottom[scc[i]] = false;
			}
		}
		
		for(int i = 0,k = 0;i<V;++i){
			if(!bottom[scc[i]]) continue;
			if(k==1) printf(" "); k = 1;
			printf("%d",1+i);
		}
		
		printf("\n");
	}
	
	return 0;
}
