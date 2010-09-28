#include <cstdio>
#include <algorithm>

using namespace std;

struct car{
	int id,s,c;
	
	car(){
	}
	
	bool operator < (const car &X) const{
		return (s>X.s || (s==X.s && c>X.c));
	}
}a[1000];

int main(){
	int T,N,k;
	
	scanf("%d",&T);
	
	for(int tc=1;tc<=T;tc++){
		scanf("%d %d",&N,&k);
		
		for(int i=0;i<N;i++) scanf("%d %d %d",&a[i].id,&a[i].s,&a[i].c);
		
		sort(a,a+N);
		
		printf("%d\n",a[k-1].id);
	}
	
	return 0;
}
