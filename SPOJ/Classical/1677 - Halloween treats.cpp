#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int c,n,a[100000],ind[100000],S;
	
	while(true){
		scanf("%d %d",&c,&n);
		if(c==0) break;
		
		for(int i=0;i<n;++i) scanf("%d",&a[i]);
		
		memset(ind,-1,sizeof(ind));
		ind[0] = 0;
		S = 0;
		
		for(int i=0;i<n;++i){
			S = (S+a[i])%c;
			
			if(ind[S]!=-1){
				printf("%d",ind[S]+1);
				for(int j=ind[S]+2;j<=i+1;++j) printf(" %d",j);
				printf("\n");
				break;
			}else ind[S] = i+1;
		}
	}
	
	return 0;
}
