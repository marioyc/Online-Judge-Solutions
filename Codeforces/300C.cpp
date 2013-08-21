#include <cstdio>

using namespace std;

#define MOD 1000000007

int mod_pow(long long a, int b){
    long long ret = 1;
    
    while(b){
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    
    return ret;
}

int main(){
    int a,b,n;
    
    scanf("%d %d %d",&a,&b,&n);
    
    long long C = 1;
    int ans = 0;
    
    for(int i = 0;i <= n;++i){
        int sum = i * a + (n - i)* b;
        bool ok = true;
        
        while(sum){
            int d = sum % 10;
            sum /= 10;
            if(d != a && d != b) ok = false;
        }
        
        if(ok) ans = (ans + C) % MOD;
        C = C * (n - i) % MOD;
        C = C * mod_pow(i + 1,MOD - 2) % MOD;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
