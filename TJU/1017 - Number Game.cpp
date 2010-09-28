#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int marked[(1<<19)],win[(1<<19)];

int mark(int mask){
	if(marked[mask]!=-1) return marked[mask];
	
	int mask2=0;
	
	for(int i=0;i<19;i++){
		if((mask & (1<<i))==0) continue;
		
		for(int j=1;(i+2)*j<=20;j++) mask2|=(1<<((i+2)*j-2));
	}
	
	for(int i=0;i<19;i++){
		if((mask & (1<<i))==0) continue;
		for(int j=i+1;j<19;j++){
			if((mask & (1<<j))==0) continue;
			for(int a=1;(i+2)*a<=20;a++){
				for(int b=1;(i+2)*a+(j+2)*b<=20;b++){
					mask2|=(1<<((i+2)*a+(j+2)*b-2));
				}
			}
		}
	}
	
	marked[mask]=mask2;
	return mask2;
}

int solve(int mask){
	if(win[mask]!=-1) return win[mask];
	
	int ans=0;
	
	int mask2=mark(mask);
	
	for(int i=0;i<19;i++){
		if((mask2 & (1<<i))==0 && solve(mask ^ (1<<i))==0){
			ans=1;
			break;
		}
	}
	
	win[mask]=ans;
	return ans;
}

int main(){
	memset(marked,-1,sizeof(marked));
	memset(win,-1,sizeof(win));
	
	int T,n,x,mask,mask2;
	
	scanf("%d",&T);
	
	for(int tc=1;tc<=T;tc++){
		scanf("%d",&n);
		
		mask=(1<<19)-1;
		
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			mask^=(1<<(x-2));
		}
		
		printf("Scenario #%d:\n",tc);
		
		if(solve(mask)==0) printf("There is no winning move.\n");
		else{
			printf("The winning moves are:");
			
			mask2=mark(mask);
			
			for(int i=0;i<19;i++)
				if((mask2 & (1<<i))==0 && solve(mask ^ (1<<i))==0)
					printf(" %d",i+2);
			
			printf(".\n");
		}
		
		printf("\n");
	}
	
	return 0;
}
