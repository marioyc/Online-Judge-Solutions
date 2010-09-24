#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int T,n,m;
	scanf("%d",&T);
	
	bool possible,found;
	char s1[101],s2[101];
	
	for(int tc=1;tc<=T;tc++){
		scanf("%s %s",s2,s1);
		
		n=strlen(s1); m=strlen(s2);
		possible=true;
		
		for(int i=0,j=0;i<n && possible;i++){
			found=false;
			
			while(j<m){
				if(s2[j]==s1[i]){
					found=true;
					j++;
					break;
				}
				j++;
			}
			
			if(!found) possible=false;
		}
		
		if(possible) printf("yes\n");
		else printf("no\n");
	}
		
	return 0;
}
