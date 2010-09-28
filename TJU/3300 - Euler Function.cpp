#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

#define N 3000000

int factors[N+1];
long long phi[N+1],ans[N+1];

int main(){
	fill(factors,factors+N+1,0);
	ans[1] = phi[1] = 1;
	
	for(int i=2;i<=N;i++){
		if(factors[i]==0){
			factors[i] = i;
			phi[i] = i-1;
			
			if(i<=sqrt(N)) for(int j=i*i;j<=N;j+=i) factors[j] = i;
		}else{
			int aux = i,exp = 0;
			
			while(aux%factors[i]==0){
				aux /= factors[i];
				++exp;
			}
			
			phi[i] = 1;
			
			for(int j=0;j<exp;++j) phi[i] *= factors[i];
			phi[i] -= phi[i]/factors[i];
			phi[i] *= phi[aux];
		}
		
		ans[i] = ans[i-1]+phi[i];
	}
	
	int a,b;
	
	while(scanf("%d %d",&a,&b)==2){
		printf("%lld\n",ans[b]-ans[a-1]);
	}
	
	return 0;
}
