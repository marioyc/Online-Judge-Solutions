#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
	int T,N,in[26],out[26];
	char word[1001];
	bool M[26][26];
	
	scanf("%d",&T);
	
	while(T--){
		scanf("%d",&N);
		
		memset(M,false,sizeof(M));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		
		for(int i = 0;i<N;++i){
			scanf("%s",word);
			int L = strlen(word);
			int c1 = word[0]-'a';
			int c2 = word[L-1]-'a';
			M[c1][c2] = M[c2][c1] = true;
			++in[c2]; ++out[c1];
		}
		
		for(int k = 0;k<26;++k)
			for(int i = 0;i<26;++i)
				for(int j = 0;j<26;++j)
					M[i][j] |= (M[i][k] & M[k][j]);
		
		bool valid = true;
		
		for(int i = 0;i<26;++i)
			for(int j = 0;j<26;++j)
				if(i!=j && in[i]+out[i]>0 && in[j]+out[j]>0 && !M[i][j])
					valid = false;
		
		int cont1 = 0, cont2 = 0;
		
		for(int i = 0;i<26;++i)
			if(in[i]==out[i]) ++cont1;
			else if(out[i]==in[i]+1) ++cont2;
		
		if(!(cont1==26 || (cont1==24 && cont2==1))) valid = false;
		
		if(valid) printf("Ordering is possible.");
		else printf("The door cannot be opened.");
		printf("\n");
	}
	
	return 0;
}
