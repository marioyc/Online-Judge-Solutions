#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int k,m,n,moves[100],grundy[10001],sz,nim_val;
	bool is[101];
	
	grundy[0]=0;
	
	while(1){
		scanf("%d",&k);
		if(k==0) break;
		
		for(int i=0;i<k;i++) scanf("%d",&moves[i]);
		
		for(int i=1,x;i<=10000;i++){
			fill(is,is+101,false);
			
			for(int j=0;j<k;j++) if(i>=moves[j]) is[grundy[i-moves[j]]]=true;
			
			x=0;
			while(is[x]) x++;
			grundy[i]=x;
		}
		
		scanf("%d",&m);
		
		for(int i=0;i<m;i++){
			scanf("%d",&n);
			
			nim_val=0;
			
			for(int j=0;j<n;j++){
				scanf("%d",&sz);
				nim_val^=grundy[sz];
			}
			
			if(nim_val) printf("W");
			else printf("L");
		}
		
		printf("\n");
	}
	
	return 0;
}
