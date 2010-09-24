#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int N,a[2000];
	long long dp[2][2000];
	
	scanf("%d",&N);
	for(int i = 0;i<N;++i) scanf("%d",&a[i]);
	
	for(int i = 0;i<N;++i) dp[1][i] = N*a[i];
	
	for(int i = 2;i<=N;++i) for(int j = 0;j+i-1<N;++j)
		dp[i&1][j] = max((N+1-i)*a[j]+dp[(i&1)^1][j+1],(N+1-i)*a[j+i-1]+dp[(i&1)^1][j]);
	
	printf("%lld\n",dp[N&1][0]);
	
	return 0;
}
