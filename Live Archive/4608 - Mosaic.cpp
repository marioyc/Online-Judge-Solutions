#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MOD 1000000
int N;

void get_prev(int prev, int cur, vector<int> &L){
	if(cur==0) L.push_back(prev);
	else{
		for(int i = 0;i<N;++i){
			if(cur & (1<<i)){
				bool b1 = (i>0 && (prev & (1<<(i-1))));
				bool b2 = (prev & (1<<i));
				bool b3 = (i+1<N && (prev & (1<<(i+1))));
				bool b4 = (i+1<N && (cur & (1<<(i+1))));
				
				if(b2 && b3 && b4) get_prev(prev ^ ((1<<i) | (1<<(i+1))),cur ^ ((1<<i) | (1<<(i+1))),L);
				if(b1 && b2) get_prev(prev ^ ((1<<i) | (1<<(i-1))),cur ^ (1<<i),L);
				if(b2 && b3) get_prev(prev ^ ((1<<i) | (1<<(i+1))),cur ^ (1<<i),L);
				if(b4 && b2) get_prev(prev ^ (1<<i),cur ^ ((1<<i) | (1<<(i+1))),L);
				if(b4 && b3) get_prev(prev ^ (1<<(i+1)),cur ^ ((1<<i) | (1<<(i+1))),L);
				
				break;
			}
		}
	}
}

int main(){
	int M,dp[500][(1<<10)];
	vector<int> prev[(1<<10)];
	
	while(true){
		scanf("%d %d",&N,&M);
		if(N==0 || M==0) break;
		
		for(int mask = 0;mask<(1<<N);++mask){
			prev[mask].clear();
			get_prev((1<<N)-1,mask,prev[mask]);
		}
		
		memset(dp,0,sizeof(dp));
		
		dp[0][0] = 1;
		
		for(int i = 1;i<M;++i){
			for(int mask = 0;mask<(1<<N);++mask){
				for(int j = prev[mask].size()-1;j>=0;--j)
					dp[i][mask] = (dp[i][mask]+dp[i-1][prev[mask][j]])%MOD;
			}
		}
		
		printf("%d\n",dp[M-1][(1<<N)-1]);
	}
	
	return 0;
}
