#include <cstdio>

using namespace std;

int main(){
	int T,N;
	scanf("%d",&T);
	
	while(T--){
		scanf("%d",&N);
		
		int ans = -1;
		
		for(int i = 1;i<=N;++i){
			if(N%i==0){
				int N2 = N/i;
				for(int j = i;j<=N2;++j){
					if(N2%j==0){
						int k = N2/j;
						int aux = 2*(i*j+j*k+k*i);
						if(ans==-1 || aux<ans) ans = aux;
					}
				}
			}
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
