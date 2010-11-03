#include <cstdio>

using namespace std;

int rev(int n){
	int aux = 0;
	
	while(n!=0){
		aux = aux*10+n%10;
		n /= 10;
	}
	
	return aux;
}

int main(){
	int n,x,y;
	scanf("%d",&n);
	
	for(int tc=1;tc<=n;++tc){
		scanf("%d %d",&x,&y);
		
		x = rev(x);
		y = rev(y);
		
		printf("%d\n\n",x+y);
	}
	
	return 0;
}
