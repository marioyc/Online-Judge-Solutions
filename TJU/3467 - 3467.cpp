#include <cstdio>

using namespace std;

int main(){
	int T,N,ans;
	
	scanf("%d",&T);
	
	for(int tc=1;tc<=T;tc++){
		scanf("%d",&N);
		
		ans=0;
		
		while(N!=0){
			ans+=N%10;
			N/=10;
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
