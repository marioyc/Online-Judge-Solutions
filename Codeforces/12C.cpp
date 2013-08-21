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
    
    int n,m;
    
    cin >> n >> m;
    
    int a[n];
    
    for(int i = 0;i < n;++i)
        cin >> a[i];
    sort(a,a + n);
    
    string b[m];
    
    for(int i = 0;i < m;++i)
        cin >> b[i];
    sort(b,b + m);
    
    int c[n];
    memset(c,0,sizeof c);
    
    for(int i = 0,j = 0;i < m;){
        int e = i;
        
        while(e < m && b[e] == b[i]) ++e;
        
        c[j++] = e - i;
        i = e;
    }
    
    sort(c,c + n);
    
    int mn = 0,mx = 0;
    
    for(int i = 0;i < n;++i){
        mx += a[i] * c[i];
        mn += a[i] * c[n - 1 - i];
    }
    
    cout << mn << " " << mx << '\n';
    
    return 0;
}
