#include <cstdio>

using namespace std;

#define MOD 9973

int mod_pow(int a, int b){
    int ret = a;
    
    for(int i = 1;i < b;++i)
        ret = (ret * a) % MOD;
    
    return ret;
}

int main(){
    int a[MOD+1],b[MOD+1],c,d;
    a[0] = 1; b[0] = 0;
    
    for(int i = 1;i <= MOD;++i){
        c = (mod_pow(i,5) - i + 7) %  MOD;
        if(c < 0) c += MOD;
        d = (mod_pow(i,3) - mod_pow(i,5) + 3 * i) % MOD;
        if(d < 0) d += MOD;
        
        a[i] = c * a[i-1] % MOD;
        b[i] = (c * b[i-1] + d) % MOD;
    }
    
    int a2[28],b2[28];
    a2[0]= a[MOD]; b2[0] = b[MOD];
    
    for(int i = 1;i <= 27;++i){
        a2[i] = a2[i-1] * a2[i-1] % MOD;
        b2[i] = (a2[i-1] * b2[i-1] + b2[i-1]) % MOD;
    }
    
    int n,m = 0,A = 1,B = 0;
    
    scanf("%d",&n);
    
    int rem = n % MOD;
    n /= MOD;
    
    for(int i = 27;i >= 0;--i){
        if(n & (1<<i)){
            A = a2[i] * A % MOD;
            B = (a2[i] * B + b2[i]) % MOD;
        }
    }
    
    B = (a[rem] * B + b[rem]) % MOD;
    
    printf("%d\n",B);
    
    return 0;
}
