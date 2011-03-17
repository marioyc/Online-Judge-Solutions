#include <cstdio>
#include <cmath>

using namespace std;

long long pow(long long a, int b, int mod){
    long long ret = 1;
    
    while(b){
        if(b & 1) ret = (ret*a) % mod;
        a = (a*a) % mod;
        b >>= 1;
    }
    
    return ret;
}

int main(){
	int p,Q,n,r;
	long long ret;
	
	while(true){
		scanf("%d %d",&p,&Q);
		if(p == 0) break;
		
		for(int q = 0;q<Q;++q){
			scanf("%d",&n);
			n %= p;
			
			if(n == 1 && p == 2) printf("YES\n");
			else if(n == 0 || n == 1) printf("NO\n");
			else{
				bool found = false;
			    int aux = p-1;
			    
				for(int i = 2;i <= aux/i && !found;++i){
					if(aux % i == 0){
						ret = pow(n,(p-1)/i,p);
						if(ret == 1) found = true;
						
						while(aux % i == 0) aux /= i;
					}
				}
				
				if(!found && aux != 1){
				    ret = pow(n,(p-1)/aux,p);
				    if(ret == 1) found = true;
				}
				
				printf("%s\n",found? "NO" : "YES");
			}
		}
	}
	
	return 0;
}
