#include <cstdio>
#include <cstring>

using namespace std;

#define min(a,b) (a)<(b)? (a):(b)
#define max(a,b) (a)>(b)? (a):(b)

int main(){
	int n,mov,cont[26],ans,val1,val2;
	char s[1001];
	
	while(true){
		scanf("%s",s);
		if(s[0]=='*') break;
		
		n = strlen(s);
		
		memset(cont,0,sizeof(cont));
		mov = s[n-1]-'a';
		++cont[mov];
		
		for(int i = n-2;i>=0;--i){
			mov = s[i]-s[i+1];
			if(mov<0) mov += 26;
			++cont[mov];
		}
		
		val1 = val2 = 0;
		for(int i = 0;i<26;++i) val1 += i*cont[i];
		ans = val1;
		
		for(int i = n-1,pos = 25;i>=0;--i){
			while(cont[pos]==0) --pos;
			val1 -= pos; val2 += 26-pos;
			ans = min(ans,max(val1,val2));
			--cont[pos];
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
