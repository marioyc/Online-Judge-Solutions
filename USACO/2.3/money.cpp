/*
ID:zion_ba1
LANG:C++
TASK:money
*/

#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);	
	
	int V,N,a[25];
	scanf("%d %d",&V,&N);
	
	for(int i = 0;i<N;++i) scanf("%d",&a[i]);
	
	long long dp[N+1];
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	
	for(int i = 0;i<V;++i)
		for(int j = 0;j+a[i]<=N;++j)
			dp[j+a[i]] += dp[j];
	
	printf("%lld\n",dp[N]);
	
	return 0;
}
