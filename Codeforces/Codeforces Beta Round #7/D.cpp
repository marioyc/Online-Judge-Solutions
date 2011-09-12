#include <iostream>
#include <cstring>

using namespace std;

char s[5000001],srev[5000001];
int f[5000000],dp[5000000];

void prefix_kmp(char *P){
	int L = strlen(P),k,p = 0;
	
	for(int i = 1;i < L;++i){
		if(i < p && f[i - k] < p-i) f[i] = f[i - k];
		else{
			int j = max(0,p-i);
			
			while(i+j < L && P[i + j] == P[j]) ++j;
			
			f[i] = j;
			p = i + j;
			k = i;
		}
	}
}

int lcp[5000000];

void LCP(char *P, char *T){
	int LP = strlen(P),LT = strlen(T),k,p = 0;
	
	for(int i = 0;i < LT;++i){
		if(i < p && f[i - k] < p-i) lcp[i] = f[i - k];
		else{
			int j = max(0,p-i);
			
			while(i+j < LT && T[i + j] == P[j]) ++j;
			
			lcp[i] = j;
			p = i + j;
			k = i;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	
	cin >> s;
	
	int L = strlen(s);
	
	for(int i = 0;i < L;++i)
		srev[i] = s[L - 1 -i];
	
	srev[L] = 0;
	
	prefix_kmp(s);
	LCP(s,srev);
	
	long long ans = 1;
	dp[0] = 1;
	
	for(int i = 1;i < L;++i){
		dp[i] = 0;
		
		if(lcp[L - 1 - i] == i + 1)
			dp[i] = 1 + dp[(i + 1) / 2 - 1];
		
		ans += dp[i];
	}
	
	cout << ans << endl;
	
	return 0;
}
