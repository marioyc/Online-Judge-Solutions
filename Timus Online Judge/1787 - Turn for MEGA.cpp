#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int k,n;
	
	scanf("%d %d",&k,&n);
	
	int total = 0,aux;
	
	for(int i = 0;i < n;++i){
		scanf("%d",&aux);
		total += aux;
		total = max(0,total - k);
	}
	
	printf("%d\n",total);
	
	return 0;
}
