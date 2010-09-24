#include <cstdio>
#include <algorithm>

using namespace std;

int H[500][500],X[1000][500],sz[1000];

int main(){
	int N,M,Q,L,U;
	int lo,hi,mi;
	
	while(true){
		scanf("%d %d",&N,&M);
		if(N==0) break;
		
		for(int i = 0;i<N;++i)
			for(int j = 0;j<M;++j)
				scanf("%d",&H[i][j]);
		
		// Empezando en (i,0)
		for(int i = 0;i<N;++i){
			for(int j = 0;i+j<N && j<M;++j)
				X[i][j] = H[i+j][j];
			
			sz[i] = min(N-i,M);
		}
		
		// Empezando en (0,i)
		for(int i = 1;i<M;++i){
			for(int j = 0;i+j<M && j<N;++j)
				X[N+i-1][j] = H[j][i+j];
			
			sz[N+i-1] = min(M-i,N);
		}
		
		scanf("%d",&Q);
		
		for(int q = 0;q<Q;++q){
			scanf("%d %d",&L,&U);
			
			int ans = 0,s,e;
			
			for(int i = N+M-2;i>=0;--i){
				if(X[i][0]>U || X[i][sz[i]-1]<L) continue;
				
				lo = 0; hi = sz[i]-1;
				
				while(lo!=hi){
					mi = (lo+hi)>>1;
					
					if(X[i][mi]>=L) hi = mi;
					else lo = mi+1;
				}
				
				s = lo;
				
				lo = 0; hi = sz[i]-1;
				
				while(lo!=hi){
					mi = (lo+hi+1)>>1;
					
					if(X[i][mi]<=U) lo = mi;
					else hi = mi-1;
				}
				
				e = lo;
				
				if(e-s+1>ans) ans = e-s+1;
			}
			
			printf("%d\n",ans);
		}
		
		puts("-");
	}
	
	return 0;
}

