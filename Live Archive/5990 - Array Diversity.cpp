#include <cstdio>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

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
    int T,N;
    int a[100000];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        for(int i = 0;i < N;++i)
            scanf("%d",&a[i]);
        
        int mn = a[0],mx = a[0];
        
        for(int i = 0;i < N;++i){
            mn = min(mn,a[i]);
            mx = max(mx,a[i]);
        }
        
        long long ans1 = (long long)(N + 1) * N % MOD;
        ans1 = ans1 * 500000004 % MOD;
        
        int pos_mn = -1,pos_mx = -1;
        
        for(int i = 0;i < N;++i){
            if(a[i] == mn) pos_mn = i;
            if(a[i] == mx) pos_mx = i;
            
            if(pos_mn == -1 || pos_mx == -1) ans1 -= i + 1;
            else ans1 -= i - min(pos_mn,pos_mx);
            
            if(ans1 < 0) ans1 += MOD;
        }
        
        long long ans2 = mod_pow(2,N) - 1;
        
        if(mn != mx){
            int cont_mn = 0,cont_mx = 0,diff = 0;
            
            for(int i = 0;i < N;++i){
                if(a[i] == mn) ++cont_mn;
                if(a[i] == mx) ++cont_mx;
                if(a[i] != mn && a[i] != mx) ++diff;
            }
            
            ans2 -= mod_pow(2,N - cont_mn) - 1;
            ans2 -= mod_pow(2,N - cont_mx) - 1;
            ans2 += mod_pow(2,N - cont_mn - cont_mx) - 1;
            ans2 %= MOD;
        }
        
        if(ans2 < 0) ans2 += MOD;
        
        printf("%lld %lld\n",ans1,ans2);
    }
    
    return 0;
}
