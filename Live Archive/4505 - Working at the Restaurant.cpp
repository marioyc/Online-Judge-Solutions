#include <cstdio>

using namespace std;

int main(){
	int N,x;
	char com[5];
	bool first = true;
	
	while(true){
		scanf("%d",&N);
		if(N==0) break;
		
		int sz1 = 0, sz2 = 0;
		
		if(!first) printf("\n");
		first = false;
		
		for(int i=0;i<N;++i){
			scanf("%s %d",com,&x);
			
			if(com[0]=='D'){
				printf("DROP 2 %d\n",x);
				sz2 += x;
			}else{
				if(sz1>=x){
					printf("TAKE 1 %d\n",x);
					sz1 -= x;
				}else{
					if(sz1>0) printf("TAKE 1 %d\n",sz1);
					
					printf("MOVE 2->1 %d\n",sz2);
					
					printf("TAKE 1 %d\n",x-sz1);
					sz1 = sz1+sz2-x;
					sz2 = 0;
				}
			}
		}
	}	
	
	return 0;
}
