#include <cstdio>
#include <cstring>

using namespace std;

int N,K,memo[(1<<12)][99];

int solve(int mask, int inv){
	if(inv<0) return 0;
	if(mask==(1<<N)-1){
		if(inv==K) return 1;
		return 0;
	}
	
	int &ret = memo[mask][inv];
	if(ret!=-1) return ret;
	
	ret = 0;
	
	for(int i = 0;i<N;++i){
		if(mask & (1<<i)) continue;
		
		int cont = 0;
		
		for(int j = i+1;j<N;++j)
			if(mask & (1<<j)) ++cont;
		
		ret += solve(mask | (1<<i),inv+cont);
	}
	
	return ret;
}

int main(){
	int T;
	scanf("%d",&T);
	
	for(int tc = 1;tc<=T;++tc){
		scanf("%d %d",&N,&K);
		memset(memo,-1,sizeof(memo));
		printf("%d\n",solve(0,0));
	}
	
	return 0;
}
