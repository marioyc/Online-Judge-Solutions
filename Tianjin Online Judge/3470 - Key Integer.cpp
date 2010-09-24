#include <cstdio>

using namespace std;

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int T,N,pos;
	
	scanf("%d",&T);
	
	for(int tc=1;tc<=T;tc++){
		scanf("%d",&N);
		
		for(int i=30;i>=0;i--){
			if(N & (1<<i)){
				pos=i;
				break;
			}
		}
		
		if(N==(1<<pos)) printf("%d\n",pos);
		else printf("%d\n",pos+1);
	}
	
	return 0;
}
