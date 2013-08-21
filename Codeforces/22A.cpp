#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    int a[n];
    for(int i = 0;i < n;++i) cin >> a[i];
    sort(a,a + n);
    int m = unique(a,a + n) - a;
    
    if(m == 1) cout << "NO\n";
    else cout << a[1] << '\n';
    
    return 0;
}
