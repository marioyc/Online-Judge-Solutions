#include <cstdio>
#include <algorithm>

using namespace std;

#define B 31
#define MOD 1000000007

int main(){
    int L;
    scanf("%d",&L);
    
    char s[L + 1];
    scanf("%s",s);
    
    long long H1[L + 1];
    H1[L] = 0;
    
    for(int i = L - 1;i >= 0;--i)
        H1[i] = (s[i] - 'a' + B * H1[i + 1]) % MOD;
    
    long long H2[L + 1];
    H2[0] = 0;
    
    for(int i = 1;i <= L;++i)
        H2[i] = (s[i - 1] - 'a' + B * H2[i - 1]) % MOD;
    
    long long p[L + 1];
    p[0] = 1;
    
    for(int i = 1;i <= L;++i)
        p[i] = p[i - 1] * B % MOD;
    
    int ans = 0;
    
    for(int i = 0;i < L;++i){
        int lo = 0,hi = min(i,L - 1 - i),mi;
        
        while(lo < hi){
            mi = (lo + hi + 1) >> 1;
            
            int h1 = (H1[i - mi] - H1[i + 1] * p[mi + 1]) % MOD;
            if(h1 < 0) h1 += MOD;
            
            int h2 = (H2[i + mi + 1] - H2[i] * p[mi + 1]) % MOD;
            if(h2 < 0) h2 += MOD;
            
            if(h1 != h2) hi = mi - 1;
            else lo = mi;
        }
        
        ans = max(ans,2*lo + 1);
    }
    
    for(int i = 0;i + 1 < L;++i){
        if(s[i] == s[i + 1]){
            int lo = 0,hi = min(i,L - 2 - i),mi;
            
            while(lo < hi){
                mi = (lo + hi + 1) >> 1;
                
                int h1 = (H1[i - mi] - H1[i + 1] * p[mi + 1]) % MOD;
                if(h1 < 0) h1 += MOD;
                
                int h2 = (H2[i + 2 + mi] - H2[i + 1] * p[mi + 1]) % MOD;
                if(h2 < 0) h2 += MOD;
                
                if(h1 != h2) hi = mi - 1;
                else lo = mi;
            }
            
            ans = max(ans,2 * lo + 2);
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
