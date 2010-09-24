#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;
inline int lcm(int a, int b){
	return a/__gcd(a,b)*b;
}

int main(){
	int n,t,h[50],H,ans1,ans2;
	
	while(true){
		scanf("%d %d",&n,&t);
		if(n==0 && t==0) break;
		
		for(int i = 0;i<n;++i) scanf("%d",&h[i]);
		
		for(int i = 0;i<t;++i){
			scanf("%d",&H);
			
			ans1 = 0; ans2 = INT_MAX;
			
			for(int i1 = 0;i1<n;++i1){
				for(int i2 = i1+1;i2<n;++i2){
					for(int i3 = i2+1;i3<n;++i3){
						for(int i4 = i3+1;i4<n;++i4){
							int m = lcm(lcm(h[i1],h[i2]),lcm(h[i3],h[i4]));
							int x = (H/m)*m;
							if(x>ans1) ans1 = x;
							if(x!=H) x += m;
							if(x<ans2) ans2 = x;
						}
					}
				}
			}
			
			printf("%d %d\n",ans1,ans2);
		}
	}
	
	return 0;
}
