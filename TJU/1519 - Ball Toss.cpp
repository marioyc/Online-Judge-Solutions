#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n,k,cont,prev,last,next,tosses;
	bool L[30],done[30];
	char c;
	
	while(1){
		scanf("%d",&n);
		if(n<1) break;
		
		scanf("%d",&k);
		k--;
		
		for(int i=0;i<n;i++){
			scanf(" %c",&c);
			if(c=='L') L[i]=true;
			else L[i]=false;
		}
		
		
		
		fill(done,done+n,false);
		done[k]=true;
		
		cont=tosses=1;
		prev=0;
		last=k;
		
		while(cont<n){
			if(L[last]){
				next=((prev-1)%n+n)%n;
				if(next==last) next=((last-1)%n+n)%n;
			}else{
				next=(prev+1)%n;
				if(next==last) next=(last+1)%n;
			}
			
			if(L[last]) L[last]=false;
			else L[last]=true;
			
			if(!done[next]){
				cont++;
				done[next]=true;
			}
			
			prev=last;
			last=next;
			
			tosses++;
		}
		
		printf("Classmate %d got the ball last after %d tosses.\n",last+1,tosses);
	}	
	
	return 0;
}
