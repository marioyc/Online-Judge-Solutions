#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int R,C,ans;
	char s[1001];
	int count1[1000],count2[1001];
	
	while(scanf("%d %d",&R,&C)==2){
		ans=0;
		fill(count1,count1+C,0);
		
		for(int i=0;i<R;i++){
			scanf("%s",s);
			
			fill(count2,count2+i+2,0);
			
			for(int j=0;j<C;j++){
				count1[j]=(s[j]=='1'? count1[j]+1:0);
				count2[count1[j]]++;
			}
			
			for(int j=i;j>0;j--) count2[j]+=count2[j+1];
			
			for(int j=i+1;j>0;j--) ans=max(ans,j*count2[j]);
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
