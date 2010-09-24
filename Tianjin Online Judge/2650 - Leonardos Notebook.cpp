#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int T;
	char s[27];
	
	scanf("%d",&T);
	
	bool used[26],valid;
	int p[26],cycle[26],cont[27],sz,pos;
	
	for(int tc=1;tc<=T;++tc){
		scanf("%s",s);
		
		for(int i=0;i<26;++i) p[i] = s[i]-'A';
		memset(used,false,sizeof(used));
		memset(cont,0,sizeof(cont));
		
		for(int i=0;i<26;++i){
			if(used[i]) continue;
			used[i] = true;
			
			sz = 0; cycle[sz++] = i;
			pos = p[i];
			
			while(pos!=i){
				cycle[sz++] = pos;
				used[pos] = true;
				pos = p[pos];
			}
			
			++cont[sz];
		}
		
		valid = true;
		
		for(int i=2;i<=26;i+=2)
		    if(cont[i]%2==1)
		        valid = false;
		
		printf("%s\n",valid? "Yes":"No");
	}
	
	return 0;
}
