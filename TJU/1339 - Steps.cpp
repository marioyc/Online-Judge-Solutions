#include <cstdio>

using namespace std;

int main(){
	int T,x,y;
	scanf("%d",&T);
	
	// f(n) = máximo número que se puede lograr con n pasos
	// f(0) = 0, f(1) = 1
	// f(2n) = f(2n-1)+n = n(n+1)
	// f(2n-1) = f(2n-2)+n = n^2
	
	while(T--){
		scanf("%d %d",&x,&y);
		x = y-x;
		
		int lo = 0,hi = (1<<16);
		long long mi;
		
		while(lo<hi){
			mi = (lo+hi)>>1;
			
			long long f = (mi%2==0? mi/2*(mi/2+1) : (mi/2+1)*(mi/2+1));
			
			if(x<=f) hi = mi;
			else lo = mi+1;
		}
		
		printf("%d\n",lo);
	}	
	
	return 0;
}
