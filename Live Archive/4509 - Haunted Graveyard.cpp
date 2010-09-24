#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define INF 10000000

int V,dist[900],u[3600],v[3600],w[3600],E;
bool reached[900];

void solve(){
	for(int i=0;i<V;++i) dist[i] = INF, reached[i] = false;
	
	dist[0] = 0; reached[0] = true;
	
	for(int i=1;i<V;++i) for(int e=0;e<E;++e){
		if(dist[u[e]]+w[e]<dist[v[e]]){
			if(reached[u[e]]) reached[v[e]] = true;
			dist[v[e]] = dist[u[e]] + w[e];
		}
	}
	
	for(int e=0;e<E;++e){
		if(reached[u[e]] && dist[u[e]]+w[e]<dist[v[e]]){
			printf("Never\n");
			return;
		}
	}
	
	if(!reached[V-1]) printf("Impossible\n");
	else printf("%d\n",dist[V-1]);
}

int main(){
	int W,H,G,holes,r,c,r2,c2,t;
	bool grave[30][30],hole[30][30];
	int dr[] = {-1,1,0,0},dc[] = {0,0,-1,1};
	
	while(true){
		scanf("%d %d",&W,&H);
		if(W==0) break;
		
		memset(grave,false,sizeof(grave));
		memset(hole,false,sizeof(hole));
		
		scanf("%d",&G);
		
		for(int i=0;i<G;++i){
			scanf("%d %d",&r,&c);
			grave[r][c] = true;
		}
		
		scanf("%d",&holes);
		E = 0;
		
		for(int i=0;i<holes;++i){
			scanf("%d %d %d %d %d",&r,&c,&r2,&c2,&t);
			hole[r][c] = true;
			u[E] = r*H+c; v[E] = r2*H+c2; w[E] = t;
			++E;
		}
		
		for(r=0;r<W;++r) for(c=0;c<H;++c){
			if(grave[r][c] || hole[r][c] || (r==W-1 && c==H-1)) continue;
			int from = r*H+c;
			
			for(int k=0;k<4;++k){
				r2 = r+dr[k]; c2 = c+dc[k];
				
				if(r2>=0 && r2<W && c2>=0 && c2<H && !grave[r2][c2]){
					u[E] = from; v[E] = r2*H+c2; w[E] = 1;
					++E;
				}
			}
		}
		
		V = W*H;
		solve();
	}
	
	return 0;
}
