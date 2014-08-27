#include <cstdio>
#include <cstdlib>

using namespace std;

typedef unsigned long long ULL;

ULL mulmod(ULL a, ULL b, ULL c){
    ULL x = 0,y = a % c;
	
    while(b > 0){
        if(b & 1) x += y;
        y <<= 1;
        if(x >= c) x -= c;
        if(y >= c) y -= c;
        b >>= 1;
    }
	
    return x;
}

ULL pow(ULL a, ULL b, ULL c){
    ULL x = 1,y = a;
	
    while(b > 0){
        if(b & 1) x = mulmod(x,y,c);
        y = mulmod(y,y,c);
        b >>= 1;
    }
	
    return x;
}

bool miller_rabin(ULL p, int it){
    if(p < 2) return false;
    if(p == 2) return true;
    if((p & 1) == 0) return false;
	
    ULL s = p - 1;
    while(s % 2 == 0) s >>= 1;
	
    while(it--){
        ULL a = rand() % (p-1) + 1,temp = s;
        ULL mod = pow(a,temp,p);
		
        if(mod == -1 || mod == 1) continue;
		
        while(temp != p-1 && mod != p-1){
            mod = mulmod(mod,mod,p);
            temp <<= 1;
        }
		
        if(mod != p-1) return false;
    }
	
    return true;
}

bool check(long long n, long long k){
    if(k == 1) return miller_rabin(n,5);
    if(n % 2 == 0) return n >= 2 * k;
    return (k >= 3 && n >= 2 * k) || (k == 2 && miller_rabin(n - 2,5));
}

int main(){
    int T;
    long long N,K;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%lld %lld",&N,&K);
        
        printf("%s\n",check(N,K)? "Yes" : "No");
    }
    
    return 0;
}
