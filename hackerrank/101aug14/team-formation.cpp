#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 100000

int a[MAXN],b[MAXN];
vector<int> have;

int solve(int l, int r){
    int n = 0;
    
    for(int i = l;i <= r;){
        int e = i;
        
        while(e <= r && a[e] == a[i]) ++e;
        
        b[n++] = e - i;
        i = e;
    }
    
    int ans = 100000,m = 0;
    
    for(int i = 0;i < n;++i){
        if(b[i] < m){
            for(int j = m - b[i];j >= 1;--j){
                ans = min(ans,have.back());
                have.pop_back();
            }
        }else{
            for(int j = b[i] - m;j >= 1;--j)
                have.push_back(0);
        }
        
        m = b[i];
        
        for(int j = m - 1;j >= 0;--j)
            ++have[j];
        
        sort(have.begin(),have.end());
    }
    
    if(!have.empty())
        ans = min(ans,have[0]);
    have.clear();
    
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    
    int T,n;
    
    cin >> T;
    
    while(T--){
        cin >> n;
        
        for(int i = 0;i < n;++i)
            cin >> a[i];
        
        sort(a,a + n);
        
        int ans = 100000;
        
        for(int i = 0;i < n;){
            int e = i + 1;
            
            while(e < n && a[e] - a[e - 1] <= 1) ++e;
            
            ans = min(ans,solve(i,e - 1));
            
            i = e;
        }
        
        if(n == 0) ans = 0;
        
        cout << ans << '\n';
    }
    
    return 0;
}
