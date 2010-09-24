#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int T,N,M,b1,b2;
	
	scanf("%d",&T);
	
	for(int tc=1;tc<=T;tc++){
		scanf("%d %d %d %d",&N,&M,&b1,&b2);
		
		printf("%d\n",__gcd(N-b1,M-b2));
	}
	
	return 0;
}
