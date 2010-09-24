#include <cstdio>

using std::scanf;
using std::printf;

int main(){
	int T,n,a[47],nim_val,tot;
	
	scanf("%d",&T);
	
	for(int tc=1;tc<=T;tc++){
		scanf("%d",&n);
		
		nim_val=tot=0;
		
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			nim_val^=a[i];
			tot+=a[i];
		}
		
		if(tot==n){
			if(n&1) printf("Brother\n");
			else printf("John\n");
		}else{
			if(nim_val) printf("John\n");
			else printf("Brother\n");
		}
	}
	
	return 0;
}
