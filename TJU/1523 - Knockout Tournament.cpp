#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	bool start=true;
	int N,n,m,L[8][256],Q,x,best[256],h[256],worst[256];
	
	while(1){
		scanf("%d",&n);
		if(n<1) break;
		
		N=(1<<n);
		
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<(1<<i);j++){
				scanf("%d",&L[i][j]);
				L[i][j]--;
			}
		}
		
		m=(1<<(n-1));
		
		for(int i=0;i<m;i++){
			L[n][2*i]=L[n-1][i];
			L[n][2*i+1]=L[n-1][i] ^ 1;
		}
		
		fill(best,best+N,-1);
		best[L[0][0]]=1;
		
		fill(h,h+N,-1);
		h[L[0][0]]=n;
		
		for(int i=1;i<=n;i++){
			for(int j=0;j<(1<<i);j+=2){
				if(best[L[i][j]]!=-1) best[L[i][j+1]]=1+best[L[i][j]];
				else best[L[i][j]]=1+best[L[i][j+1]];
				
				if(h[L[i][j]]!=-1) h[L[i][j+1]]=n-i;
				else h[L[i][j]]=n-i;
			}
		}
		
		fill(worst,worst+N,N);
		
		for(int i=0;i<n;i++){
			for(int j=0;j<(1<<i);j++){
				if(L[i+1][2*j]==L[i][j]) worst[L[i][j]]-=(1<<h[L[i+1][2*j+1]]);
				else worst[L[i][j]]-=(1<<h[L[i+1][2*j]]);
			}
		}
		
		if(!start) printf("\n");
		start=false;
		
		scanf("%d",&Q);
		
		for(int q=0;q<Q;q++){
			scanf("%d",&x);
			
			printf("Player %d can be ranked as high as %d or as low as %d.\n",x,best[x-1],worst[x-1]);
		}
	}
	
	return 0;
}
