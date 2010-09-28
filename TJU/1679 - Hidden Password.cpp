#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
	int T,L;
	char s[100001];
	
	scanf("%d",&T);
	
	while(T--){
		scanf("%d %s",&L,s);	
	
		int ans = 0,p = 1,l = 0;
	
		while(p<L && ans+l+1<L){
			if(s[ans+l]==s[(p+l)%L]) ++l;
			else if(s[ans+l]<s[(p+l)%L]){
				p = p+l+1;
				l = 0;
			}else{
				ans = max(ans+l+1,p);
				p = ans+1;
				l = 0;
			}
		}
	
		printf("%d\n",ans);
	}
	
	return 0;
}
