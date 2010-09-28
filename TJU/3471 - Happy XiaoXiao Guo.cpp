#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	bool win[10001];
	memset(win,false,sizeof(win));
		
	for(int i=1;i<=10000;i++){
		if(i>=1 && !win[i-1]) win[i]=true;
		if(i>=2 && !win[i-2]) win[i]=true;
		if(i>=4 && !win[i-4]) win[i]=true;
		if(i>=5 && !win[i-5]) win[i]=true;
	}
	
	int N;
	
	while(1){
		scanf("%d",&N);
		if(N==0) break;
		
		if(win[N]) printf("Happy\n");
		else printf("Unhappy\n");
	}
	
	return 0;
}
