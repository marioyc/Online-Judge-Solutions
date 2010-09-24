#include <cstdio>
#include <cmath>

using namespace std;

long long pow(int a, int b, int mod){
	if(b==0) return 1;
	
	long long aux = pow(a,b/2,mod);
	aux = (aux*aux)%mod;
	if(b&1) aux = (aux*a)%mod;
	
	return aux;
}

int main(){
	int p,Q,n,r;
	long long ret;
	
	while(true){
		scanf("%d %d",&p,&Q);
		if(p==0) break;
		
		for(int q = 0;q<Q;++q){
			scanf("%d",&n);
			n %= p;
			
			if(n==1 && p==2) printf("YES\n");
			else if(n==0 || n==1) printf("NO\n");
			else{
				bool found = false;
				
				r = (int)floor(sqrt(p-1));
			
				for(int i = 2;i<=r && !found;++i){
					if((p-1)%i==0){
						ret = pow(n,i,p);
						if(ret==1) found = true;
						ret = pow(n,(p-1)/i,p);
						if(ret==1) found = true;
					}
				}
				
				printf("%s\n",found? "NO" : "YES");
			}
		}
	}
	
	return 0;
}
