#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int T,M,N,a[99],dp[98*99+1];
	
	scanf("%d",&T);
	
	while(T--){
		scanf("%d %d",&M,&N);
		
		for(int i = 0;i<M;++i)
			scanf("%d",&a[i]);
		
		sort(a,a+M);
		
		int ans = -1;
		
		if(N%a[M-1]==0) ans = N/a[M-1];
		else{
			int N2 = min(N,((a[M-1]-1)*a[M-1]));
			dp[0] = 0;
			
			for(int i = 1;i<=N2;++i){
				dp[i] = -1;
				
				for(int j = M-1;j>=0;--j)
					if(i>=a[j] && dp[i-a[j]]!=-1 && (dp[i]==-1 || 1+dp[i-a[j]]<dp[i]))
						dp[i] = 1+dp[i-a[j]];
				
				if(dp[i]!=-1){
					if(i==N && (ans==-1 || dp[i]<ans))
						ans = dp[i];
					else if((N-i)%a[M-1]==0 && (ans==-1 || dp[i]+(N-i)/a[M-1]<ans))
						ans = dp[i]+(N-i)/a[M-1];
				}
			}
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
