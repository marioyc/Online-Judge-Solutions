#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

void get_prev(int prev, int cur, vector<int> &L){
	if(cur==0) L.push_back(prev);
	else{
		for(int i = 0;i<4;++i){
			if(cur & (1<<i)){
				bool b1 = (prev & (1<<i));
				bool b2 = (i+1<4 && (cur & (1<<(i+1))));
				
				if(b1) get_prev(prev ^ (1<<i),cur ^ (1<<i),L);
				if(b2) get_prev(prev,cur ^ ((1<<i) | (1<<(i+1))),L);
				
				break;
			}
		}
	}
}

#define MAX_W 25

int main(){
	int T,W,dp[MAX_W][(1<<4)];
	vector<int> prev[(1<<4)];
	
	for(int mask = 0;mask<(1<<4);++mask)
		get_prev((1<<4)-1,mask,prev[mask]);
	
	memset(dp,0,sizeof(dp));
	dp[0][0] = dp[0][3] = dp[0][6] = dp[0][12] = dp[0][15] = 1;
	
	for(int i = 1;i<MAX_W;++i){
		for(int mask = 0;mask<(1<<4);++mask){
			for(int j = prev[mask].size()-1;j>=0;--j)
				dp[i][mask] += dp[i-1][prev[mask][j]];
		}
	}
	
	scanf("%d",&T);
	
	for(int tc = 1;tc<=T;++tc){
		scanf("%d",&W);
		printf("%d %d\n",tc,dp[W-1][(1<<4)-1]);
	}
	
	return 0;
}
