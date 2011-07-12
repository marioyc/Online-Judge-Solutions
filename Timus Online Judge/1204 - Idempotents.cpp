#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long get_inverse(int x, int mod){
    int b = mod - 2;
    long long a = x,ret = 1;
    
    while(b > 0){
        if(b & 1) ret = (ret * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    
    return ret;
}

int main(){
    bool isPrime[31622];
    memset(isPrime,true,sizeof(isPrime));
    
    int p[3401],sz = 0;
    
    for(int i = 2;i < 31622;++i){
        if(isPrime[i]){
            p[sz++] = i;
            
            if(i <= 177)
                for(int j = i * i;j < 31622;j += i)
                    isPrime[j] = false;
        }
    }
    
    int T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        for(int i = 0;i < 3401;++i){
            if(N % p[i] == 0){
                long long inv1 = get_inverse(p[i],N / p[i]),inv2 = get_inverse(N / p[i],p[i]);
                long long r1 = p[i] * inv1, r2 = N / p[i] * inv2;
                
                printf("0 1 %lld %lld\n",min(r1,r2),max(r1,r2));
                break;
            }
        }
    }
    
    return 0;
}
