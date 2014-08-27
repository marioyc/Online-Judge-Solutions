#include <cstdio>
#include <algorithm>

using namespace std;

#define MOD 1000000007

int calc2(int a[4], int n){
    sort(a,a + n);
    
    long long ret = 1;
    
    for(int i = 0;i < n;++i){
        if(a[i] <= i) return 0;
        ret = ret * (a[i] - i) % MOD;
    }
    
    return ret;
}

int calc1(int l[4], int r[4], int n){
    for(int i = 0;i < n;++i)
        if(l[i] > r[i])
            return 0;
    
    int a[n];
    long long ans = 0;
    
    for(int mask = 0;mask < (1 << n);++mask){
        for(int i = 0;i < n;++i){
            if(mask >> i & 1) a[i] = l[i] - 1;
            else a[i] = r[i];
        }
        
        if(__builtin_popcount(mask) & 1){
            ans -= calc2(a,n);
            if(ans < 0) ans += MOD;
        }else{
            ans += calc2(a,n);
            if(ans >= MOD) ans -= MOD;
        }
    }
    
    return ans;
}

int main(){
    int T,L[4],R[4],a[4],b[4];
    
    scanf("%d",&T);
    
    while(T--){
        
        for(int i = 0;i < 4;++i)
            scanf("%d %d",&L[i],&R[i]);
        
        long long ans = calc1(L,R,4);
        
        a[0] = max(L[0],L[2]); b[0] = min(R[0],R[2]);
        a[1] = L[1]; b[1] = R[1];
        a[2] = L[3]; b[2] = R[3];
        
        ans += calc1(a,b,3);
        if(ans >= MOD) ans -= MOD;
        
        a[1] = max(L[1],L[3]); b[1] = min(R[1],R[3]);
        
        ans += calc1(a,b,2);
        if(ans >= MOD) ans -= MOD;
        
        a[0] = L[0]; b[0] = R[0];
        a[1] = max(L[1],L[3]); b[1] = min(R[1],R[3]);
        a[2] = L[2]; b[2] = R[2];
        
        ans += calc1(a,b,3);
        if(ans >= MOD) ans -= MOD;
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
