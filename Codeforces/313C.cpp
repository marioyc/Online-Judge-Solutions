#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    
    int n4;
    cin >> n4;
    
    int a[n4];
    
    for(int i = 0;i < n4;++i) cin >> a[i];
    sort(a,a + n4);
    
    int n = 1;
    long long ans = 0;
    
    while(n <= n4){
        for(int i = 0;i < n;++i)
            ans += a[n4 - 1 - i];
        n *= 4;
    }
    
    cout << ans << '\n';
    
    return 0;
}
