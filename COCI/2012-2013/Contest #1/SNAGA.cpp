#include <cstdio>

using namespace std;

bool is_prime(int n){
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    
    for(int i = 3;i <= n / i;i += 2)
        if(n % i == 0) return false;
    
    return true;
}

int p[56],powp[56];

long long f(long long n){
    long long ret = 0;
    
    for(int i = 0;i < 56;++i)
        powp[i] = p[i];
    
    long long cur = 1;
    
    while(cur <= n){
        int mn = powp[0],ind = 0;
        
        for(int i = 1;i < 56;++i){
            if(powp[i] < mn){
                mn = powp[i];
                ind = i;
            }
        }
        
        long long nxt = cur * p[ind];
        
        ret += (n / cur - n / nxt) * (ind == 0? (powp[0] == 2? 2 : 4) : 3);
        
        powp[ind] *= p[ind];
        cur = nxt;
    }
    
    return ret;
}

int main(){
    int cont = 0;
    
    for(int i = 2;cont < 56;++i)
        if(is_prime(i)) p[cont++] = i;
    
    long long A,B;
    
    scanf("%lld %lld",&A,&B);
    
    printf("%lld\n",f(B) - f(A - 1));
    
    return 0;
}
