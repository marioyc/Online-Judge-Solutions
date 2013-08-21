#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    
    int n,k;
    
    cin >> n >> k;
    
    int a[n];
    
    for(int i = 0;i < n;++i) cin >> a[i];
    sort(a,a + n);
    
    int ans = 0;
    
    while(true){
        int cont = count(a,a + n,k);
        if(cont == n) break;
        
        ++ans;
        
        for(int i = 0;i < n;){
            int e = i;
            while(e < n && a[e] == a[i]) ++e;
            if(a[e - 1] < k) ++a[e - 1];
            i = e;
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}
