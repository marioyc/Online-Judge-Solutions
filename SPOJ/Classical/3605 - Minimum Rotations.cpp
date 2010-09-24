#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	freopen("password.in","r",stdin);
	freopen("password.out","w",stdout);	
	
	char s[100001];
	scanf("%s",s);	
	
	int N = strlen(s),ans = 0,p = 1,l = 0;
	
	while(p<N && ans+l+1<N){
		if(s[ans+l]==s[(p+l)%N]) ++l;
		else if(s[ans+l]<s[(p+l)%N]){
			p = p+l+1;
			l = 0;
		}else{
			ans = max(ans+l+1,p);
			p = ans+1;
			l = 0;
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}
