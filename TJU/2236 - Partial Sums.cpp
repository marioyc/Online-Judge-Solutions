#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n,L,U,sum,total,ans,max,a[100000],cont[5200];
	
	while(scanf("%d %d %d",&n,&L,&U)==3){
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		
		ans=max=-1;
		
		for(int i=L;i<=U;i++){
			fill(cont+1,cont+i,0);
			cont[0]=1;
			
			sum=total=0;
			
			for(int j=0;j<n;j++){
				sum=(sum+a[j])%i;
				total+=cont[sum];
				cont[sum]++;
			}
			
			if(max<total){
				max=total;
				ans=i;
			}
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
