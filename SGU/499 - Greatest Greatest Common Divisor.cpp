#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_N 1000000
#define SQRT_N 1000

int factor[MAX_N+1],cont[MAX_N+1];
int ans,p[78498],exp[78498],n_primes;

void generate_divisors(int n = 0, int div = 1){
    if(n==n_primes){
        ++cont[div];
        if(cont[div]==2 && div>ans) ans = div;
        return;
    }
    
    for(int i=0;i<=exp[n];++i){
        generate_divisors(n+1,div);
        div *= p[n];
    }
}

int main(){
    fill(factor,factor+MAX_N+1,0);
    factor[1] = 1;
    
    for(int i=2;i<=MAX_N;++i){
        if(factor[i]==0){
            factor[i] = i;
            if(i<=SQRT_N) for(int j=i*i;j<=MAX_N;j+=i) factor[j] = i;
        }
    }
    
    int n,x;
	scanf("%d",&n);
    
	memset(cont,0,sizeof(cont));
	ans = 1;
	
	for(int i=0;i<n;++i){
		scanf("%d",&x);
		n_primes = 0;
		
		while(x!=1){
		    int f = factor[x];
		    p[n_primes] = f;
		    exp[n_primes] = 0;
		    
		    while(x%f==0){
		        x /= f;
		        ++exp[n_primes];
		    }
		    
		    ++n_primes;
		}
		
		generate_divisors();
	}
	
	printf("%d\n",ans);
	
	return 0;
}
