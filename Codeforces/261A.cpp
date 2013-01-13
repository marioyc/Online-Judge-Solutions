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

int q[100000],a[100000];

int main(){
    ios::sync_with_stdio(0);
    
    int n,m;
    
    cin >> n;
    
    for(int i = 0;i < n;++i)
        cin >> q[i];
    sort(q,q + n);
    
    cin >> m;
    
    for(int i = 0;i < m;++i)
        cin >> a[i];
    sort(a,a + m);
    
    int Q = q[0];
    int pos = m - 1;
    long long ans = 0;
    
    while(pos >= 0){
        int s = max(0,pos - Q + 1);
        //cout << s << " " << pos << endl;
        for(int i = s;i <= pos;++i) ans += a[i];
        pos = s - 3;
        //cout << pos << endl;
    }
    
    cout << ans << '\n';
    
    return 0;
}
