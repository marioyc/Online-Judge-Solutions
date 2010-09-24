#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n,N,a,b,c,x[90],y[90],z[90],dp[90];
	
	while(true){
		scanf("%d",&n);
		if(n==0) break;
		
		N = 3*n;
		
		for(int i = 0;i<n;++i){
			scanf("%d %d %d",&a,&b,&c);
			x[3*i] = a; y[3*i] = b; z[3*i] = c;
			x[3*i+1] = b; y[3*i+1] = c; z[3*i+1] = a;
			x[3*i+2] = c; y[3*i+2] = a; z[3*i+2] = b;
		}
		
		for(int i = 0;i<N;++i) for(int j = i+1;j<N;++j){
			if((x[j]<x[i] && y[j]<y[i]) || (y[j]<x[i] && x[j]<y[i])){
				swap(x[i],x[j]);
				swap(y[i],y[j]);
				swap(z[i],z[j]);
			}
		}
		
		int ans = -1;
		
		for(int i = 0;i<N;++i){
			dp[i] = z[i];
			
			for(int j = 0;j<i;++j)
				if((x[j]<x[i] && y[j]<y[i]) || (y[j]<x[i] && x[j]<y[i]))
					dp[i] = max(dp[i],dp[j]+z[i]);
			
			ans = max(ans,dp[i]);
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
