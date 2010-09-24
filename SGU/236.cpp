#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	
	int u[M],v[M],C[M],T[M];
	for(int i = 0;i<M;++i){
		scanf("%d %d %d %d",&u[i],&v[i],&C[i],&T[i]);
		--u[i]; --v[i];
	}
	
	double lo = 0, hi = 100,mi,d[N];
	
	for(int i = 0;i<50;++i){
		mi = (lo+hi)/2;
		
		d[0] = 0;
		for(int j = 1;j<N;++j) d[j] = 1e9;
		
		bool found;
		
		for(int it = 1;it<=N;++it){
			found = false;
			for(int j = 0;j<M;++j){
				if(d[u[j]]+(mi*T[j]-C[j])<d[v[j]]){
					d[v[j]] = d[u[j]]+(mi*T[j]-C[j]);
					found = true;
				}
			}
		}
		
		if(found) lo = mi;
		else hi = mi;
	}
	
	if(lo<1e-8) printf("0\n");
	else{
		bool adj[N][N];
		double dist0[N][N],dist[N][N];
		memset(adj,false,sizeof(adj));
		
		for(int i = 0;i<N;++i)
			for(int j = 0;j<N;++j)
				dist0[i][j] = dist[i][j] = 1e9;
		
		for(int i = 0;i<M;++i){
			adj[u[i]][v[i]] = true;
			dist0[u[i]][v[i]] = dist[u[i]][v[i]] = lo*T[i]-C[i];
		}
		
		for(int k = 0;k<N;++k)
			for(int i = 0;i<N;++i)
				for(int j = 0;j<N;++j)
					if(dist[i][k]<1e9 && dist[k][j]<1e9)
						dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
		
		vector<int> P;
		int s = -1,cur;
		
		for(int i = 0;i<N;++i){
			if(dist[i][i]<1e-8){
				s = cur = i;
				break;
			}
		
		}
		
		if(s==-1){
			printf("0\n");
			return 0;
		}
		
		bool visited[N];
		memset(visited,false,sizeof(visited));
		visited[s] = true;
		P.push_back(s);
		
		while(true){
			int next = -1;
			
			for(int i = 0;i<N;++i){
				if(!visited[i] && adj[cur][i] && dist[i][s]<1e9 && dist[s][cur]+dist0[cur][i]+dist[i][s]<1e-8){
					visited[i] = true;
					P.push_back(i);
					next = i;
					break;
				}
			}
			
			if(next==-1) break;
			cur = next;
		}
		
		int sz = P.size();
		printf("%d\n",sz);
		
		for(int i = 0;i<sz;++i){
			printf("%d",1+P[i]);
			if(i+1==sz) printf("\n");
			else printf(" ");
		}
	}
	
	return 0;
}
