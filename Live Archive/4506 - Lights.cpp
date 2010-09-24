#include <cstdio>

using namespace std;

const int MOD = 10567201;

long long pow(int a, int b){
	if(b==0) return 1;
	long long aux = pow(a,b/2);
	
	long long ans = (aux*aux)%MOD;
	if(b&1) ans = (ans*a)%MOD;
	
	return ans;
}

long long inv[1001];

long long comb(int m, int n){
	if(m<n) return 0;
	
	long long ans = 1;
	for(int i = 1;i<=n;++i) ans = (ans*(m-i+1))%MOD;
	for(int i = 1;i<=n;++i) ans = (ans*inv[i])%MOD;
	
	return ans;
}

int main(){
	int n,m,v;
	long long pow2[1001],dp[1001];
	
	pow2[0] = 1;
	
	for(int i = 1;i<=1000;++i){
		pow2[i] = (2*pow2[i-1])%MOD;
		inv[i] = pow(i,MOD-2);
	}
	
	while(true){
		scanf("%d %d %d",&n,&m,&v);
		if(n==0) break;
		
		dp[0] = (v==0? 1:0); dp[1] = 1;
		
		for(int i = (m&1)+2;i<=m;i += 2){
			dp[i] = ((comb(pow2[n],i-1)-(pow2[n]-i+2)*dp[i-2])%MOD+MOD)%MOD;
			dp[i] = (dp[i]*inv[i])%MOD;
		}
		
		printf("%lld\n",dp[m]);
	}
	
	return 0;
}
