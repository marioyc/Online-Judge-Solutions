#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_L 400000

char P[MAX_L+1];
int f[MAX_L];

void prefixFunction(){
	int n = strlen(P), k = 0;
	f[0] = 0;
	
	for(int i = 1;i<n;++i){
		while(k>0 && P[k]!=P[i]) k = f[k-1];
		if(P[k]==P[i]) ++k;
		f[i] = k;
	}
}

int main(){
	int ans[MAX_L],sz;	
	
	while(scanf("%s",P)==1){
		prefixFunction();
		
		int L = strlen(P);
		sz = 0;
		
		while(L!=0){
			ans[sz] = L;
			++sz;
			L = f[L-1];
		}
		
		printf("%d",ans[sz-1]);
		for(int i = sz-2;i>=0;--i) printf(" %d",ans[i]);
		printf("\n");
	}
	
	return 0;
}
