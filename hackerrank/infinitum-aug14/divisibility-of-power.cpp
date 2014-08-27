#include <cstdio>
#include <climits>

using namespace std;

#define MAXN 200000

int N,Q;
long long A[MAXN],x;

bool check(int l, int r, int k){
    if(l > r) return k <= 1;
    
    int lg = 0;
    long long aux = 1;
    
    while(aux < k){
        if(aux <= LLONG_MAX / A[l])
            aux *= A[l];
        else
            aux = LLONG_MAX;
        ++lg;
    }
    
    return check(l + 1,r,lg);
}

long long mod_mult(long long a, long long b, long long c){
    a %= c;
    long long ret = 0;
    
    while(b){
        if(b & 1){
            ret += a;
            if(ret >= c) ret -= c;
        }
        
        a <<= 1;
        if(a >= c) a -= c;
        b >>= 1;
    }
    
    return ret;
}

int main(){
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i)
        scanf("%lld",&A[i]);
    
    scanf("%d",&Q);
    int l,r;
    
    while(Q--){
        scanf("%d %d %lld",&l,&r,&x);
        --l; --r;
        
        bool ok = true;
        
        if(A[l] != 0){
            if(r > l && A[l + 1] == 0){
                if(x > 1) ok = false;
            }else{
                int k = 0;
                long long aux = 1;
                
                while(k <= 53 && aux % x != 0){
                    aux = mod_mult(aux,A[l],x);
                    ++k;
                }
                
                if(k == 54) ok = false;
                else{
                    int len = 0;
                    
                    for(int i = l + 1;i <= r && A[i] > 1;++i)
                        ++len;
                    
                    if(l + len + 1 <= r && A[l + len + 1] == 0) --len;
                    if(len < 4 && !check(l + 1,l + len,k)) ok = false;
                }
            }
        }
        
        printf("%s\n",ok? "Yes" : "No");
    }
    
    return 0;
}
