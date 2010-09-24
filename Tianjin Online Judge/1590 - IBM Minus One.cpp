#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int T,L;
	char s[51];
	
	scanf("%d",&T);
	
	for(int tc=1;tc<=T;++tc){
		scanf("%s",s);
		L = strlen(s);
		
		printf("String #%d\n",tc);
		for(int i=0;i<L;++i) printf("%c",'A'+(s[i]-'A'+1)%26);
		printf("\n\n");
	}
	
	return 0;
}
