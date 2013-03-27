#include <iostream>

using namespace std;

int main(){
    long long n,k;
    
    cin >> n >> k;
    --n; --k;
    
    if(k * (k + 1) / 2 < n) cout << -1 << '\n';
    else{
        int ans = 0;
        
        while(n){
            k = min(n,k);
            
            long long lo = 1,hi = k,mi;
            
            while(lo < hi){
                mi = (lo + hi) / 2;
                
                if(k * (k + 1) / 2 - (mi - 1) * mi / 2 > n) lo = mi + 1;
                else hi = mi;
            }
            
            ans += k - lo + 1;
            n -= k * (k + 1) / 2 - (lo - 1) * lo / 2;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
