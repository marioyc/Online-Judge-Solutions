#include <cstdio>

using namespace std;

int main(){
	int T,E,F,N,p[500],w[500],dp[10000];
	scanf("%d",&T);
	
	for(int tc = 1;tc<=T;++tc){
		scanf("%d %d %d",&E,&F,&N);
		
		for(int i = 0;i<N;++i) scanf("%d %d",&p[i],&w[i]);
		
		F -= E;
		dp[0] = 0;
		
		for(int i = 1;i<=F;++i){
			dp[i] = -1;
			
			for(int j = 0;j<N;++j)
				if(i>=w[j] && dp[i-w[j]]!=-1 && (dp[i]==-1 || p[j]+dp[i-w[j]]<=dp[i]))
					dp[i] = p[j]+dp[i-w[j]];
		}
		
		if(dp[F]==-1) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[F]);
	}	
	
	return 0;
}
