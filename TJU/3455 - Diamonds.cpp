#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int T,s1,s2,ans;
	int a[10];
	
	scanf("%d",&T);
	
	for(int tc=1;tc<=T;tc++){
		for(int i=0;i<10;i++) scanf("%d",&a[i]);
		
		ans=-1;
		
		for(int mask=0;mask<(1<<9);mask++){
			s1=s2=0;
			
			for(int i=0;i<10;i++){
				if(mask & (1<<i)) s1+=a[i];
				else s2+=a[i];
			}
			
			ans=max(ans,min(s1,s2));
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
