#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int N,M,x,y,s,e;
	int S[10000],E[10000];
	
	while(true){
		scanf("%d %d",&N,&M);
		if(N==0) break;
		
		for(int i=0;i<N;++i){
			scanf("%d %d %d %d",&x,&y,&S[i],&E[i]);
			E[i] = S[i]+E[i];
		}
		
		for(int i=0;i<M;++i){
			int ans = 0;
			scanf("%d %d",&s,&e);
			e = s+e;
			
			for(int j=0;j<N;++j){
				int s2 = max(s,S[j]), e2 = min(e,E[j]);
				if(e2-s2>=1) ++ans;
			}
			
			printf("%d\n",ans);
		}
	}
	
	return 0;
}
