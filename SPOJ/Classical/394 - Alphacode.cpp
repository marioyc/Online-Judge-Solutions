#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int L;
	char d[5001];
	long long dp[5001];
	
	while(true){
		scanf("%s",d);
		if(d[0]=='0') break;
		
		L = strlen(d);
		
		dp[0] = dp[1] = 1;
		
		for(int i = 2;i<=L;++i){
			dp[i] = 0;
			
			char c1 = d[i-2]-'0', c2 = d[i-1]-'0';
			
			if(c1==1 || (c1==2 && c2<=6)) dp[i] += dp[i-2];
			if(c2!=0) dp[i] += dp[i-1];
		}
		
		printf("%lld\n",dp[L]);
	}
	
	return 0;
}
